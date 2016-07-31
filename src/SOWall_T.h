// SOWall_T.h: interface for the SOWall_T class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWALL_T_H__5D02F962_299C_11D4_95D9_E07E51C10014__INCLUDED_)
#define AFX_SOWALL_T_H__5D02F962_299C_11D4_95D9_E07E51C10014__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SONormalSquare.h"

class SOWall_T : public SONormalSquare  
{
public:
	virtual void Draw();
	SOWall_T();
	virtual ~SOWall_T();

};

#endif // !defined(AFX_SOWALL_T_H__5D02F962_299C_11D4_95D9_E07E51C10014__INCLUDED_)
