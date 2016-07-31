// Level2.h: interface for the Level2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEVEL2_H__B463D220_2A09_11D4_95D9_E0B151C1F816__INCLUDED_)
#define AFX_LEVEL2_H__B463D220_2A09_11D4_95D9_E0B151C1F816__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Level.h"


#include "InteractSwitch.h"
#include "SOWaterBridge_Straight.h"

class Level2 : public Level  
{
public:
	virtual void RobotGrabbed(RobotInteractObject* pObject);
	virtual bool ExtendArms();
	virtual bool RetractArms();
	Level2( Game* pGame );
	virtual ~Level2();

protected:
	InteractSwitch			*m_pSwitch;
	SOWaterBridge_Straight	*m_pBridge;
};

#endif // !defined(AFX_LEVEL2_H__B463D220_2A09_11D4_95D9_E0B151C1F816__INCLUDED_)
