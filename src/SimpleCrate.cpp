// SimpleCrate.cpp: implementation of the SimpleCrate class.
//
//////////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "threed_objects.h"
#include "SimpleCrate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SimpleCrate::SimpleCrate()
{
	m_bMovable = true;
}

SimpleCrate::~SimpleCrate()
{

}

void SimpleCrate::Draw()
{
	DrawObject();
}

bool SimpleCrate::Grabbed()
{
	return true;
}


void SimpleCrate::DrawObject()
{
	glColor3f(0.3,0.3,0.0);
	
	glEnable(GL_TEXTURE_2D);
	pTheTextureManager->SetCurrentTexture(100);
	
	globjTexCube(4.0, 0,0,1,1,2,1);
	
	pTheTextureManager->SetCurrentTexture(-1);
	glDisable(GL_TEXTURE_2D);
}
