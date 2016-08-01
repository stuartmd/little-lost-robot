// Level1.cpp: implementation of the Level1 class.
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

#include "Level1.h"
#include "SOStart.h"
#include "SOFinish.h"
#include "SONormalSquare.h"
#include "SOWall_Straight.h"
#include "SOWall_L.h"
#include "SOWall_T.h"
#include "SOWall_End.h"

#include "SimpleCrate.h"
#include <GL/glut.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Level1::~Level1()
{
}

Level1::Level1(Game* pGame) : Level(pGame)
{

    m_szName = "Crate Expectations";
    m_szHint = "You do not have to take the crate with you.";

    /* Initialise Game Objects */
    m_nXsize = 9;
    m_nYsize = 9;

    m_pSceneObjects = new SceneObject*[ m_nNumSceneObjects = 8 ];
    m_pInteractObjects = new RobotInteractObject*[ m_nNumInteractObjects = 1 ];


    m_pSceneObjects[0] = new SOStart();
    m_pSceneObjects[1] = new SOFinish();
    m_pSceneObjects[2] = new SONormalSquare();
    m_pSceneObjects[3] = new SONormalSquare();
    m_pSceneObjects[4] = new SOWall_Straight();
    m_pSceneObjects[5] = new SOWall_L();
    m_pSceneObjects[6] = new SOWall_T();
    m_pSceneObjects[7] = new SOWall_End();

    ((SONormalSquare*) m_pSceneObjects[2])->SetColor(1.0, 0.8, 0.8);
    ((SONormalSquare*) m_pSceneObjects[3])->SetColor(0.8, 1.0, 1.0);


    m_pSolution = new eRobotCommand[25];
    m_pSolution[0] = ROBCOM_FORWARD;
    m_pSolution[1] = ROBCOM_FORWARD;
    m_pSolution[2] = ROBCOM_FORWARD;
    m_pSolution[3] = ROBCOM_GRASP;
    m_pSolution[4] = ROBCOM_LEFT;
    m_pSolution[5] = ROBCOM_RELEASE;
    m_pSolution[6] = ROBCOM_RIGHT;
    m_pSolution[7] = ROBCOM_FORWARD;
    m_pSolution[8] = ROBCOM_RIGHT;
    m_pSolution[9] = ROBCOM_FORWARD;
    m_pSolution[10] = ROBCOM_FORWARD;
    m_pSolution[11] = ROBCOM_FORWARD;
    m_pSolution[12] = ROBCOM_LEFT;
    m_pSolution[13] = ROBCOM_FORWARD;
    m_pSolution[14] = ROBCOM_FORWARD;
    m_pSolution[15] = ROBCOM_LEFT;
    m_pSolution[16] = ROBCOM_FORWARD;
    m_pSolution[17] = ROBCOM_FORWARD;
    m_pSolution[18] = ROBCOM_FORWARD;
    m_pSolution[19] = ROBCOM_FORWARD;
    m_pSolution[20] = ROBCOM_FORWARD;
    m_pSolution[21] = ROBCOM_FORWARD;
    m_pSolution[22] = ROBCOM_FORWARD;
    m_pSolution[23] = ROBCOM_LEFT;
    m_pSolution[24] = ROBCOM_FORWARD;
    m_nSolutionSteps = 25;



    /* Initialise Game Grid */
    m_pGrid = new GameGridItem[81];

    // Start/Finish Squares
    m_pGrid[13].Set(m_pSceneObjects[0]); // Start
    m_pGrid[55].Set(m_pSceneObjects[1]); // Finish
    m_nRobotPos = 13;
    m_nFinishPos = 55;

    // Straight Walls
    m_pGrid[4].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[12].Set(m_pSceneObjects[4]);
    m_pGrid[14].Set(m_pSceneObjects[4]);
    m_pGrid[21].Set(m_pSceneObjects[4]);
    m_pGrid[23].Set(m_pSceneObjects[4]);
    m_pGrid[29].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[32].Set(m_pSceneObjects[4]);
    m_pGrid[37].Set(m_pSceneObjects[4]);
    m_pGrid[42].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[43].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[53].Set(m_pSceneObjects[4]);
    m_pGrid[54].Set(m_pSceneObjects[4]);
    m_pGrid[57].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[58].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[59].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[62].Set(m_pSceneObjects[4]);
    m_pGrid[63].Set(m_pSceneObjects[4]);
    m_pGrid[71].Set(m_pSceneObjects[4]);
    m_pGrid[73].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[74].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[75].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[76].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[77].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[78].Set(m_pSceneObjects[4], ORI_RIGHT);
    m_pGrid[79].Set(m_pSceneObjects[4], ORI_RIGHT);

    // L sections
    m_pGrid[3].Set(m_pSceneObjects[5]);
    m_pGrid[5].Set(m_pSceneObjects[5], ORI_LEFT);
    m_pGrid[28].Set(m_pSceneObjects[5]);
    m_pGrid[30].Set(m_pSceneObjects[5], ORI_DOWN);
    m_pGrid[41].Set(m_pSceneObjects[5], ORI_RIGHT);
    m_pGrid[44].Set(m_pSceneObjects[5], ORI_LEFT);
    m_pGrid[45].Set(m_pSceneObjects[5]);
    m_pGrid[47].Set(m_pSceneObjects[5], ORI_LEFT);
    m_pGrid[56].Set(m_pSceneObjects[5], ORI_RIGHT);
    m_pGrid[72].Set(m_pSceneObjects[5], ORI_RIGHT);
    m_pGrid[80].Set(m_pSceneObjects[5], ORI_DOWN);

    // T sections
    m_pGrid[46].Set(m_pSceneObjects[6]);

    // End Section
    m_pGrid[60].Set(m_pSceneObjects[7], ORI_RIGHT);

    // Flat Squares
    m_pGrid[22].Set(m_pSceneObjects[2]);
    m_pGrid[31].Set(m_pSceneObjects[3]);
    m_pGrid[38].Set(m_pSceneObjects[2]);
    m_pGrid[39].Set(m_pSceneObjects[3]);
    m_pGrid[40].Set(m_pSceneObjects[2]);
    m_pGrid[48].Set(m_pSceneObjects[2]);
    m_pGrid[49].Set(m_pSceneObjects[3]);
    m_pGrid[50].Set(m_pSceneObjects[2]);
    m_pGrid[51].Set(m_pSceneObjects[3]);
    m_pGrid[52].Set(m_pSceneObjects[2]);
    m_pGrid[61].Set(m_pSceneObjects[3]);

    m_pGrid[64].Set(m_pSceneObjects[2]);
    m_pGrid[65].Set(m_pSceneObjects[3]);
    m_pGrid[66].Set(m_pSceneObjects[2]);
    m_pGrid[67].Set(m_pSceneObjects[3]);
    m_pGrid[68].Set(m_pSceneObjects[2]);
    m_pGrid[69].Set(m_pSceneObjects[3]);
    m_pGrid[70].Set(m_pSceneObjects[2]);


    /* Set grid positions */
    for (int i = 0; i < 81; i++) {
        m_pGrid[i].SetPos(2.5 + 5 * (i % 9), 2.5 + 5 * (i / 9));
    }


    // Add items
    m_pInteractObjects[0] = new SimpleCrate();
    m_pGrid[49].pInteractObject = m_pInteractObjects[0];

}

