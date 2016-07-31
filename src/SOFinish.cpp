// SOFinish.cpp: implementation of the SOFinish class.
//
//////////////////////////////////////////////////////////////////////

#include "SOFinish.h"
#include <GL/glut.h>
#include "threed_objects.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOFinish::SOFinish()
{
}

SOFinish::~SOFinish()
{
}

void SOFinish::Draw()
{
	glColor3f(1.0, 0.0, 0.0);
	globjRectangle(5.0, 5.0);	
	//globjCuboid(5.0, 5.0, 0.01);	
}
