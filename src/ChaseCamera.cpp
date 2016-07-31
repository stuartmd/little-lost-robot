// haseCamera.cpp: implementation of the ChaseCamera class.
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

#include "ChaseCamera.h"
#include "Level.h"

#include <math.h>

const float DEG2RADS = 0.0174533;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ChaseCamera::ChaseCamera(Game* pGame) : Camera(pGame)
{
	m_eProjMode = PROJ_PERSP;
	m_FOV = 60.0;
	m_Aspect = 1.0;
	m_ClipNear = 1.0;
	m_ClipFar = 200.0;
	
	m_ori[0] = 30.0;
}

ChaseCamera::~ChaseCamera()
{

}

/*
bool
{
	Level* pLevel = m_pGame->pCurrentLevel;
	
	if (pLevel)
	{
		glRotatef(-20.0, 1, 0, 0);
		glTranslatef(-pLevel->GetRobotPosX(), 5.0-pLevel->GetRobotPosY(), -15.0);
		pLevel->Draw();
	}

	return true;
}
*/
void ChaseCamera::Update()
{
	Level* pLevel = m_pGame->pCurrentLevel;

	m_ori[1] = pLevel->GetRobotAngle();

	m_pos[0] = pLevel->GetRobotPosX() + 5.0*sin( m_ori[1] * DEG2RADS );
	m_pos[1] = pLevel->GetRobotPosY() - 5.0*cos( m_ori[1] * DEG2RADS );
	m_pos[2] = 10.0;

	
}
/*
bool ChaseCamera::Draw()
{
	Level * pLevel = m_pGame->pCurrentLevel;

	Update();
		
	glTranslatef(0.0,5.0,0.0);
	glRotatef(m_ori[0], 1, 0, 0);
	glRotatef(-pLevel->GetRobotAngle(), 0, 0, 1);
	glTranslatef(-m_pos[0], -m_pos[1], -m_pos[2]);
	//glTranslatef(-pLevel->GetRobotPosX(), -pLevel->GetRobotPosY(), -m_pos[2]);
	
	pLevel->Draw(); 

	return false;
}
*/