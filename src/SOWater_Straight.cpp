// SOWater_Straight.cpp: implementation of the SOWater_Straight class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWater_Straight.h"
#include <GL/glut.h>
#include "threed_objects.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWater_Straight::SOWater_Straight()
{
	m_bObstacle = true;
	m_bStatic = false;
}

SOWater_Straight::~SOWater_Straight()
{

}

void SOWater_Straight::Draw()
{
	glTranslatef(0, 0, -1.0);
	
	glPushMatrix();
		glColor4f(0.6, 0.6, 1.0, 0.2);
		globjBaselessCuboid(4.2, 5.0, 0.8);

		glColor3fv(m_color);
		glTranslatef(2.3, 0, 0.0);
		globjBaselessCuboid(0.4, 5.0, 1.0);
		
		glTranslatef(-4.7, 0, 0.0);
		globjBaselessCuboid(0.4, 5.0, 1.0);
	glPopMatrix();

	glTranslatef(0, 0, -3.0);
}
