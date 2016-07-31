// SOWall_Straight.cpp: implementation of the SOWall_Straight class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWall_Straight.h"
#include <GL/glut.h>
#include "threed_objects.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWall_Straight::SOWall_Straight()
{
	m_bObstacle = true;
	m_fHeight = 5.0;
}

SOWall_Straight::~SOWall_Straight()
{

}

void SOWall_Straight::Draw()
{
	SONormalSquare::Draw();

	glColor3f(0.6, 0.6, 0.1);
	globjBaselessCuboid(2.0, 5.0, 5.0);
}
