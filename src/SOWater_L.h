// SOWater_L.h: interface for the SOWater_L class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWATER_L_H__8169F2A3_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
#define AFX_SOWATER_L_H__8169F2A3_2A0E_11D4_95D9_100C53C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SONormalSquare.h"

class SOWater_L : public SONormalSquare  
{
public:
	virtual void Draw();
	SOWater_L();
	virtual ~SOWater_L();

};

#endif // !defined(AFX_SOWATER_L_H__8169F2A3_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
