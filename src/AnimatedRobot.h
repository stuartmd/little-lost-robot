// AnimatedRobot.h: interface for the AnimatedRobot class.
//
//////////////////////////////////////////////////////////////////////

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
