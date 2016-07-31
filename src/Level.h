// Level.h: interface for the Level class.
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

#if !defined(AFX_LEVEL_H__11ECC223_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_LEVEL_H__11ECC223_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "Game.h"
#include "SceneObject.h"
#include "RobotInteractObject.h"


enum GGI_ORIENTATION{ ORI_UP=0, ORI_LEFT=90, ORI_DOWN=180, ORI_RIGHT=270};


struct GameGridItem
{
	SceneObject*			pSceneObject;
	RobotInteractObject*	pInteractObject;
	float Pos3f[3];
	GGI_ORIENTATION orientation;
	GGI_ORIENTATION objOrientation;
	

	GameGridItem() { 
		pSceneObject = 0; 
		pInteractObject = 0;
		Pos3f[0] = Pos3f[1] = Pos3f[2] = 0;
		orientation = objOrientation = ORI_UP;
	};

	GameGridItem(SceneObject* pObject, GGI_ORIENTATION ori=ORI_UP, float x=0, float y=0, float z=0) : pSceneObject(pObject), orientation(ori)
	{
		objOrientation = ORI_UP;
		Pos3f[0] = x;
		Pos3f[1] = y;
		Pos3f[2] = z;
	};

	void Set(SceneObject* pObject, GGI_ORIENTATION ori=ORI_UP, float x=0, float y=0, float z=0)
	{
		pSceneObject = pObject;
		pInteractObject = 0;
		orientation = ori;
		Pos3f[0] = x;
		Pos3f[1] = y;
		Pos3f[2] = z;
	};

	void SetPos(float x=0, float y=0, float z=0)
	{
		objOrientation = ORI_UP;
		Pos3f[0] = x;
		Pos3f[1] = y;
		Pos3f[2] = z;
	};
};


class Level  
{
public:
	const char* GetHint();
	const char* GetName();
	virtual void RobotGrabbed(RobotInteractObject* pObject);
	virtual int GetSolutionSteps();
	virtual const eRobotCommand* GetSolution();
	bool ExecuteRobotCommand(eRobotCommand cmd);
	virtual bool IsAcceptingInput();
	float GetRobotAngle();
	float GetRobotPosY();
	float GetRobotPosX();
	float GetDepth();
	float GetWidth();
	virtual bool RetractArms();
	virtual bool ExtendArms();
	virtual bool MoveBackward();
	virtual bool MoveForward();
	virtual bool TurnRight();
	virtual bool TurnLeft();
	virtual bool Draw();
	virtual ~Level();

	RobotInteractObject		**m_pInteractObjects;

protected:
	Level( Game* pGame );

	int m_nRobotPos;
	GGI_ORIENTATION m_oriRobot;

	GameGridItem* m_pGrid;
	SceneObject				**m_pSceneObjects;
	

	int m_nNumSceneObjects;
	int m_nNumInteractObjects;

	int m_nXsize, m_nYsize;
	Game* m_pGame;


protected:
	eRobotCommand* m_pSolution;
	int m_nSolutionSteps;

	const char* m_szName;
	const char* m_szHint;

	GLuint m_dlStatic;
	int m_nFinishPos;

	bool DrawGrid();
	
	
	bool DrawRobot();
	// Animation variables
	bool	m_bAniFinish;
	bool	m_bAniTurnLeft;
	bool	m_bAniTurnRight;
	bool	m_bAniMoveFwd;
	bool	m_bAniMoveBck;
	float	m_nAniIndex;


};

#endif // !defined(AFX_LEVEL_H__11ECC223_2948_11D4_95D9_907E51C10700__INCLUDED_)
