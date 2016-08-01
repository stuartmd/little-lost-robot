// Image.h: interface for the Image class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE_H__9F98F076_C9AA_11D3_BD7E_50C053C1F800__INCLUDED_)
#define AFX_IMAGE_H__9F98F076_C9AA_11D3_BD7E_50C053C1F800__INCLUDED_

/*
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
*/

typedef enum IMAGE_ENUM{IMAGE_NULL, IMAGE_INT, IMAGE_FLOAT, IMAGE_BGRUCHAR, IMAGE_RGBUCHAR, IMAGE_ABGRUCHAR} IMAGE_TYPE;


class Image
{
public:
	Image();
	virtual ~Image();
	Image(int x_size, int y_size, IMAGE_TYPE type) ;
	/*
	GetPixelf(int x, int y);
	GetPixeli(int x, int y);
	GetPixel3f(int x, int y);
	GetPixel3i(int x, int y);
	*/

	inline IMAGE_TYPE GetImageType() const { return m_imageType; }
	inline int GetWidth() const { return m_xSize; }
	inline int GetHeight() const { return m_ySize; }
	void*	GetImageDataPtr() const;


protected:
	void*		m_pImageData;
	int			m_xSize;
	int			m_ySize;
	IMAGE_TYPE	m_imageType;
};

#endif // !defined(AFX_IMAGE_H__9F98F076_C9AA_11D3_BD7E_50C053C1F800__INCLUDED_)
