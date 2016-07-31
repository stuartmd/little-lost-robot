// SOStart.h: interface for the SOStart class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOSTART_H__11ECC228_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_SOSTART_H__11ECC228_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SceneObject.h"

class SOStart : public SceneObject  
{
public:
	virtual void Draw();
	SOStart();
	virtual ~SOStart();

};

#endif // !defined(AFX_SOSTART_H__11ECC228_2948_11D4_95D9_907E51C10700__INCLUDED_)
