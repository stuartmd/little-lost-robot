// SOWaterBridge_Straight.cpp: implementation of the SOWaterBridge_Straight class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWaterBridge_Straight.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWaterBridge_Straight::SOWaterBridge_Straight()
{
	m_bObstacle = true;
	m_bExtended = false;
}

SOWaterBridge_Straight::~SOWaterBridge_Straight()
{

}

void SOWaterBridge_Straight::Draw()
{
	SOWater_Straight::Draw();

	glTranslatef(0.0, 0.0, 3.7);
	glColor3f(0.2,0.2,0.7);
	if (m_bAnimated)
	{
		float width;
		if (m_bExtended)
			width = 4.2 * m_nAniStep / m_nAniMAX;
		else
			width = 4.2 * (m_nAniMAX-m_nAniStep) / m_nAniMAX;

		glPushMatrix();
			glTranslatef(-2.1 + width/2, 0.0, 0.0 );
			globjBaselessCuboid(width, 3.5, 0.3);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(2.1 - width/2, 0.0, 0.0 );
			globjBaselessCuboid(width, 3.5, 0.3);
		glPopMatrix();
		
		if (m_nAniStep++ == m_nAniMAX)
		{
			m_bAnimated = false;
			m_bObstacle = !m_bExtended;
		}
	}
	else if (m_bExtended)
	{
		globjBaselessCuboid(4.2, 3.5, 0.3);
		glTranslatef(0.0, 0.0, 0.3);
	}

	glTranslatef(0.0, 0.0, 0.3);
}

void SOWaterBridge_Straight::InitAnimation()
{
	m_bAnimated = true;
	m_bObstacle = true;
	m_nAniStep = 0;
	m_nAniMAX = 30;
}

void SOWaterBridge_Straight::SetExtended(bool bState)
{
	m_bExtended = bState;
	InitAnimation();
}
