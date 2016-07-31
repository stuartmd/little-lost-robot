// SOWall_End.cpp: implementation of the SOWall_End class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWall_End.h"
#include <GL/glut.h>
#include "threed_objects.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWall_End::SOWall_End()
{
	m_bObstacle = true;
	m_fHeight = 5.0;
}

SOWall_End::~SOWall_End()
{

}

void SOWall_End::Draw()
{
	SONormalSquare::Draw();

	glColor3f(0.6, 0.6, 0.1);

	glTranslatef(0.0, -0.75, 0.0);
	globjBaselessCuboid(2.0, 3.5, 5.0);
}
