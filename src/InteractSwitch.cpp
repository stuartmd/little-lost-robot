// InteractSwitch.cpp: implementation of the InteractSwitch class.
//
//////////////////////////////////////////////////////////////////////

#include "InteractSwitch.h"

#include <GL/glut.h>
#include "threed_objects.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

InteractSwitch::InteractSwitch()
{
	m_bState=false;
	m_bMovable = false;
	m_bObstacle = true;
}

InteractSwitch::~InteractSwitch()
{

}

void InteractSwitch::Draw()
{
	glColor3f(0.3, 0.6, 0.2);
	globjCuboid(2.0, 2.0, 3.5);

	if (m_bState)
		glColor3f(0.6, 1.0, 0.6);
	else
		glColor3f(1.0, 0.6, 0.6);
	
	glTranslatef(0.0,0.0,3.5);
	globjCuboid(2.0, 2.0, 0.5);
}

bool InteractSwitch::Grabbed()
{
	m_bState = !m_bState;
	return false;
}

bool InteractSwitch::GetState()
{
	return m_bState;
}
