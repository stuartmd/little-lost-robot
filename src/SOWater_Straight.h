// SOWater_Straight.h: interface for the SOWater_Straight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWATER_STRAIGHT_H__8169F2A0_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
#define AFX_SOWATER_STRAIGHT_H__8169F2A0_2A0E_11D4_95D9_100C53C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SONormalSquare.h"

class SOWater_Straight : public SONormalSquare  
{
public:
	virtual void Draw();
	SOWater_Straight();
	virtual ~SOWater_Straight();

};

#endif // !defined(AFX_SOWATER_STRAIGHT_H__8169F2A0_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
