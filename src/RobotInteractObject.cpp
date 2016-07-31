// RobotInteractObject.cpp: implementation of the RobotInteractObject class.
//
//////////////////////////////////////////////////////////////////////

#include "RobotInteractObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RobotInteractObject::RobotInteractObject()
{
	m_bObstacle = true;
	m_bMovable = false;
}

RobotInteractObject::~RobotInteractObject()
{

}

void RobotInteractObject::Draw()
{

}

bool RobotInteractObject::IsObstacle()
{
	return m_bObstacle;
}

bool RobotInteractObject::Grabbed()
{
	return false;
}

bool RobotInteractObject::IsMovable()
{
	return m_bMovable;
}
