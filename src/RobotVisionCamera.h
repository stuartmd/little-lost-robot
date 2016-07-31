// RobotVisionCamera.h: interface for the RobotVisionCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTVISIONCAMERA_H__A16994C0_2CDE_11D4_95D9_00104B7D9749__INCLUDED_)
#define AFX_ROBOTVISIONCAMERA_H__A16994C0_2CDE_11D4_95D9_00104B7D9749__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Camera.h"

class RobotVisionCamera : public Camera  
{
public:
	virtual void Update();
	RobotVisionCamera(Game* pGame);
	virtual ~RobotVisionCamera();

};

#endif // !defined(AFX_ROBOTVISIONCAMERA_H__A16994C0_2CDE_11D4_95D9_00104B7D9749__INCLUDED_)
