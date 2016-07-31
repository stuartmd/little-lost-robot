// amera.h: interface for the Camera class.
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

#if !defined(AFX_AMERA_H__600CE4C0_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
#define AFX_AMERA_H__600CE4C0_29EE_11D4_95D9_30AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <GL/glut.h>

class Game;
class TransitionCamera;
enum	eProjMode{PROJ_ORTHO, PROJ_PERSP};

class Camera  
{
	friend class TransitionCamera;

public:
	virtual void Update();
	virtual void reshape();
	virtual void reshape(int w, int h);
	virtual bool Draw();
	Camera(Game* pGame);
	virtual ~Camera();

protected:
	float m_ori[3];
	float m_pos[3];
	int m_width;
	int m_height;

	Game*	m_pGame;

	eProjMode m_eProjMode;
	float	m_fvModeVars[6];

	// Orthographic Projection Vars
	float&	m_ClipLeft;
	float&	m_ClipRight;
	float&	m_ClipBottom;
	float&	m_ClipTop;

	// Perspective Projection Vars
	float&	m_FOV;
	float&	m_Aspect;
	float&  m_ClipNear;
	float&	m_ClipFar;
};

#endif // !defined(AFX_AMERA_H__600CE4C0_29EE_11D4_95D9_30AA51C19A15__INCLUDED_)
