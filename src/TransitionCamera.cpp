// TransitionCamera.cpp: implementation of the TransitionCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "TransitionCamera.h"
#include "Game.h"
#include "Level.h"

#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TransitionCamera::TransitionCamera(Game* pGame) : Camera(pGame)
{
	m_eProjMode = PROJ_PERSP;
	m_nAniStep = 0;
	m_nAniMAX = 20;
}

TransitionCamera::~TransitionCamera()
{

}

bool TransitionCamera::Draw()
{
	reshape();
	if(m_nAniStep==m_nAniMAX)
	{
		m_pEnd->reshape(m_width, m_height);
		m_pEnd->Draw();
		return false;
	}
	else
	{
		Camera::Draw();
		m_nAniStep++;
		return true;
	}
}

void TransitionCamera::Update()
{
	float	progPerc = (float) m_nAniStep / (float) m_nAniMAX;
	m_pEnd->Update();
	float oriDiff = m_pEnd->m_ori[1] - m_startOri[1];

	for (int i=0; i<3; i++)
	{	
		m_pos[i] = m_startPos[i] + ((m_pEnd->m_pos[i] - m_startPos[i]) * progPerc);
		m_ori[i] = m_startOri[i] + ((m_pEnd->m_ori[i] - m_startOri[i]) * progPerc);
	}

	m_ori[1] = m_startOri[1] + (
					
		((abs(oriDiff)<= 180) ? oriDiff : 180-oriDiff) * progPerc);
	/*
	m_pos[0] += (pEnd->m_pos[0] - m_pos[0]) * (1.0 - progPerc);
	m_pos[1] += (pEnd->m_pos[1] - m_pos[1]) * (1.0 - progPerc);
	m_pos[2] += (pEnd->m_pos[2] - m_pos[2]) * (1.0 - progPerc);

	m_ori[0] += (pEnd->m_ori[0] - m_ori[0]) * (1.0 - progPerc);
	m_ori[1] += (pEnd->m_ori[1] - m_ori[1]) * (1.0 - progPerc);
	m_ori[2] += (pEnd->m_ori[2] - m_ori[2]) * (1.0 - progPerc);
	*/
	m_FOV = m_startFOV + ((m_pEnd->m_FOV - m_startFOV) * progPerc);
}

bool TransitionCamera::SetCameras(Camera * pStart, Camera * pEnd)
{
	for(int i=0; i<3; i++)
	{
		m_startPos[i] = pStart->m_pos[i];
		m_startOri[i] = pStart->m_ori[i];
	}
	m_startFOV = pStart->m_FOV;
	m_nAniStep = 0;
	m_pEnd = pEnd;
	return true;
}
