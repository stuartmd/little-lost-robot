// InteractSwitch.cpp: implementation of the InteractSwitch class.
//
// MIT License
// 
// Copyright (c) [2016] [Stuart McDonald Dickson]
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
/////////////////////////////////////////////////////////////////////////////////

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
