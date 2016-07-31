// SONormalSquare.h: interface for the SONormalSquare class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SONormalSquare_H__11ECC227_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_SONormalSquare_H__11ECC227_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SceneObject.h"

class SONormalSquare : public SceneObject  
{
public:
	void Draw();
	SONormalSquare();
	virtual ~SONormalSquare();
};

#endif // !defined(AFX_SONormalSquare_H__11ECC227_2948_11D4_95D9_907E51C10700__INCLUDED_)
