// SOWall_Straight.h: interface for the SOWall_Straight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWALL_STRAIGHT_H__5D02F960_299C_11D4_95D9_E07E51C10014__INCLUDED_)
#define AFX_SOWALL_STRAIGHT_H__5D02F960_299C_11D4_95D9_E07E51C10014__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SONormalSquare.h"

class SOWall_Straight : public SONormalSquare  
{
public:
	virtual void Draw();
	SOWall_Straight();
	virtual ~SOWall_Straight();

};

#endif // !defined(AFX_SOWALL_STRAIGHT_H__5D02F960_299C_11D4_95D9_E07E51C10014__INCLUDED_)
