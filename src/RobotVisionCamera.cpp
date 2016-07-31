// RobotVisionCamera.cpp: implementation of the RobotVisionCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "RobotVisionCamera.h"
#include "Level.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RobotVisionCamera::RobotVisionCamera(Game* pGame) : Camera(pGame)
{
	m_eProjMode = PROJ_PERSP;
	m_FOV = 90.0;
	m_Aspect = 1.0;
	m_ClipNear = 1.0;
	m_ClipFar = 200.0;
}

RobotVisionCamera::~RobotVisionCamera()
{

}

void RobotVisionCamera::Update()
{
	Level* pLevel = m_pGame->pCurrentLevel;

	m_ori[0] = 90;
	m_ori[1] = pLevel->GetRobotAngle();

	m_pos[0] = pLevel->GetRobotPosX();
	m_pos[1] = pLevel->GetRobotPosY();
	m_pos[2] = 4.0;
}
