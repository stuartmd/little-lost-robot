// SOWater_StraightCrated.cpp: implementation of the SOWater_StraightCrated class.
//
//////////////////////////////////////////////////////////////////////

#include "SOWater_StraightCrated.h"
#include "SimpleCrate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWater_StraightCrated::SOWater_StraightCrated()
{
	m_bAniInit = false;
	m_bObstacle = false;
	m_bStatic = false;
}

SOWater_StraightCrated::~SOWater_StraightCrated()
{

}

void SOWater_StraightCrated::Draw()
{
	SOWater_Straight::Draw();
	if (m_bAniInit)
	{
		glTranslatef(0,0, 4.0 * ((15.0-m_nAniStep) / 15.0));
		if (++m_nAniStep==15)
		{
			m_bAniInit = false;
			m_bObstacle = false;
		}
	}
	SimpleCrate::DrawObject();

}

void SOWater_StraightCrated::InitAnimation()
{
	m_bAniInit = true;
	m_nAniStep = 0.0;
	m_bObstacle = true;
}
