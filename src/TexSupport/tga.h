/*
	tga.h
	=====
	Header file for TARGA files

  Based upon tga.h, documented in
  "Programming for Graphics Files in C and C++"
  written by John Levine, 
  published by John Wiley & Sons Inc.
*/


/* Header Definition. */
#ifndef		_TGA_H
#define		_TGA_H


class TgaHeader
{
public:

	char* ID;

	unsigned char	IDLength;
								/* Length of Identifier string */
	unsigned char	CoMapType;	
								/* 0 = no map */
	unsigned char	ImgType;	
								/* Image type, see below for examples */
	unsigned char	Index_lo, Index_hi;
								/* Index of first color-map entry */
	unsigned char	Length_lo, Length_hi;
								/* Number of entries in color map */
	unsigned char	CoSize;
								/* Size of color map entry (15,16,24,32) */

	unsigned char	X_org_lo, X_org_hi;		/* x origin of image */
	unsigned char	Y_org_lo, Y_org_hi;		/* y origin of image */
	unsigned char	Width_lo, Width_hi;		/* width of image */
	unsigned char	Height_lo, Height_hi;	/* height of image */
	unsigned char	PixelSize;				/* pixel size (8,16,24,32) */
	unsigned char	AttBits;				/* 4 bits, number of attribute bits per pixel */
	unsigned char	LRbit;					/* 1 bit, origin: 0=left, 1=right */
	unsigned char	OrgBit;					/* 1 bit, origin: 0=lower left, 1=upper left */
	unsigned char	IntrLve;				/* 2 bits, interleaving flag */
	unsigned char	Rsrvd;


	unsigned int GetWidth() 
	{
		return ((int) Width_lo) + ((int) Width_hi) * 256;
	};

	unsigned int GetHeight() 
	{
		return ((int) Height_lo) + ((int) Height_hi) * 256;
	};

	unsigned int GetCoMapIndex() 
	{
		return ((int) Index_lo) + ((int) Index_hi) * 256;
	};

	unsigned int GetCoMapLength() 
	{
		return ((int) Length_lo) + ((int) Length_hi) * 256;
	};

};


/* Image-type Definitions. */
#define		TGA_Null		0
#define		TGA_Map			1
#define		TGA_RGB			2
#define		TGA_Mono		3
#define		TGA_RLEMap		9
#define		TGA_RLERGB		10
#define		TGA_RLEMono		11
#define		TGA_CompMap		32
#define		TGA_CompMap4	33


/* Definitions for Interleave flag. */
#define		TGA_IL_None		0
#define		TGA_IL_Two		1
#define		TGA_IL_Four		2


#endif