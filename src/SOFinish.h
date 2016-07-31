// SOFinish.h: interface for the SOFinish class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOFINISH_H__11ECC229_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_SOFINISH_H__11ECC229_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SceneObject.h"

class SOFinish : public SceneObject  
{
public:
	virtual void Draw();
	SOFinish();
	virtual ~SOFinish();

};

#endif // !defined(AFX_SOFINISH_H__11ECC229_2948_11D4_95D9_907E51C10700__INCLUDED_)
