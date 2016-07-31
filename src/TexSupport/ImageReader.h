/*
	ImageReader.h
	=============

  Defines the ImageReader Class.\

*/

class Image;


class ImageReader
{
public:
	static Image* Load(const char* szFilename);
};