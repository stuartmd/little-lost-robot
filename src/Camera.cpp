// amera.cpp: implementation of the Camera class.
//
//////////////////////////////////////////////////////////////////////

#include "Camera.h"
#include "Game.h"
#include "Level.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Camera::Camera(Game* pGame) :	m_FOV(m_fvModeVars[0]), 
								m_Aspect(m_fvModeVars[1]),
								m_ClipNear(m_fvModeVars[4]),
								m_ClipFar(m_fvModeVars[5]),
								
								m_ClipLeft(m_fvModeVars[0]),
								m_ClipRight(m_fvModeVars[1]),
								m_ClipBottom(m_fvModeVars[2]),
								m_ClipTop(m_fvModeVars[3])
{
	m_pGame = pGame;

	m_eProjMode = PROJ_ORTHO;
	m_ClipLeft = -3.0;
	m_ClipRight = 3.0;
	m_ClipBottom = -3.0;
	m_ClipTop = 3.0;
	m_ClipNear = 1.0;
	m_ClipFar = -1.0;

	/*	Sample Perspective Mode initialisation
	m_eProjMode = PROJ_PERSP;
	m_FOV = 30.0;
	m_Aspect = 1.0;
	m_ClipNear = 1.0;
	m_ClipFar = 200.0;
	*/

	m_pos[0] = m_pos[1] = m_pos[2] = 0.0;
	m_ori[0] = m_ori[1] = m_ori[2] = 0.0;
}

Camera::~Camera()
{

}

bool Camera::Draw()
{
	Level * pLevel = m_pGame->pCurrentLevel;

	Update();

	
	glRotatef(-m_ori[0], 1, 0, 0);
	glRotatef(-m_ori[1], 0, 0, 1);
	glRotatef(-m_ori[2], 0, 1, 0);

	glTranslatef(-m_pos[0], -m_pos[1], -m_pos[2]);

	pLevel->Draw(); 

	return false;
}

void Camera::reshape(int w, int h)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	switch(m_eProjMode)
	{
	case PROJ_ORTHO:
		if (w<=h)
			glOrtho(	m_ClipLeft, 
						m_ClipRight,
						m_ClipBottom * (GLfloat)h/(GLfloat)w,
						m_ClipTop * (GLfloat)h/(GLfloat)w,
						m_ClipNear,
						m_ClipFar);
		else
			glOrtho(	m_ClipLeft * (GLfloat)w/(GLfloat)h, 
						m_ClipRight * (GLfloat)w/(GLfloat)h,
						m_ClipBottom,
						m_ClipTop,
						m_ClipNear,
						m_ClipFar);
		break;

	case PROJ_PERSP:
		m_Aspect = (GLfloat) w / (GLfloat) h;
		gluPerspective(	m_FOV, 
						m_Aspect,
						m_ClipNear,
						m_ClipFar);
		break;
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	m_width = w;
	m_height = h;
}

void Camera::reshape()
{
	reshape(m_width, m_height);
}

void Camera::Update()
{

}
