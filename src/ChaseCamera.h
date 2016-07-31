// haseCamera.h: interface for the ChaseCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HASECAMERA_H__600CE4C2_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
#define AFX_HASECAMERA_H__600CE4C2_29EE_11D4_95D9_30AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Camera.h"


class ChaseCamera : public Camera 
{
public:
	//virtual bool Draw();
	virtual void Update();
	//virtual bool Draw();
	ChaseCamera(Game* pGame);
	virtual ~ChaseCamera();

};

#endif // !defined(AFX_HASECAMERA_H__600CE4C2_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
