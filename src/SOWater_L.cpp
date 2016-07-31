// SOWater_L.cpp: implementation of the SOWater_L class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWater_L.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWater_L::SOWater_L()
{
	m_bObstacle = true;
}

SOWater_L::~SOWater_L()
{

}

void SOWater_L::Draw()
{
	glTranslatef(0, 0, -1.0);
	
	glPushMatrix();
		glTranslatef(0.2, 0.2, 0.0);
		glColor4f(0.6, 0.6, 1.0, 0.2);
		globjBaselessCuboid(4.6, 4.6, 0.8);

		glColor3fv(m_color);
		glTranslatef(2.1, 2.1, 0.0);
		globjBaselessCuboid(0.4, 0.4, 1.0);
		glTranslatef(-2.1, -2.1, 0.0);
		glTranslatef(-2.5, -0.2, 0.0);
		globjBaselessCuboid(0.4, 5.0, 1.0);
		
		glTranslatef(2.5, -2.3, 0.0);
		globjBaselessCuboid(4.6, 0.4, 1.0);
	glPopMatrix();

	glTranslatef(0, 0, -3.0);
}
