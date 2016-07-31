// InteractSwitch.h: interface for the InteractSwitch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERACTSWITCH_H__8169F2A1_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
#define AFX_INTERACTSWITCH_H__8169F2A1_2A0E_11D4_95D9_100C53C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "RobotInteractObject.h"

class InteractSwitch : public RobotInteractObject  
{
public:
	bool GetState();
	virtual bool Grabbed();
	virtual void Draw();
	InteractSwitch();
	virtual ~InteractSwitch();

protected:
	bool m_bState;
};

#endif // !defined(AFX_INTERACTSWITCH_H__8169F2A1_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
