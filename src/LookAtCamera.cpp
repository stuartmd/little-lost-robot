// LookAtCamera.cpp: implementation of the LookAtCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "LookAtCamera.h"
#include "Game.h"
#include "Level.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LookAtCamera::LookAtCamera(Game* pGame) : Camera(pGame)
{
	m_eTargetType = TARGET_NULL;
}

LookAtCamera::~LookAtCamera()
{

}

void LookAtCamera::Update()
{
	int i;
	switch(m_eTargetType)
	{
	case TARGET_MOVING:
		for (i=0; i<3; i++)
			m_targetPos[i] = *(targetData.movingTarget.pos[i]);
		break;

	case TARGET_STATIC:
		for (i=0; i<3; i++)
			m_targetPos[i] = *(targetData.movingTarget.pos[i]);
		break;
	}
}

void LookAtCamera::SetStaticTargetPos(const float * newPos)
{
	m_eTargetType = TARGET_STATIC;

	for (int i=0; i<3; i++)
		m_targetPos[i] = targetData.staticTarget.pos[i] = newPos[i];
}

void LookAtCamera::SetMovingTargetPos(float * pNewPos)
{
	m_eTargetType = TARGET_MOVING;

	for (int i=0; i<3; i++)
		targetData.movingTarget.pos[i] = &pNewPos[i];
}

void LookAtCamera::SetFuncTargetPos(float ( * funcX ) ( ), float ( * funcY ) ( ), float ( * funcZ ) ( ))
{
	m_eTargetType = TARGET_FUNC;
	targetData.funcTarget.pos[0] = funcX;
	targetData.funcTarget.pos[1] = funcY;
	targetData.funcTarget.pos[2] = funcZ;
}

bool LookAtCamera::Draw()
{
	Level*	pLevel = m_pGame->pCurrentLevel;

	Update();
	gluLookAt(	m_pos[0],m_pos[1],m_pos[2], 
				m_targetPos[0],m_targetPos[1],m_targetPos[2],
				0,0,1);
				
	pLevel->Draw();
	return false;
}
