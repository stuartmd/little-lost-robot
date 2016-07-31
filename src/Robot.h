/*
	Robot.h
	=======
	Declaration of ROBOT class.
*/


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

