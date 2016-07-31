// AnimatedRobot.cpp: implementation of the AnimatedRobot class.
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

#include "AnimatedRobot.h"

#include <GL/glut.h>
#include "threed_objects.h"
#include "Game.h"
#include "Level.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AnimatedRobot::AnimatedRobot()
{
	bTorsoTurnLft = bTorsoTurnRgt = false;

	m_bExtendingArms = false;
	m_bRetractingArms = false;
	m_pGame = 0;
}

AnimatedRobot::AnimatedRobot(Game * pGame)
{
	bTorsoTurnLft = bTorsoTurnRgt = false;
 	m_bExtendingArms = false;
	m_bRetractingArms = false;

	m_pGame = pGame;
}

AnimatedRobot::~AnimatedRobot()
{

}

bool AnimatedRobot::DrawArm()
{
// Draws a 'left' arm
	float fShoulderSize = (m_bArmsExtended) ? 1.0 : 0.5;
	float fArmLength = (m_bArmsExtended) ? 4.0 : 0.0;

	bool bDrawArmExtensions = m_bExtendingArms || m_bRetractingArms;


	GLUquadricObj* pObj;
	pObj = gluNewQuadric();

	if(!m_bExtendingArms && !m_bRetractingArms)
		return Robot::DrawArm();


	if (m_bExtendingArms)
	{
		if (m_nExtendArmStep<10)
		{
			fShoulderSize = 0.5 * (float)m_nExtendArmStep;
			fShoulderSize /= 10.0f;
			fShoulderSize += 0.5;
			fArmLength = 0.0;
		}
		else if(m_nExtendArmStep<30)
		{
			fArmLength *= (float)m_nExtendArmStep-10.0f;
			fArmLength /= 20.0f;
			fShoulderSize = 1.0;
		}
	}
	else if (m_bRetractingArms)
	{
		fShoulderSize = 0.5;
		if (m_nExtendArmStep<25)
		{
			fShoulderSize = 1.0;
			fArmLength = 25.0 - m_nExtendArmStep;
			fArmLength /= 25.0;
			fArmLength *= 4.0;
		}
		else if(m_nExtendArmStep<50)
		{
			fShoulderSize *= 50.0 - m_nExtendArmStep;
			fShoulderSize /= 25.0;
			fShoulderSize += 0.5;
			fArmLength = 0.0;
		}
	}

	glColor3f(0.6,0.6,0.8);
	gluCylinder(pObj, 0.35, 0.35, fShoulderSize, 16, 1);
	

	glTranslatef(0.0,0.0,fShoulderSize);
	
	glPushMatrix();
		glTranslatef(-0.65, 0, 0);
		globjCuboid(2.1, 0.8, 0.25);
		
		glTranslatef(-0.75, 0.6, 0);
		globjCuboid(0.6, 0.4, 0.25);

		glTranslatef(0.0,fArmLength,0.0);
		
		glTranslatef(0.0, 0.5, 0);
		glColor3f(1.0,0.0,0.0);
		globjCuboid(0.6, 0.6, 0.25);
	glPopMatrix();

	if (bDrawArmExtensions)
	{
		glColor3f(1.0,0.7,0.3);
		glTranslatef(-1.5, 0.8, 0.125);
		glRotatef(-90,1,0,0);
		gluCylinder(pObj, 0.075, 0.075, fArmLength, 16, 1);
		glTranslatef(0.225, 0.0, 0.0);
		gluCylinder(pObj, 0.075, 0.075, fArmLength, 16, 1);
	}
	

	gluDeleteQuadric(pObj);

	if (m_bExtendingArms)
	{
		if (m_nExtendArmStep++>30)
		{
			m_bExtendingArms = false;
			if (m_pInteractingObject)
			{
				if (m_pInteractingObject->Grabbed() == false)
				{
					if(m_pGame)
					{
						if(m_pGame->pCurrentLevel)
							m_pGame->pCurrentLevel->RobotGrabbed(m_pInteractingObject);
					}
					RetractArms();
					m_pInteractingObject = 0;
				}
			}
			else
				RetractArms();

			return false;
		}
	}
	else if (m_bRetractingArms)
	{
		if (m_nExtendArmStep++>50)
		{
			m_bRetractingArms = false;
			return false;
		}
	}
	
	return true;
}

bool AnimatedRobot::ExtendArms()
{
	if (m_bArmsExtended)
		return false;

	m_bExtendingArms = true;
	m_nExtendArmStep = 0;
	m_bArmsExtended = true; 

	return true;
}

bool AnimatedRobot::RetractArms()
{
	if (m_bArmsExtended)
	{
		m_bRetractingArms = true;
		m_nExtendArmStep = 0;
		m_bArmsExtended = false;
		return true;
	}
	return false;
}

void AnimatedRobot::TurnLeft()
{
	m_nAnimStep = 0;
}

void AnimatedRobot::TurnRight()
{
	m_nAnimStep = 0;
}

void AnimatedRobot::DrawInteractObject()
{
	//if (!m_bExtendingArms)
		Robot::DrawInteractObject();
}

bool AnimatedRobot::IsAnimated()
{
	return (m_bExtendingArms || m_bRetractingArms ||
			m_bTorsoTurnLft || m_bTorsoTurnRgt );
}

void AnimatedRobot::SetGame(Game * pGame)
{
	m_pGame = pGame;
}
