// SOWater_L.cpp: implementation of the SOWater_L class.
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
