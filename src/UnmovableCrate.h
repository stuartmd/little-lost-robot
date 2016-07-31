// UnmovableCrate.h: interface for the UnmovableCrate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNMOVABLECRATE_H__8169F2A2_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
#define AFX_UNMOVABLECRATE_H__8169F2A2_2A0E_11D4_95D9_100C53C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SimpleCrate.h"

class UnmovableCrate : public SimpleCrate  
{
public:
	virtual void Draw();
	virtual bool Grabbed();
	UnmovableCrate();
	virtual ~UnmovableCrate();

};

#endif // !defined(AFX_UNMOVABLECRATE_H__8169F2A2_2A0E_11D4_95D9_100C53C10000__INCLUDED_)
