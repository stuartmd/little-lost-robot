// SOWaterBridge_Straight.h: interface for the SOWaterBridge_Straight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWATERBRIDGE_STRAIGHT_H__45FD1A63_2D17_11D4_95D9_60AA51C19A15__INCLUDED_)
#define AFX_SOWATERBRIDGE_STRAIGHT_H__45FD1A63_2D17_11D4_95D9_60AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SOWater_Straight.h"

class SOWaterBridge_Straight : public SOWater_Straight  
{
public:
	void SetExtended(bool bState);
	virtual void InitAnimation();
	virtual void Draw();
	SOWaterBridge_Straight();
	virtual ~SOWaterBridge_Straight();

protected:
	bool m_bExtended;
};

#endif // !defined(AFX_SOWATERBRIDGE_STRAIGHT_H__45FD1A63_2D17_11D4_95D9_60AA51C19A15__INCLUDED_)
