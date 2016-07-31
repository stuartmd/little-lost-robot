

#include "TgaReader.h"
#include "Image.h"


#include <fstream>


Image* TgaReader::Load(const char* szFilename)
{
	return TgaReader::LoadFile(szFilename);
}


Image* TgaReader::LoadFile(const char* szFilename)
{
	TgaHeader	header;
	Image*		pImage = NULL;
	IMAGE_TYPE	type = IMAGE_NULL;
	int			rows, cols;
	ifstream	inStream(szFilename, ios::binary);

	int			maxval;
	bool		bMapped=false, bRleEncoded=false;

	unsigned char**	ColorMap;
	unsigned char*	pPixels;


	if (!TgaReader::ReadHeader(inStream, header))
		return false;


	switch( header.ImgType )
	{
	case TGA_Map:
	case TGA_RLEMap:
	case TGA_RLERGB:
	case TGA_RGB:
		if (header.PixelSize==32)
			type = IMAGE_RGBAUCHAR;
		else
			type = IMAGE_RGBUCHAR;
		break;

	/*
	case TGA_Mono:
	case TGA_RLEMono:
		break;
	*/

	default:
		return NULL;
	}


	if (header.ImgType == TGA_Map || header.ImgType == TGA_RLEMap)
	{
		if (header.CoMapType != 1)
			return NULL;
		
		switch (header.CoSize)
		{
		case 8:
		case 24:
		case 32:
			maxval=255;
			break;

		case 15:
		case 16:
			maxval = 31;
			break;
		
		default:
			return NULL;
		}
		bMapped = true;
	}
	else
	{
		switch(header.PixelSize)
		{
		case 8:
		case 24:
		case 32:
			maxval=255;
			break;

		case 15:
		case 16:
			maxval=31;
			break;

		default:
			return NULL;
		}
	}


	if (header.CoMapType !=0)
	{
		if (header.GetCoMapIndex() + header.GetCoMapLength() + 1)

		ColorMap = new unsigned char*[header.GetCoMapLength()];

		for (int i=0; i<header.GetCoMapLength(); i++)
		{
			switch(header.PixelSize)
			{
			case 8:
			case 24:
			case 15:
			case 16:
				ColorMap[i + header.GetCoMapIndex()] = new unsigned char[3];
				break;

			case 32:
				ColorMap[i + header.GetCoMapIndex()] = new unsigned char[4];
			}

			TgaReader::GetMapEntry(inStream, ColorMap[i], header.PixelSize);
		}
	}
	
	rows = header.GetHeight();
	cols = header.GetWidth();

	pImage = new Image(cols,rows,type);
	pPixels = (unsigned char*) pImage->GetImageDataPtr();
	

	for(int row=0; row<rows; row++)
	{
		for (int col=0; col<cols; col++)
		{
			switch( type )
			{
			case IMAGE_RGBUCHAR:
				TgaReader::GetPixel(inStream, &(pPixels[(row*cols*3) + (col*3)]), header.PixelSize, bRleEncoded, bMapped, header.GetCoMapIndex(), ColorMap);
				break;
			case IMAGE_RGBAUCHAR:
				TgaReader::GetPixel(inStream, &(pPixels[4*(row*cols + col)]), header.PixelSize, bRleEncoded, bMapped, header.GetCoMapIndex(), ColorMap);
				break;
			}
		}
	}


	return pImage;
}


bool TgaReader::ReadHeader(istream& inStream, TgaHeader& header)
{
	unsigned char buffer[18];
	unsigned int i = 0;

	inStream.read((char*) buffer, 18);

	header.IDLength		= buffer[0];
	header.CoMapType	= buffer[1];
	header.ImgType		= buffer[2];
	header.Index_lo		= buffer[3];
	header.Index_hi		= buffer[4];
	header.Length_lo	= buffer[5];
	header.Length_hi	= buffer[6];
	header.CoSize		= buffer[7];
	header.X_org_lo		= buffer[8];
	header.X_org_hi		= buffer[9];
	header.Y_org_lo		= buffer[10];
	header.Y_org_hi		= buffer[11];
	header.Width_lo		= buffer[12];
	header.Width_hi		= buffer[13];
	header.Height_lo	= buffer[14];
	header.Height_hi	= buffer[15];
	header.PixelSize	= buffer[16];

	header.AttBits		= buffer[17] & 0xf;
	header.Rsrvd		= (buffer[17] & 0x10) >> 4;
	header.OrgBit		= (buffer[17] & 0x20) >> 5;
	header.IntrLve		= (buffer[17] & 0xc0) >> 6;

	if (header.IDLength > 0)
	{
		header.ID = new char[header.IDLength + 1];
		inStream.read(header.ID, header.IDLength);
		header.ID[header.IDLength + 1] = '\0';
	}

	return true;
}


void	TgaReader::GetMapEntry(istream& inStream, unsigned char* pPixel, unsigned int size)
{
	unsigned char j,k;
	unsigned char r,g,b,a;
	switch( size )
	{
	case 8:
		r = g = b = inStream.get();
		break;

	case 15:
	case 16:
		j = inStream.get();
		k = inStream.get();
		r = ( k & 0x7c ) >> 2;
		g = ((k & 0x03) << 3) + ((j & 0xE0)>>5);
		b = j & 0x1F;
		break;

	case 24:
	case 32:
		b = inStream.get();
		g = inStream.get();
		r = inStream.get();
		if (size==32)
			a = inStream.get();
		break;

	default:
		return;
	}

	pPixel[0] = r;
	pPixel[1] = g;
	pPixel[2] = b;
	if (size==32)
		pPixel[3] = a;
}


void TgaReader::GetPixel(istream& inStream, unsigned char* pPixel, unsigned int size, bool rleEncoded, bool mapped, unsigned int mapIndex, unsigned char** pColorMap)
{
	unsigned char	Red, Grn, Blu, Alpha;
	unsigned char			j,k;
	static unsigned int		l;
	static int				RLE_count=0, RLE_flag=0;


	// Check if Run-Length-Encoded
	if (rleEncoded)
	{
		if (RLE_count == 0)
		{
			// Need to get next group
			unsigned char i;
			i = inStream.get();
			RLE_flag = (i &  0x80);

			if (RLE_flag == 0)
			{
				// Stream of unencoded pixels
				RLE_count = i+1;
			}
			else
			{
				// Single pixel replicated
				RLE_count = i - 127;
			}

			--RLE_count;
		}
		else
		{
			--RLE_count;
			if (RLE_flag != 0)
				goto PixEncode;
		}
	}

	switch( size )
	{
	case 8:
		Red = Grn = Blu = inStream.get();
		break;

	case 15:
	case 16:
		j = inStream.get();
		k = inStream.get();
		l = ((unsigned int) k <<8) + j;
		Red = ( k & 0x7c ) >> 2;
		Grn = ((k & 0x03) << 3) + ((j & 0xE0)>>5);
		Blu = j & 0x1F;
		break;

	case 24:
	case 32:
		Blu = inStream.get();
		Grn = inStream.get();
		Red = inStream.get();
		if (size==32)
			Alpha = inStream.get();
		break;

	default:
		return;
	}

PixEncode:
	if (mapped)
	{
		for(int i=0; i< ((size==32) ? 4:3); i++)
			pPixel[i] = pColorMap[l-mapIndex][i];
	}
	else
	{
		pPixel[0] = Red;
		pPixel[1] = Grn;
		pPixel[2] = Blu;
		if (size==32)
			pPixel[3] = Alpha;
	}
}