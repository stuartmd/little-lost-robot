// SONormalSquare.cpp: implementation of the SONormalSquare class.
//
//////////////////////////////////////////////////////////////////////

#include "SONormalSquare.h"
#include <GL/glut.h>
#include "threed_objects.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SONormalSquare::SONormalSquare()
{
	m_color[0] = 1.0;
	m_color[1] = 1.0;
	m_color[2] = 1.0;
}

SONormalSquare::~SONormalSquare()
{

}

void SONormalSquare::Draw()
{
	glColor3fv(m_color);
	globjRectangle(5.0, 5.0);
}
