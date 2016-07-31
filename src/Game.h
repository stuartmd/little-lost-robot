// Game.h: interface for the Game class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__11ECC222_2948_11D4_95D9_907E51C10700__INCLUDED_)
#define AFX_GAME_H__11ECC222_2948_11D4_95D9_907E51C10700__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "AnimatedRobot.h"

#include "Camera.h"
#include "ChaseCamera.h"
#include "OverviewCamera.h"
#include "RobotVisionCamera.h"

#include "TransitionCamera.h"

#include <list>
using namespace std;

class Level;

#include "TextureManager.h"
#include "Robot.h"	// Added by ClassView


enum eGameTextures{	TEX_ROBCOM_FORWARD = ROBCOM_FORWARD,
				    TEX_ROBCOM_BACKWARD,
					TEX_ROBCOM_LEFT,
					TEX_ROBCOM_RIGHT,
					TEX_ROBCOM_GRASP,
					TEX_ROBCOM_RELEASE};

enum eGameMode{ GM_START,
				GM_PLAY,
				GM_FINISH };

class Game  
{
	
public:
	void reshape();
	void DrawInstructionCache();
	void reshape(int x, int y);	

	bool SolveLevel();
	void LevelProcessSpecialKey(int key, int x, int y);
	void special(int key, int x, int y);
	void ChangeCamera();
	friend Camera;

	bool NextLevel();
	bool Draw();
	
	void keyboard( unsigned char nKey, int a, int b);
	void Start();
	Game();
	virtual ~Game();

	AnimatedRobot	theRobot;

	Level	*pLevels[2];
	Level*	pCurrentLevel;
	int		m_nLevelIndex;
	int		m_nNumLevels;

protected:
	void DrawLevelDetails();
	bool m_bShowLevelDetails;
	void DrawFinishScreen();
	void DrawStartScreen();
	bool m_bShowInstructions;
	void DrawHUD();
	void printstring(void *font, const char *string);
	void DrawInstructions();
	int m_lastCmd;
	int m_nWidth, m_nHeight;
	list<eRobotCommand>	m_InstructionCache;
	void ProcessLevelKey(unsigned char nKey, int a, int b);
	int m_nActiveCamera;
	int m_nUserCamera;
	int m_nNumCameras;
	Camera** m_pvCameras;
	Camera* m_pUserCamera;
	Camera* m_pActiveCamera;

	TransitionCamera*	m_pTransCamera;

	OverviewCamera*		m_pOverviewCamera;
	ChaseCamera*		m_pChaseCamera;
	RobotVisionCamera*	m_pRobotVisionCamera;
	TextureManager*		pTextureManager;

	eGameMode	m_eGameMode;
};	

#endif // !defined(AFX_GAME_H__11ECC222_2948_11D4_95D9_907E51C10700__INCLUDED_)
