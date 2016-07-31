// SOWall_L.h: interface for the SOWall_L class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWALL_L_H__5D02F961_299C_11D4_95D9_E07E51C10014__INCLUDED_)
#define AFX_SOWALL_L_H__5D02F961_299C_11D4_95D9_E07E51C10014__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SONormalSquare.h"

class SOWall_L : public SONormalSquare  
{
public:
	virtual void Draw();
	SOWall_L();
	virtual ~SOWall_L();

};

#endif // !defined(AFX_SOWALL_L_H__5D02F961_299C_11D4_95D9_E07E51C10014__INCLUDED_)
