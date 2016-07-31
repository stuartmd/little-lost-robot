// RobotInteractObject.h: interface for the RobotInteractObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTINTERACTOBJECT_H__11ECC220_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_ROBOTINTERACTOBJECT_H__11ECC220_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class RobotInteractObject  
{
public:
	bool IsMovable();
	virtual bool Grabbed();
	bool IsObstacle();
	virtual void Draw();


	RobotInteractObject();
	virtual ~RobotInteractObject();

protected:
	bool m_bMovable;
	bool m_bObstacle;
};

#endif // !defined(AFX_ROBOTINTERACTOBJECT_H__11ECC220_2948_11D4_95D9_907E51C10700__INCLUDED_)
