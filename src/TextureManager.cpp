// TextureManager.cpp: implementation of the TextureManager class.
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

#include "TextureManager.h"
#include "TexSupport/Image.h"
#include "TexSupport/TgaReader.h"


static GLuint texName = 0;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{

}

void*           TextureManager::cm_pInstance    = 0;
unsigned int    TextureManager::cm_iCount       = 0;
/*  operator new
    ============
    Overloaded to make TextureManager a
    SINGLETON object.  Every class which
    attempts to use TextureManager (using new)
    will refer to the same instance.

    This is not an ideal solution, but it solves a
    problem with calling glGenTextures() outside
    of main.cpp.

*/
void* TextureManager::operator new(size_t stAllocateBlock)
{
    void* pvTemp;

    if (cm_pInstance == 0)
        cm_pInstance = malloc(stAllocateBlock);

    cm_iCount++;

    return cm_pInstance;
}

void TextureManager::operator delete(void* pvMem)
{
    if (cm_pInstance) {
        if (--cm_iCount == 0) {
            free(pvMem);
            cm_pInstance = 0;
        }
    }
}


bool TextureManager::NewTexture(int nKey, const char* szFilename)
{
    //GLuint texName = 0;
    Image* pImage = TgaReader::LoadFile(szFilename);

    if (pImage) {
        glPixelStorei(GL_PACK_SKIP_ROWS, 0);
        glPixelStorei(GL_PACK_SKIP_PIXELS, 0);
        glPixelStorei(GL_PACK_ALIGNMENT, 1);

        glGenTextures(1, &texName);

        glBindTexture(GL_TEXTURE_2D, texName);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                     pImage->GetWidth(), pImage->GetHeight(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE,
                     pImage->GetImageDataPtr());
        delete pImage;

        m_mapElements.insert(mtex::value_type(nKey, texName));

        return true;
    } else
        return false;
}

bool TextureManager::SetCurrentTexture(int key)
{
    if (key < 0) {
        // Invalid element index
        // --> Indicates user wishes to select 'null texture'
        glBindTexture(GL_TEXTURE_2D, 0);
        return true;
    } else if (m_mapElements.count(key)) {
        glBindTexture(GL_TEXTURE_2D, (GLuint) m_mapElements[key]);
        return true;
    } else
        // The texture element requested does not exist (list too small)
        return false;

}
