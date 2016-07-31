// OverviewCamera.cpp: implementation of the OverviewCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "Game.h"
#include "Level.h"
#include "OverviewCamera.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OverviewCamera::OverviewCamera(Game* pGame) : Camera(pGame)
{
	
	m_eProjMode = PROJ_PERSP;
	m_FOV = 30.0; 
	m_ClipNear = 1.0;
	m_ClipFar = 200.0;
}

OverviewCamera::~OverviewCamera()
{

}
/*
bool OverviewCamera::Draw()
{
	
	Level * pLevel = m_pGame->pCurrentLevel;
	
	Update();
	glTranslatef(-m_pos[0], -m_pos[1], -m_pos[2]);
	pLevel->Draw(); 

	return true;
}
*/
void OverviewCamera::Update()
{
	Level * pLevel = m_pGame->pCurrentLevel;
		
	if (pLevel != m_pLastLevel)
	{
		m_pLastLevel = pLevel;
		m_pos[0] = -2.5+ 0.5 * pLevel->GetWidth();
		m_pos[1] = -2.5+ 0.5 * pLevel->GetDepth();
		m_pos[2] = 0.5 * pLevel->GetWidth() / tan(m_FOV * DEG2RAD / 2);
	}
}
