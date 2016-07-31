// Image.cpp: implementation of the Image class.
//
//////////////////////////////////////////////////////////////////////

//#include "stdafx.h"
//#include "PlanetViewer.h"
#include "Image.h"

#define NULL 0

/*
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
*/

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Image::Image()   :	m_pImageData(0), 
					m_imageType(IMAGE_NULL),
					m_xSize(0), 
					m_ySize(0)
{	
}


Image::Image(int x_size, int y_size, IMAGE_TYPE type) 
		 :	m_imageType(type),
			m_xSize(x_size), 
			m_ySize(y_size)
{
	
	switch( type )
	{
	case IMAGE_NULL:
		m_pImageData = NULL;
		m_xSize = m_ySize = 0;
		break;

	case IMAGE_INT:
		m_pImageData = (void*) new int[x_size * y_size];
		break;

	case IMAGE_FLOAT:
		m_pImageData = (void*) new float[x_size * y_size];
		break;

	case IMAGE_BGRUCHAR:
	case IMAGE_RGBUCHAR:
		m_pImageData = (void*) new unsigned char[x_size * y_size * 3];
		break;

	//case IMAGE_BGRAUCHAR:
	case IMAGE_RGBAUCHAR:
		m_pImageData = (void*) new unsigned char[x_size * y_size * 4];
		break;
	}
}

Image::~Image()
{
	if (m_pImageData != NULL) {
	    switch( m_imageType )
	    {
	    case IMAGE_INT:
		delete [] (int*) m_pImageData;
		break;

	    case IMAGE_FLOAT:
		delete [] (float*) m_pImageData;
		break;

	    case IMAGE_BGRUCHAR:
	    case IMAGE_RGBUCHAR:
	    case IMAGE_RGBAUCHAR:
		delete [] (unsigned char*) m_pImageData;
		break;
	    }
	}
		
}

void*	Image::GetImageDataPtr() const
{
	return (void*) m_pImageData;
}