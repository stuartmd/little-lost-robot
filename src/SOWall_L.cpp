// SOWall_L.cpp: implementation of the SOWall_L class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWall_L.h"
#include <GL/glut.h>
#include "threed_objects.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWall_L::SOWall_L()
{
	m_bObstacle = true;
	m_fHeight = 5.0;
}

SOWall_L::~SOWall_L()
{
	m_bObstacle = true;
}

void SOWall_L::Draw()
{
	SONormalSquare::Draw();


	glColor3f(0.6, 0.6, 0.1);

	glTranslatef(0.0, 0.75, 0.0);
	globjBaselessCuboid(2.0, 3.5, 5.0);

	glTranslatef(1.75, -0.75, 0.0);
	globjBaselessCuboid(1.5, 2.0, 5.0);
}
