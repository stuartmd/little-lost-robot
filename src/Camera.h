// amera.h: interface for the Camera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMERA_H__600CE4C0_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
#define AFX_AMERA_H__600CE4C0_29EE_11D4_95D9_30AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL/glut.h>

class Game;
class TransitionCamera;
enum	eProjMode{PROJ_ORTHO, PROJ_PERSP};

class Camera  
{
	friend class TransitionCamera;

public:
	virtual void Update();
	virtual void reshape();
	virtual void reshape(int w, int h);
	virtual bool Draw();
	Camera(Game* pGame);
	virtual ~Camera();

protected:
	float m_ori[3];
	float m_pos[3];
	int m_width;
	int m_height;

	Game*	m_pGame;

	eProjMode m_eProjMode;
	float	m_fvModeVars[6];

	// Orthographic Projection Vars
	float&	m_ClipLeft;
	float&	m_ClipRight;
	float&	m_ClipBottom;
	float&	m_ClipTop;

	// Perspective Projection Vars
	float&	m_FOV;
	float&	m_Aspect;
	float&  m_ClipNear;
	float&	m_ClipFar;
};

#endif // !defined(AFX_AMERA_H__600CE4C0_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
