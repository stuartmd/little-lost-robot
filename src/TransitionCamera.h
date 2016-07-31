// TransitionCamera.h: interface for the TransitionCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSITIONCAMERA_H__F62DDC03_2F40_11D4_95D9_00104B7D9749__INCLUDED_)
#define AFX_TRANSITIONCAMERA_H__F62DDC03_2F40_11D4_95D9_00104B7D9749__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Camera.h"

class TransitionCamera : public Camera  
{
public:
	bool SetCameras(Camera* pStart, Camera* pEnd);
	virtual void Update();
	virtual bool Draw();
	TransitionCamera(Game* pGame);
	virtual ~TransitionCamera();

protected:
	int m_nAniStep;
	int m_nAniMAX;
	Camera *m_pEnd;

	float m_startFOV;
	float m_startPos[3];
	float m_startOri[3];
};

#endif // !defined(AFX_TRANSITIONCAMERA_H__F62DDC03_2F40_11D4_95D9_00104B7D9749__INCLUDED_)
