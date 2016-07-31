/*
	TgaReader.h
	=============

	Defines the TgaReader Class.\

*/


#ifndef	_TGAREADER_H
#define	_TGAREADER_H

#include "ImageReader.h"
#include "tga.h"
#include <iostream>
using namespace std;


#ifdef	MSDOS
	const unsigned int MAXCOLORS = 256;
#else
	const unsigned int MAXCOLORS = 16384;
#endif


class Image;


class TgaReader : ImageReader
{
public:
	virtual Image* Load(const char* szFilename);
	static Image* LoadFile(const char* szFilename);


private:
	static bool ReadHeader(istream& inStream, TgaHeader& header);
	static void	GetMapEntry(istream& inStream, unsigned char* pPixel, unsigned int size);
	static void GetPixel(istream& inStream, unsigned char* pPixel, unsigned int size, bool rleEncoded, bool mapped, unsigned int mapIndex, unsigned char** pColorMap);
};


#endif