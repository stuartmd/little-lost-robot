// OverviewCamera.h: interface for the OverviewCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OVERVIEWCAMERA_H__600CE4C1_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
#define AFX_OVERVIEWCAMERA_H__600CE4C1_29EE_11D4_95D9_30AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Camera.h"

const float	DEG2RAD = 0.0174533;

class Level;

class OverviewCamera : public Camera  
{
public:
	virtual void Update();
	Level* m_pLastLevel;
	//virtual bool Draw();
	OverviewCamera(Game* pGame);
	virtual ~OverviewCamera();

protected:
};

#endif // !defined(AFX_OVERVIEWCAMERA_H__600CE4C1_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
