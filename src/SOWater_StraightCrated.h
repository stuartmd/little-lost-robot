// SOWater_StraightCrated.h: interface for the SOWater_StraightCrated class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOWATER_STRAIGHTCRATED_H__45FD1A61_2D17_11D4_95D9_60AA51C19A15__INCLUDED_)
#define AFX_SOWATER_STRAIGHTCRATED_H__45FD1A61_2D17_11D4_95D9_60AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SOWater_Straight.h"

class SOWater_StraightCrated : public SOWater_Straight  
{
public:
	virtual void InitAnimation();
	virtual void Draw();
	SOWater_StraightCrated();
	virtual ~SOWater_StraightCrated();

protected:
	float	m_nAniStep;
	bool	m_bAniInit;
};

#endif // !defined(AFX_SOWATER_STRAIGHTCRATED_H__45FD1A61_2D17_11D4_95D9_60AA51C19A15__INCLUDED_)
