// SimpleCrate.h: interface for the SimpleCrate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIMPLECRATE_H__11ECC221_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_SIMPLECRATE_H__11ECC221_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "RobotInteractObject.h"
#include "TextureManager.h"

extern class TextureManager* pTheTextureManager;
class SimpleCrate : public RobotInteractObject
{
public:
	static void DrawObject();
	bool Grabbed();
	SimpleCrate();
	virtual ~SimpleCrate();

	virtual void Draw();

};

#endif // !defined(AFX_SIMPLECRATE_H__11ECC221_2948_11D4_95D9_907E51C10700__INCLUDED_)
