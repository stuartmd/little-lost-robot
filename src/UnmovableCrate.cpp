// UnmovableCrate.cpp: implementation of the UnmovableCrate class.
//
//////////////////////////////////////////////////////////////////////

#include "UnmovableCrate.h"
#include <GL/glut.h>
#include "threed_objects.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UnmovableCrate::UnmovableCrate()
{
	m_bMovable = false;
}

UnmovableCrate::~UnmovableCrate()
{

}

bool UnmovableCrate::Grabbed()
{
	return false;
}

void UnmovableCrate::Draw()
{
	glEnable(GL_TEXTURE_2D);
	pTheTextureManager->SetCurrentTexture(110);
	
	globjTexCube(4.0, 0,0,0,0,0,0);
	
	pTheTextureManager->SetCurrentTexture(-1);
	glDisable(GL_TEXTURE_2D);
}
