// SceneObject.h: interface for the SceneObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENEOBJECT_H__11ECC224_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_SCENEOBJECT_H__11ECC224_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include <GL/glut.h>
#include "threed_objects.h"




class SceneObject  
{
public:
	virtual void InitAnimation();
	virtual float GetHeight();
	void SetColor(float r, float g, float b);
	bool IsStatic();
	bool IsObstacle();
	virtual void Draw();
	SceneObject();
	virtual ~SceneObject();

protected:
	float	m_nAniStep;
	int		m_nAniMAX;
	bool	m_bAnimated;
	
	float m_fHeight;
	GLfloat	m_color[3];
	bool m_bStatic;
	bool m_bObstacle;
	bool m_bEnabled;
	bool m_bVisible;

	//SceneObject	*m_pNeighbours[8];
	/*
			1 2 3
			4 * 5
			6 7 8
	*/
};

#endif // !defined(AFX_SCENEOBJECT_H__11ECC224_2948_11D4_95D9_907E51C10700__INCLUDED_)
