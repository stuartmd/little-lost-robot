// haseCamera.cpp: implementation of the ChaseCamera class.
//
//////////////////////////////////////////////////////////////////////

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