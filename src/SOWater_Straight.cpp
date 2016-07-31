// SOWater_Straight.cpp: implementation of the SOWater_Straight class.
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
