// TextureManager.h: interface for the TextureManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTUREMANAGER_H__376E4FA0_2D8A_11D4_95D9_C0AB52C10107__INCLUDED_)
#define AFX_TEXTUREMANAGER_H__376E4FA0_2D8A_11D4_95D9_C0AB52C10107__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL/glut.h>
#include <map>
using namespace std;


typedef map< int, GLuint, less<int> > mtex;

class TextureManager  
{
public:
	static void* operator new(size_t stAllocateBlock);
	static void operator delete( void * pvMem);

protected:
	static void* cm_pInstance;
	static unsigned int cm_iCount;

public:
	bool SetCurrentTexture(int key);
	bool NewTexture(int nKey, const char* szFilename);
	TextureManager();
	virtual ~TextureManager();

protected:
	mtex	m_mapElements;

};

#endif // !defined(AFX_TEXTUREMANAGER_H__376E4FA0_2D8A_11D4_95D9_C0AB52C10107__INCLUDED_)
