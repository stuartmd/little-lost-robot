// TextureManager.h: interface for the TextureManager class.
//
// MIT License
// 
// Copyright (c) [2016] [Stuart McDonald Dickson]
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
/////////////////////////////////////////////////////////////////////////////////

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
