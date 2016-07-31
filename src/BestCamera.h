// BestCamera.h: interface for the BestCamera class.
//
//////////////////////////////////////////////////////////////////////

/*
	

*/
#if !defined(AFX_BESTCAMERA_H__600CE4C3_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
#define AFX_BESTCAMERA_H__600CE4C3_29EE_11D4_95D9_30AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Camera.h"

class BestCamera : public Camera  
{
public:
	BestCamera(Game* pGame);
	virtual ~BestCamera();

};

#endif // !defined(AFX_BESTCAMERA_H__600CE4C3_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
