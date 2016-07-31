// SOWall_End.h: interface for the SOWall_End class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWALL_END_H__3FF1F900_29BC_11D4_95D9_B0B151C1F816__INCLUDED_)
#define AFX_SOWALL_END_H__3FF1F900_29BC_11D4_95D9_B0B151C1F816__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SONormalSquare.h"

class SOWall_End : public SONormalSquare  
{
public:
	virtual void Draw();
	SOWall_End();
	virtual ~SOWall_End();

};

#endif // !defined(AFX_SOWALL_END_H__3FF1F900_29BC_11D4_95D9_B0B151C1F816__INCLUDED_)
