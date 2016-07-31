/*
	TgaReader.h
	=============

	Defines the TgaReader Class.

*/


#ifndef	_TGAREADER_H
#define	_TGAREADER_H

#include "ImageReader.h"
#include <iostream>

class Image;


class TgaReader : ImageReader
{
public:
	virtual Image* Load(const char* szFilename);
	static Image* LoadFile(const char* szFilename);
};


#endif