// LookAtCamera.h: interface for the LookAtCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOOKATCAMERA_H__F62DDC00_2F40_11D4_95D9_00104B7D9749__INCLUDED_)
#define AFX_LOOKATCAMERA_H__F62DDC00_2F40_11D4_95D9_00104B7D9749__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Camera.h"

class LookAtCamera : public Camera  
{
public:
	virtual bool Draw();
	void SetMovingTargetPos(float* pNewPos);
	void SetStaticTargetPos(const float* newPos);
	void SetFuncTargetPos( float (*funcX)(), float (*funcY)(), float (*funcZ)());

	virtual void Update();
	LookAtCamera(Game* pGame);
	virtual ~LookAtCamera();

protected:
	float m_targetPos[3];

	union TargetData{

		struct {
			float pos[3];		
		} staticTarget;

		struct {
			float* pos[3];
		} movingTarget;
		
		struct {
			float (*pos[3])();
		} funcTarget;
	} targetData;

	enum eTargetType {	TARGET_STATIC, 
						TARGET_MOVING,
						TARGET_FUNC,
						TARGET_NULL} m_eTargetType;

};

#endif // !defined(AFX_LOOKATCAMERA_H__F62DDC00_2F40_11D4_95D9_00104B7D9749__INCLUDED_)
