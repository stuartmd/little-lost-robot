// SOWaterBridge_Straight.cpp: implementation of the SOWaterBridge_Straight class.
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

#include "SOWaterBridge_Straight.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWaterBridge_Straight::SOWaterBridge_Straight()
{
	m_bObstacle = true;
	m_bExtended = false;
}

SOWaterBridge_Straight::~SOWaterBridge_Straight()
{

}

void SOWaterBridge_Straight::Draw()
{
	SOWater_Straight::Draw();

	glTranslatef(0.0, 0.0, 3.7);
	glColor3f(0.2,0.2,0.7);
	if (m_bAnimated)
	{
		float width;
		if (m_bExtended)
			width = 4.2 * m_nAniStep / m_nAniMAX;
		else
			width = 4.2 * (m_nAniMAX-m_nAniStep) / m_nAniMAX;

		glPushMatrix();
			glTranslatef(-2.1 + width/2, 0.0, 0.0 );
			globjBaselessCuboid(width, 3.5, 0.3);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(2.1 - width/2, 0.0, 0.0 );
			globjBaselessCuboid(width, 3.5, 0.3);
		glPopMatrix();
		
		if (m_nAniStep++ == m_nAniMAX)
		{
			m_bAnimated = false;
			m_bObstacle = !m_bExtended;
		}
	}
	else if (m_bExtended)
	{
		globjBaselessCuboid(4.2, 3.5, 0.3);
		glTranslatef(0.0, 0.0, 0.3);
	}

	glTranslatef(0.0, 0.0, 0.3);
}

void SOWaterBridge_Straight::InitAnimation()
{
	m_bAnimated = true;
	m_bObstacle = true;
	m_nAniStep = 0;
	m_nAniMAX = 30;
}

void SOWaterBridge_Straight::SetExtended(bool bState)
{
	m_bExtended = bState;
	InitAnimation();
}
