// Level.cpp: implementation of the Level class.
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

#include "Level.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Level::~Level()
{
    int i;

    for (i = 0; i < m_nNumSceneObjects; i++) {
        delete m_pSceneObjects[i];
        m_pSceneObjects[i] = 0;
    }
    
    if (m_pSceneObjects)
        delete [] m_pSceneObjects;

    for (i = 0; i < m_nNumInteractObjects; i++) {
        delete m_pInteractObjects[i];
        m_pInteractObjects[i] = 0;
    }

    if (m_pInteractObjects)
        delete [] m_pInteractObjects;

    if (m_pGrid)
        delete [] m_pGrid;

    if (m_pSolution)
        delete [] m_pSolution;

    if (m_dlStatic)
        glDeleteLists(m_dlStatic, 1);
}

Level::Level(Game* pGame)
{
    m_pGame = pGame;
    m_oriRobot = ORI_UP;

    m_bAniMoveFwd = m_bAniMoveBck = false;
    m_bAniTurnLeft = m_bAniTurnRight = false;

    m_bAniFinish = false;
    m_dlStatic = 0;
    m_nSolutionSteps = 0;
    m_pSolution = 0;
    m_pGrid = 0;
    m_pSceneObjects = 0;
    m_pInteractObjects = 0;

    m_szName = "";
    m_szHint = "";
}

bool Level::Draw()
{
    if (m_bAniFinish) {
        float pos = -50.0 * m_nAniIndex / 50.0;

        glPushMatrix();
        glTranslatef(0, 0, pos);
    }

    DrawGrid();

    if (m_bAniFinish) {
        glPopMatrix();
        if (m_nAniIndex < 50)
            m_nAniIndex++;
        else
            m_pGame->NextLevel();
    }

    DrawRobot();

    if (!(m_bAniMoveFwd || m_bAniMoveBck ||
            m_bAniTurnLeft || m_bAniTurnRight || m_bAniFinish)) {
        // Not in the middle of an animation - check state
        if (m_nRobotPos == m_nFinishPos) {
            m_bAniFinish = true;
            m_nAniIndex = 0;
        }
    }

    return true;
}

bool Level::TurnLeft()
{
    int ori = m_oriRobot;
    SceneObject*     pEndObject, *pThruObject;

    if (m_pGame->theRobot.GetInteractObject()) {
        int endPos = m_nRobotPos;
        int thruPos = m_nRobotPos;


        switch (m_oriRobot) {
        case ORI_UP:
            endPos --;
            thruPos += m_nXsize - 1;
            break;
        case ORI_RIGHT:
            endPos += m_nXsize;
            thruPos += m_nXsize + 1;
            break;
        case ORI_LEFT:
            endPos -= m_nXsize;
            thruPos -= m_nXsize + 1;
            break;
        case ORI_DOWN:
            endPos ++;
            thruPos -= (m_nXsize - 1);
            break;
        }

        pEndObject = m_pGrid[endPos].pSceneObject;
        pThruObject = m_pGrid[thruPos].pSceneObject;
        if (pEndObject)
            if (pEndObject->IsObstacle() &&
                    pEndObject->GetHeight() > m_pGame->theRobot.GetTorsoHeight())
                return false;
        if (m_pGrid[endPos].pInteractObject)
            if (m_pGrid[endPos].pInteractObject->IsObstacle())
                return false;
        if (pThruObject)
            if (pThruObject->IsObstacle() &&
                    pThruObject->GetHeight() > m_pGame->theRobot.GetTorsoHeight())
                return false;
        if (m_pGrid[thruPos].pInteractObject)
            if (m_pGrid[thruPos].pInteractObject->IsObstacle())
                return false;
    }

    m_oriRobot = (GGI_ORIENTATION)((ori + 90) % 360) ;  //(GGI_ORIENTATION) ((4 + ori)%4);
    //m_pGame->theRobot.TurnLeft();

    m_bAniTurnLeft = true;
    m_nAniIndex = 0;
    return true;
}

bool Level::TurnRight()
{
    int ori = m_oriRobot;
    SceneObject*     pEndObject, *pThruObject;
    if (m_pGame->theRobot.GetInteractObject()) {
        int endPos = m_nRobotPos;
        int thruPos = m_nRobotPos;

        switch (m_oriRobot) {
        case ORI_UP:
            endPos ++;
            thruPos += m_nXsize + 1;
            break;
        case ORI_RIGHT:
            endPos -= m_nXsize;
            thruPos -= (m_nXsize - 1);
            break;
        case ORI_LEFT:
            endPos += m_nXsize;
            thruPos += m_nXsize - 1;
            break;
        case ORI_DOWN:
            endPos --;
            thruPos -= m_nXsize + 1;
            break;
        }

        pEndObject = m_pGrid[endPos].pSceneObject;
        pThruObject = m_pGrid[thruPos].pSceneObject;
        if (pEndObject)
            if (pEndObject->IsObstacle() &&
                    pEndObject->GetHeight() > m_pGame->theRobot.GetTorsoHeight())
                return false;
        if (m_pGrid[endPos].pInteractObject)
            if (m_pGrid[endPos].pInteractObject->IsObstacle())
                return false;
        if (pThruObject)
            if (pThruObject->IsObstacle() &&
                    pThruObject->GetHeight() > m_pGame->theRobot.GetTorsoHeight())
                return false;
        if (m_pGrid[thruPos].pInteractObject)
            if (m_pGrid[thruPos].pInteractObject->IsObstacle())
                return false;
    }

    m_oriRobot = (GGI_ORIENTATION)((270 + ori) % 360) ;  //;
    //m_pGame->theRobot.TurnRight();
    m_bAniTurnRight = true;
    m_nAniIndex = 0;
    return true;
}

bool Level::MoveForward()
{
    int newPos = m_nRobotPos;

    switch (m_oriRobot) {
    case ORI_UP:
        newPos += m_nXsize;
        break;
    case ORI_RIGHT:
        newPos ++;
        break;
    case ORI_LEFT:
        newPos --;
        break;
    case ORI_DOWN:
        newPos -= m_nXsize;
        break;
    }

    if (m_pGrid[newPos].pSceneObject)
        if (m_pGrid[newPos].pSceneObject->IsObstacle())
            return false;

    if (m_pGrid[newPos].pInteractObject)
        if (m_pGrid[newPos].pInteractObject->IsObstacle())
            return false;

    if (m_pGame->theRobot.GetInteractObject()) {
        int newPos2 = newPos;

        switch (m_oriRobot) {
        case ORI_UP:
            newPos2 += m_nXsize;
            break;
        case ORI_RIGHT:
            newPos2 ++;
            break;
        case ORI_LEFT:
            newPos2 --;
            break;
        case ORI_DOWN:
            newPos2 -= m_nXsize;
            break;
        }

        if (m_pGrid[newPos2].pSceneObject)
            if (m_pGrid[newPos2].pSceneObject->IsObstacle() && m_pGrid[newPos2].pSceneObject->GetHeight() > m_pGame->theRobot.GetTorsoHeight())
                return false;

        if (m_pGrid[newPos2].pInteractObject)
            if (m_pGrid[newPos2].pInteractObject->IsObstacle())
                return false;
    }
    m_nRobotPos = newPos;

    m_bAniMoveFwd = true;
    m_nAniIndex = 0;
    return true;
}

bool Level::MoveBackward()
{
    int newPos = m_nRobotPos;

    switch (m_oriRobot) {
    case ORI_UP:
        newPos -= m_nXsize;
        break;
    case ORI_RIGHT:
        newPos --;
        break;
    case ORI_LEFT:
        newPos ++;
        break;
    case ORI_DOWN:
        newPos += m_nXsize;
        break;
    }

    if (m_pGrid[newPos].pSceneObject)
        if (m_pGrid[newPos].pSceneObject->IsObstacle())
            return false;

    if (m_pGrid[newPos].pInteractObject)
        if (m_pGrid[newPos].pInteractObject->IsObstacle())
            return false;

    m_nRobotPos = newPos;

    m_bAniMoveBck = true;
    m_nAniIndex = 0;

    return true;
}

bool Level::ExtendArms()
{
    int interactPos;

    switch (m_oriRobot) {
    case ORI_UP:
        interactPos = m_nRobotPos + m_nXsize;
        break;
    case ORI_RIGHT:
        interactPos = m_nRobotPos + 1;
        break;
    case ORI_LEFT:
        interactPos = m_nRobotPos - 1;
        break;
    case ORI_DOWN:
        interactPos = m_nRobotPos - m_nXsize;
        break;
    }

    if (m_pGrid[interactPos].pInteractObject) {
        if (m_pGrid[interactPos].pInteractObject->IsMovable()) {
            m_pGame->theRobot.ExtendArms();
            m_pGame->theRobot.SetInteractObject(m_pGrid[interactPos].pInteractObject, m_pGrid[interactPos].objOrientation - m_oriRobot);
            m_pGrid[interactPos].pInteractObject = 0;
        } else {
            m_pGame->theRobot.ExtendArms();
            m_pGame->theRobot.SetInteractObject(m_pGrid[interactPos].pInteractObject, m_pGrid[interactPos].objOrientation - m_oriRobot);
        }

    }
    return true;
}

bool Level::RetractArms()
{
    int interactPos;
    switch (m_oriRobot) {
    case ORI_UP:
        interactPos = m_nRobotPos + m_nXsize;
        break;
    case ORI_RIGHT:
        interactPos = m_nRobotPos + 1;
        break;
    case ORI_LEFT:
        interactPos = m_nRobotPos - 1;
        break;
    case ORI_DOWN:
        interactPos = m_nRobotPos - m_nXsize;
        break;
    }
    if (m_pGrid[interactPos].pInteractObject == 0) {
        m_pGrid[interactPos].pInteractObject = m_pGame->theRobot.GetInteractObject();
        m_pGrid[interactPos].objOrientation = (GGI_ORIENTATION)(m_oriRobot + (int) m_pGame->theRobot.GetInteractObjectAngle());
        m_pGame->theRobot.RetractArms();
        m_pGame->theRobot.SetInteractObject(0, 0);
    }

    return true;
}

bool Level::ToggleGrabber()
{
    if (m_pGame->theRobot.GetArmsExtended()) {
        return RetractArms();
    } else {
        return ExtendArms();
    }
}

bool Level::DrawRobot()
{
    float angle = m_oriRobot;

    /*
    glTranslatef(   m_pGrid[m_nRobotPos].Pos3f[0],
                    m_pGrid[m_nRobotPos].Pos3f[1],
                    m_pGrid[m_nRobotPos].Pos3f[2]);
    */

    glTranslatef(GetRobotPosX(),
                 GetRobotPosY(),
                 m_pGrid[m_nRobotPos].Pos3f[2]);

    // Draw Robot
    /*
    switch(m_oriRobot)
    {
    case ORI_UP:
        angle = 0.0;
        break;
    case ORI_RIGHT:
        angle = -90.0;
        break;
    case ORI_DOWN:
        angle = 180.0;
        break;
    case ORI_LEFT:
        angle = 90.0;
        break;
    }
    */

    if (m_bAniMoveBck || m_bAniMoveFwd) {
        if (++m_nAniIndex == 15)
            m_bAniMoveFwd = m_bAniMoveBck = false;
    } else if (m_bAniTurnLeft || m_bAniTurnRight) {
        /*float oppAngle = 90.0f * (15.0f - m_nAniIndex) / 15.0f;
        if (m_bAniTurnLeft)
            oppAngle *= -1.0f;
        angle += oppAngle;
        */
        angle = GetRobotAngle();

        if (++m_nAniIndex == 15)
            m_bAniTurnLeft = m_bAniTurnRight = false;
    }

    glRotatef(angle, 0, 0, 1);
    m_pGame->theRobot.Draw();
    return true;
}

float Level::GetWidth()
{
    return m_nXsize * 5.0;
}

float Level::GetDepth()
{
    return m_nYsize * 5.0;
}

float Level::GetRobotPosX()
{
    if (m_bAniMoveBck || m_bAniMoveFwd) {
        float pos = 5.0 * (15.0 - m_nAniIndex) / 15.0;

        if (m_bAniMoveFwd)
            pos *= -1.0;

        switch (m_oriRobot) {
        case ORI_RIGHT:
            break;
        case ORI_LEFT:
            pos *= -1.0;
            break;

        default:
            return m_pGrid[m_nRobotPos].Pos3f[0];
        }

        return (m_pGrid[m_nRobotPos].Pos3f[0] + pos);
    } else
        return m_pGrid[m_nRobotPos].Pos3f[0];
}

float Level::GetRobotPosY()
{
    if (m_bAniMoveBck || m_bAniMoveFwd) {
        float pos = 5.0 * (15.0 - m_nAniIndex) / 15.0;

        if (m_bAniMoveFwd)
            pos *= -1.0;

        switch (m_oriRobot) {
        case ORI_UP:
            //glTranslatef(0, pos, 0);
            break;
        case ORI_DOWN:
            pos *= -1.0;
            break;
        default:
            return m_pGrid[m_nRobotPos].Pos3f[1];
        }

        return (m_pGrid[m_nRobotPos].Pos3f[1] + pos);
    } else
        return m_pGrid[m_nRobotPos].Pos3f[1];
}

bool Level::DrawGrid()
{
    GameGridItem* pItem;
    int i;

    if (m_dlStatic) {
        glCallList(m_dlStatic);
    } else {
        m_dlStatic = glGenLists(1);
        glNewList(m_dlStatic, GL_COMPILE_AND_EXECUTE);
        for (i = 0; i < (m_nXsize * m_nYsize); i++) {
            pItem = &m_pGrid[i];

            if (pItem->pSceneObject) {
                if (pItem->pSceneObject->IsStatic()) {
                    glPushMatrix();
                    glTranslatef(pItem->Pos3f[0],
                                 pItem->Pos3f[1],
                                 pItem->Pos3f[2]);

                    /*
                    switch(pItem->orientation)
                    {
                    case ORI_UP:
                        angle = 0.0;
                        break;
                    case ORI_RIGHT:
                        angle = 270.0;
                        break;
                    case ORI_DOWN:
                        angle = 180.0;
                        break;
                    case ORI_LEFT:
                        angle = 90.0;
                        break;
                    }
                    */
                    glRotatef((pItem->orientation), 0, 0, 1);
                    pItem->pSceneObject->Draw();
                    glPopMatrix();
                }
            }
        }
        glEndList();

    }


    for (i = 0; i < (m_nXsize * m_nYsize); i++) {
        pItem = &m_pGrid[i];

        if (pItem->pSceneObject && pItem->pInteractObject) {
            glPushMatrix();
            glTranslatef(pItem->Pos3f[0],
                         pItem->Pos3f[1],
                         pItem->Pos3f[2]);

            if (pItem->orientation)
                glRotatef(pItem->orientation, 0, 0, 1);
            if (!(pItem->pSceneObject->IsStatic()))
                pItem->pSceneObject->Draw();

            glRotatef(pItem->objOrientation - pItem->orientation, 0, 0, 1);
            pItem->pInteractObject->Draw();
            glPopMatrix();
        } else {
            if (pItem->pSceneObject) {
                if (!(pItem->pSceneObject->IsStatic())) {
                    glPushMatrix();
                    glTranslatef(pItem->Pos3f[0],
                                 pItem->Pos3f[1],
                                 pItem->Pos3f[2]);

                    if (pItem->orientation)
                        glRotatef(pItem->orientation, 0, 0, 1);
                    pItem->pSceneObject->Draw();
                    glPopMatrix();
                }
            }

            if (pItem->pInteractObject) {
                glPushMatrix();
                glTranslatef(pItem->Pos3f[0],
                             pItem->Pos3f[1],
                             pItem->Pos3f[2]);
                if (pItem->objOrientation)
                    glRotatef(pItem->objOrientation, 0, 0, 1);
                pItem->pInteractObject->Draw();
                glPopMatrix();
            }
        }
    }

    return true;
}

float Level::GetRobotAngle()
{
    float angle = m_oriRobot;

    if (m_bAniTurnLeft || m_bAniTurnRight) {
        float oppAngle = 90.0f * (15.0f - m_nAniIndex) / 15.0f;
        if (m_bAniTurnLeft)
            oppAngle *= -1.0f;
        angle += oppAngle;
    }
    return angle;
}

bool Level::IsAcceptingInput()
{
    return (!m_bAniFinish &&
            !m_bAniTurnLeft  &&
            !m_bAniTurnRight &&
            !m_bAniMoveFwd &&
            !m_bAniMoveBck &&
            !m_pGame->theRobot.IsAnimated());
}

bool Level::ExecuteRobotCommand(eRobotCommand cmd)
{
    switch (cmd) {
    case ROBCOM_FORWARD:
        return MoveForward();

    case ROBCOM_BACKWARD:
        return MoveBackward();

    case ROBCOM_LEFT:
        return TurnLeft();

    case ROBCOM_RIGHT:
        return TurnRight();

    case ROBCOM_GRASP:
        return ExtendArms();

    case ROBCOM_RELEASE:
        return RetractArms();

    case ROBCOM_TOGGLE_GRABBER:
        return ToggleGrabber();
    }
    return false;
}

const eRobotCommand* Level::GetSolution()
{
    return m_pSolution;
}

int Level::GetSolutionSteps()
{
    return m_nSolutionSteps;
}

void Level::RobotGrabbed(RobotInteractObject* pObject)
{

}

const char* Level::GetName()
{
    return m_szName;
}

const char* Level::GetHint()
{
    return m_szHint;
}
