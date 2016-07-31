// Level2.cpp: implementation of the Level2 class.
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

#include "Level2.h"

#include "SOStart.h"
#include "SOFinish.h"
#include "SONormalSquare.h"
#include "SOWall_Straight.h"
#include "SOWall_L.h"
#include "SOWater_Straight.h"
#include "SOWater_StraightCrated.h"
#include "SOWater_L.h"

#include "SimpleCrate.h"
#include "UnmovableCrate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Level2::~Level2()
{
}


Level2::Level2(Game * pGame) : Level(pGame)
{
	int i;
	
	m_szName = "Robot Moat-L";
	m_szHint = "What ALSO floats in water?...";

	/* Initialise Game Objects */
	m_nXsize = 8;
	m_nYsize = 8;

	m_pSolution = new eRobotCommand[53];
	
	m_pSolution[0] = ROBCOM_LEFT;
	m_pSolution[1] = ROBCOM_FORWARD;
	m_pSolution[2] = ROBCOM_FORWARD;
	m_pSolution[3] = ROBCOM_GRASP;
	m_pSolution[4] = ROBCOM_BACKWARD;
	m_pSolution[5] = ROBCOM_BACKWARD;
	m_pSolution[6] = ROBCOM_BACKWARD;
	m_pSolution[7] = ROBCOM_RIGHT;
	m_pSolution[8] = ROBCOM_FORWARD;
	m_pSolution[9] = ROBCOM_FORWARD;
	m_pSolution[10] = ROBCOM_LEFT;
	m_pSolution[11] = ROBCOM_FORWARD;
	m_pSolution[12] = ROBCOM_RIGHT;
	m_pSolution[13] = ROBCOM_FORWARD;
	m_pSolution[14] = ROBCOM_RIGHT;
	m_pSolution[15] = ROBCOM_GRASP;
	m_pSolution[16] = ROBCOM_RIGHT;
	m_pSolution[17] = ROBCOM_BACKWARD;
	m_pSolution[18] = ROBCOM_BACKWARD;
	m_pSolution[19] = ROBCOM_RELEASE;
	m_pSolution[20] = ROBCOM_LEFT;
	m_pSolution[21] = ROBCOM_FORWARD;
	m_pSolution[22] = ROBCOM_FORWARD;
	m_pSolution[23] = ROBCOM_RIGHT;
	m_pSolution[24] = ROBCOM_FORWARD;
	m_pSolution[25] = ROBCOM_FORWARD;
	m_pSolution[26] = ROBCOM_RIGHT;
	m_pSolution[27] = ROBCOM_FORWARD;
	m_pSolution[28] = ROBCOM_FORWARD;
	m_pSolution[29] = ROBCOM_RIGHT;
	m_pSolution[30] = ROBCOM_GRASP;
	m_pSolution[31] = ROBCOM_FORWARD;
	m_pSolution[32] = ROBCOM_RELEASE;
	m_pSolution[33] = ROBCOM_BACKWARD;
	m_pSolution[34] = ROBCOM_RIGHT;
	m_pSolution[35] = ROBCOM_FORWARD;
	m_pSolution[36] = ROBCOM_FORWARD;
	m_pSolution[37] = ROBCOM_LEFT;
	m_pSolution[38] = ROBCOM_FORWARD;
	m_pSolution[39] = ROBCOM_FORWARD;
	m_pSolution[40] = ROBCOM_LEFT;
	m_pSolution[41] = ROBCOM_FORWARD;
	m_pSolution[42] = ROBCOM_GRASP;
	m_pSolution[43] = ROBCOM_FORWARD;
	m_pSolution[44] = ROBCOM_FORWARD;
	m_pSolution[45] = ROBCOM_RELEASE;
	m_pSolution[46] = ROBCOM_FORWARD;
	m_pSolution[47] = ROBCOM_FORWARD;
	m_pSolution[48] = ROBCOM_LEFT;
	m_pSolution[49] = ROBCOM_FORWARD;
	m_pSolution[50] = ROBCOM_FORWARD;
	m_pSolution[51] = ROBCOM_FORWARD;
	m_pSolution[52] = ROBCOM_FORWARD;
	m_nSolutionSteps = 53;


	m_pSceneObjects = new SceneObject*[16];
	m_nNumSceneObjects = 7;

	m_pInteractObjects = new RobotInteractObject*[3];
	m_nNumInteractObjects = 3;

	m_pSceneObjects[0] = new SOStart();
	m_pSceneObjects[1] = new SOFinish();

	m_pSceneObjects[2] = new SONormalSquare();
	m_pSceneObjects[3] = new SOWall_Straight();
	m_pSceneObjects[4] = new SOWall_L();
	m_pSceneObjects[5] = new SOWater_Straight();
	m_pSceneObjects[6] = new SOWater_L();
	
	m_pSceneObjects[7] = new SONormalSquare();
	m_pSceneObjects[8] = new SOWall_Straight();
	m_pSceneObjects[9] = new SOWall_L();
	m_pSceneObjects[10] = new SOWater_Straight();
	m_pSceneObjects[11] = new SOWater_L();

	m_pSceneObjects[12] = new SOWater_StraightCrated();
	m_pSceneObjects[13] = new SOWater_StraightCrated();

	m_pSceneObjects[14] = new SOWaterBridge_Straight();
	m_pSceneObjects[15] = new SOWaterBridge_Straight();


	for (i=2; i<7; i++)
	{
		m_pSceneObjects[i]->SetColor(1.0, 0.8, 0.8);
		m_pSceneObjects[i+5]->SetColor(0.8, 1.0, 1.0);
	}
	m_pSceneObjects[12]->SetColor(1.0, 0.8, 0.8);
	m_pSceneObjects[14]->SetColor(1.0, 0.8, 0.8);
	m_pSceneObjects[13]->SetColor(0.8, 1.0, 1.0);
	m_pSceneObjects[15]->SetColor(0.8, 1.0, 1.0);


	/* Initialise Game Grid */
	m_pGrid = new GameGridItem[64];
	
	for (i=1; i<7; i++)
	{
	// Straight Walls
		m_pGrid[i].Set(m_pSceneObjects[3], ORI_RIGHT);
		m_pGrid[56 + i].Set(m_pSceneObjects[3], ORI_RIGHT);
		m_pGrid[i*8].Set(m_pSceneObjects[3]);
		m_pGrid[i*8 + 7].Set(m_pSceneObjects[3]);
		
	// Normal Sections
		m_pGrid[i+8].Set(m_pSceneObjects[2]);
		m_pGrid[i*8 + 1].Set(m_pSceneObjects[2]);
	}

	// L sections
	m_pGrid[0].Set(m_pSceneObjects[4]);
	m_pGrid[7].Set(m_pSceneObjects[4], ORI_LEFT);
	m_pGrid[56].Set(m_pSceneObjects[4], ORI_RIGHT);
	m_pGrid[63].Set(m_pSceneObjects[4], ORI_DOWN);

	// Straight Water Sections
	for (i=3; i<7; i++)
	{
		m_pGrid[i + 16].Set(m_pSceneObjects[5], ORI_RIGHT);
		m_pGrid[i*8 + 2].Set(m_pSceneObjects[5]);
	}
	
	// L-shaped Water
	m_pGrid[18].Set(m_pSceneObjects[6]);
	
	// Start/Finish Squares
	m_pGrid[12].Set(m_pSceneObjects[0]); // Start
	m_pGrid[17].Set(m_pSceneObjects[1]); // Finish
	m_nRobotPos = 12;
	m_nFinishPos = 17;


	// Bridge
	m_pGrid[21].Set(m_pSceneObjects[14], ORI_RIGHT);

	// Add items
	m_pInteractObjects[0] = new SimpleCrate();
	m_pInteractObjects[1] = new UnmovableCrate();
	m_pInteractObjects[2] = new InteractSwitch();

	for (i=27; i<31; i++)
		for (int j=0; j<4; j++)
			m_pGrid[8*j + i].Set(m_pSceneObjects[2]);
	
	m_pGrid[37].pInteractObject = m_pInteractObjects[0];
	m_pGrid[27].pInteractObject = m_pInteractObjects[1];
	m_pGrid[30].pInteractObject = m_pInteractObjects[1];
	m_pGrid[35].pInteractObject = m_pInteractObjects[1];
	m_pGrid[43].pInteractObject = m_pInteractObjects[1];
	m_pGrid[45].pInteractObject = m_pInteractObjects[1];
	m_pGrid[9].pInteractObject  = m_pInteractObjects[2];
	

	/* Set grid positions and colours */
	for (i=0; i<64; i++)
	{
		m_pGrid[i].SetPos(5*(i%8), 5*(i/8));
		if ((i%2 + (i/m_nXsize)%2)==1)
		{
			for (int j=2; j<7; j++)
			{
				if (m_pGrid[i].pSceneObject == m_pSceneObjects[j])
					m_pGrid[i].pSceneObject = m_pSceneObjects[j+5];
			}
			if (m_pGrid[i].pSceneObject == m_pSceneObjects[12])
				m_pGrid[i].pSceneObject = m_pSceneObjects[13];
			if (m_pGrid[i].pSceneObject == m_pSceneObjects[14])
				m_pGrid[i].pSceneObject = m_pSceneObjects[15];
		}
	}

	m_pSwitch = (InteractSwitch*) m_pInteractObjects[2];
	m_pBridge = (SOWaterBridge_Straight*) m_pGrid[21].pSceneObject;
}

bool Level2::RetractArms()
{
	int interactPos;

	switch(m_oriRobot)
	{
	case ORI_UP:
		interactPos = m_nRobotPos+m_nXsize;
		break;
	case ORI_RIGHT:
		interactPos = m_nRobotPos+1;
		break;
	case ORI_LEFT:
		interactPos = m_nRobotPos-1;
		break;
	case ORI_DOWN:
		interactPos = m_nRobotPos-m_nXsize;
		break;
	}

	if (m_pGame->theRobot.GetInteractObject())
		if (m_pGrid[interactPos].pSceneObject == m_pSceneObjects[5] ||
			m_pGrid[interactPos].pSceneObject == m_pSceneObjects[10])
		{
			m_pGrid[interactPos].pSceneObject = 
				(m_pGrid[interactPos].pSceneObject == m_pSceneObjects[5]) ?
					m_pSceneObjects[12] :
					m_pSceneObjects[13];

			m_pGrid[interactPos].pSceneObject->InitAnimation();
			m_pGame->theRobot.SetInteractObject(0,0);
			m_pGame->theRobot.RetractArms();
			return true;
		}

	return Level::RetractArms();
}

bool Level2::ExtendArms()
{
	return Level::ExtendArms();
}


void Level2::RobotGrabbed(RobotInteractObject * pObject)
{
	
	if (pObject==m_pSwitch)
	{
		/*m_pGrid[21].pSceneObject = 
			(m_pGrid[21].pSceneObject == m_pSceneObjects[10]) ?
				m_pSceneObjects[14] :
				m_pSceneObjects[15]; 

		m_pGrid[21].pSceneObject->InitAnimation();
		*/
		m_pBridge->SetExtended(m_pSwitch->GetState());
	}
}
