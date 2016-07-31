/*
	Robot.h
	=======
	Declaration of ROBOT class.
*/
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


#ifndef _ROBOT_H
#define _ROBOT_H


//#include "Camera.h"
#include "RobotInteractObject.h"

class Camera;


enum eRobotCommand{	ROBCOM_FORWARD, 
					ROBCOM_BACKWARD,
					ROBCOM_LEFT,
					ROBCOM_RIGHT,
					ROBCOM_GRASP,
					ROBCOM_RELEASE};

class Robot
{
	friend Camera;


public:
	float GetInteractObjectAngle();
	float GetTorsoHeight();
	virtual void DrawInteractObject();
	bool SetInteractObject( RobotInteractObject* pObject, float angle);
	RobotInteractObject* GetInteractObject() { return m_pInteractingObject; };
	Robot();
	~Robot();

	bool Draw();

	inline bool GetArmsExtended() { return m_bArmsExtended; };
	inline void SetArmsExtended(bool bVal) { m_bArmsExtended = bVal; };

protected:
	float m_InteractObjectAngle;
	RobotInteractObject* m_pInteractingObject;
	virtual bool DrawTracks();
	virtual bool DrawTorso();
	virtual bool DrawArm();
	virtual bool DrawHead();


// State Variables
	bool	m_bMovingFwd;
	bool	m_bMovingBck;
	bool	m_bTurningLft;
	bool	m_bTurningRgt;
	bool	m_bTorsoTurnLft;
	bool	m_bTorsoTurnRgt;
	int		m_nBodyAngle;
	int		m_nTorsoAngle;
	int		m_nTorsoHeight;

	bool	m_bArmsExtended;

};

#endif

