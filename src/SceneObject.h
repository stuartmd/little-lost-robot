// SceneObject.h: interface for the SceneObject class.
//
// MIT License
// 
// Copyright (c) [2016] [Stuart McDonald Dickson]
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
/////////////////////////////////////////////////////////////////////////////////

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
