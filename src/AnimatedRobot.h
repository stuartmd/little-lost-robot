// AnimatedRobot.h: interface for the AnimatedRobot class.
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

#if !defined(AFX_ANIMATEDROBOT_H__FA8E9302_292A_11D4_95D9_103453C14F00__INCLUDED_)
#define AFX_ANIMATEDROBOT_H__FA8E9302_292A_11D4_95D9_103453C14F00__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Robot.h"


class Game;

class AnimatedRobot : public Robot  
{
public:
	void SetGame(Game* pGame);
	 AnimatedRobot(Game* pGame);
	bool IsAnimated();
	virtual void DrawInteractObject();
	void TurnRight();
	void TurnLeft();
	// Actions
	bool ExtendArms();
	bool RetractArms();


	AnimatedRobot();
	virtual ~AnimatedRobot();

protected: 
	Game* m_pGame;
	virtual bool DrawArm();


	/* Turning State Vars */
	bool bTorsoTurnLft; 
	bool bTorsoTurnRgt;

	/* Gripping/Releasing State Vars */
	bool	m_bExtendingArms;
	bool	m_bRetractingArms;
	float	m_nExtendArmStep;

	int		m_nAnimStep;

};

#endif // !defined(AFX_ANIMATEDROBOT_H__FA8E9302_292A_11D4_95D9_103453C14F00__INCLUDED_)
