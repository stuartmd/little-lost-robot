// SOWall_T.cpp: implementation of the SOWall_T class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWall_T.h"
#include <GL/glut.h>
#include "threed_objects.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWall_T::SOWall_T()
{
	m_bObstacle = true;
	m_fHeight = 5.0;
}

SOWall_T::~SOWall_T()
{

}

void SOWall_T::Draw()
{
	SONormalSquare::Draw();

	glColor3f(0.6, 0.6, 0.1);
	globjBaselessCuboid(5.0, 2.0, 5.0);
	glTranslatef(0.0, -1.75, 0.0);
	globjBaselessCuboid(2.0, 1.5, 5.0);
}
