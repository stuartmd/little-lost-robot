// Game.cpp: implementation of the Game class.
//
//////////////////////////////////////////////////////////////////////

#include "Game.h"
#include "Level.h"

#include "Level1.h"
#include "Level2.h"

#include <GL/glut.h>
#include "TexSupport/Image.h"
#include "TexSupport/TgaReader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
 
Game::Game()  
{
	m_eGameMode = GM_START;
	theRobot.SetGame(this);
	pLevels[0] = new Level1(this);
	pLevels[1] = new Level2(this);
	m_nNumLevels = 2;
	m_nLevelIndex = 0;
	pCurrentLevel = pLevels[m_nLevelIndex];

	m_pvCameras = new Camera*[m_nNumCameras = 3];
	m_pvCameras[0] = new OverviewCamera(this);
	m_pvCameras[1] = new ChaseCamera(this);
	m_pvCameras[2] = new RobotVisionCamera(this);

	m_nUserCamera = 0;
	m_pUserCamera = m_pvCameras[0];
	m_pActiveCamera = m_pUserCamera;
	m_nActiveCamera = 0;
	m_nNumCameras = 3;

	m_pTransCamera = new TransitionCamera(this);

	
	pTextureManager = new TextureManager();
	
	m_lastCmd = -1;

	m_bShowInstructions = false;
	m_bShowLevelDetails = true;
}

Game::~Game()
{
	int i;

	for (i=0; i<m_nNumLevels; i++) 
	{
		delete pLevels[i];
		pLevels[i] = 0;
	}

	for (i=0; i < m_nNumCameras; i++)
		delete m_pvCameras[i];

	delete [] m_pvCameras;
	m_pvCameras = 0;

	delete m_pTransCamera;
	m_pTransCamera = 0;
	
	delete pTextureManager;
	pTextureManager = 0;
}

void Game::Start()
{

}

void Game::keyboard(unsigned char nKey, int a, int b)
{
	switch(m_eGameMode)
	{
	case GM_START:
		m_eGameMode = GM_PLAY;
		break;
	
	case GM_PLAY:
		if (m_bShowLevelDetails)
		{
			m_bShowLevelDetails = false;
			return;
		}

		switch( nKey)
		{
		case 'c':				// CHANGE CAMERA
			ChangeCamera();
			glutPostRedisplay();
			break;

		case 's':				// SOLVE LEVEL
			SolveLevel();
			break;

		case 8:					// BACKSPACE  --> Delete last command in InstructionCache
			if (m_InstructionCache.size()>0)
				m_InstructionCache.pop_back();
			break;

		case 27:				// KEY_ESCAPE --> Display Level Details
			m_bShowLevelDetails = !m_bShowLevelDetails;
			break;

		default:
			ProcessLevelKey(nKey, a, b);
		}
		break;
	
	case GM_FINISH:
		exit(0);
		break;
	}
}

bool Game::Draw()
{
	switch(m_eGameMode)
	{
	case GM_START:
		DrawHUD();
		break;

	case GM_PLAY:
		if (pCurrentLevel && m_pActiveCamera)
		{
			glViewport(0,50, m_nWidth, m_nHeight-50);
			m_pActiveCamera->reshape(m_nWidth, m_nHeight);
			if (pCurrentLevel->IsAcceptingInput() && m_InstructionCache.size()>0)
			{
				pCurrentLevel->ExecuteRobotCommand( m_InstructionCache.front() );
				m_lastCmd = m_InstructionCache.front();
				m_InstructionCache.pop_front();
			}
			else if (pCurrentLevel->IsAcceptingInput())
				m_lastCmd = -1;

			if (m_pActiveCamera == m_pTransCamera)
			{
				if (!m_pActiveCamera->Draw())
				{
					m_pActiveCamera = m_pUserCamera;
					m_pActiveCamera->Draw();
				}
			}
			else
				m_pActiveCamera->Draw();
			
			glViewport(0,0, m_nWidth, 50);
			DrawInstructionCache();

			glViewport(0,0,m_nWidth, m_nHeight);

			if (m_bShowInstructions || m_bShowLevelDetails)
				DrawHUD();

			m_pActiveCamera->reshape(m_nWidth, m_nHeight);
		}
		break;

	case GM_FINISH:
		DrawHUD();
		break;
	}
	return true;
}

bool Game::NextLevel()
{
	m_lastCmd = -1;
	m_InstructionCache.clear();
	if (m_nLevelIndex++ < m_nNumLevels)
	{
		m_bShowLevelDetails = true;
		pCurrentLevel = pLevels[m_nLevelIndex];
		glutPostRedisplay();
	}
	else
	{
		pCurrentLevel = pLevels[m_nLevelIndex=0];
		m_eGameMode = GM_FINISH;
	}

	return true;
}

void Game::ChangeCamera()
{
	bool bIsUserCamera = (	m_pActiveCamera==m_pUserCamera || 
							m_pActiveCamera==m_pTransCamera);
	
	Camera* pOldCamera = m_pActiveCamera;

	m_nUserCamera = (m_nUserCamera+1) % m_nNumCameras;
	m_pUserCamera = m_pvCameras[m_nUserCamera];
	
	//m_nActiveCamera = (m_nActiveCamera+1) % m_nNumCameras;
	//m_pActiveCamera = m_pvCameras[m_nActiveCamera];
	
	if (bIsUserCamera)
	{
		m_pTransCamera->SetCameras(pOldCamera, m_pUserCamera);
		m_pActiveCamera = m_pTransCamera;
		//m_pActiveCamera = m_pUserCamera;
		m_pActiveCamera->reshape(m_nWidth, m_nHeight);
	}
}

void Game::ProcessLevelKey(unsigned char nKey, int a, int b)
{
	eRobotCommand cmd;

	switch( nKey)
	{
	case 'r':
		cmd = ROBCOM_RELEASE;
		break;
	case 'g':
		cmd = ROBCOM_GRASP;
		break;
	
	default:
		return;
	}
	
	m_InstructionCache.push_back(cmd);
}

void Game::special(int key, int x, int y)
{
	LevelProcessSpecialKey(key, x, y);
}

void Game::LevelProcessSpecialKey(int key, int x, int y)
{
	eRobotCommand cmd;


	switch( key )
	{
	case GLUT_KEY_UP:
		cmd = ROBCOM_FORWARD;
		break;
	case GLUT_KEY_DOWN:
		cmd = ROBCOM_BACKWARD;
		break;
	case GLUT_KEY_LEFT:
		cmd = ROBCOM_LEFT;
		break;
	case GLUT_KEY_RIGHT:
		cmd = ROBCOM_RIGHT;
		break;

	case GLUT_KEY_F1:
		m_bShowInstructions = !m_bShowInstructions;
	}

	m_InstructionCache.push_back(cmd);
}

bool Game::SolveLevel()
{
	if (pCurrentLevel)
	{
		const eRobotCommand* soln = pCurrentLevel->GetSolution();

		while (!m_InstructionCache.empty())
			m_InstructionCache.pop_front();

		for (int i=0; i<pCurrentLevel->GetSolutionSteps(); i++)
		{
			m_InstructionCache.push_back( soln[i] );
		}
	}

	return true;
}

void Game::reshape(int x, int y)
{
	m_nWidth = x;
	m_nHeight = y;

	glViewport(0,0,x,y);
	m_pActiveCamera->reshape(x,y-50);
}

void Game::DrawInstructionCache()
{
	glDisable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D( -10, 
				10,
				-1.1,
				1.1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glTranslatef(-9.0,0,0);

	
	pTextureManager->SetCurrentTexture(m_lastCmd);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(-1.0, 1.0);
			
			glTexCoord2f(0.0, 0.0);
			glVertex2f(-1.0, -1.0);

			glTexCoord2f(1.0, 0.0);
			glVertex2f(1.0, -1.0);

			glTexCoord2f(1.0, 1.0);
			glVertex2f(1.0, 1.0);
		glEnd();
		glTranslatef(2.5,0,0);


	list<eRobotCommand>::iterator p;
	
	for ( p = m_InstructionCache.begin(); p != m_InstructionCache.end(); ++p)
	{
		pTextureManager->SetCurrentTexture(*p);
		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(-1.0, 1.0);
			
			glTexCoord2f(0.0, 0.0);
			glVertex2f(-1.0, -1.0);

			glTexCoord2f(1.0, 0.0);
			glVertex2f(1.0, -1.0);

			glTexCoord2f(1.0, 1.0);
			glVertex2f(1.0, 1.0);
		glEnd();
		glTranslatef(2.0,0,0);
	}
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}

void Game::reshape()
{
	reshape(m_nWidth, m_nHeight);
}

void Game::printstring(void *font, const char *string)
{
  int len,i;

  len=(int)strlen(string);
  for(i=0;i<len;i++)
    glutBitmapCharacter(font,string[i]);
}


void Game::DrawInstructions()
{
  glColor4f(0.0,0.0,0.0,0.7);
  glRecti(40,40,600,440);

  glColor3f(1.0,0.0,0.0);
  glRasterPos2i(300,420);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"Instructions");

  glRasterPos2i(60,390);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"F1    - Togle Help");
  glRasterPos2i(60,360);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"Up    - Move Forward");
  glRasterPos2i(60,330);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"Down  - Move Backward");
  glRasterPos2i(60,300);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"Left  - Turn Left");
  glRasterPos2i(60,270);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"Right - Turn Right");
  glRasterPos2i(60,240);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"g     - Grab");
  glRasterPos2i(60,210);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"r     - Release");
  glRasterPos2i(60,180);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"c     - Switch Camera");
}

void Game::DrawHUD()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS );
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_FOG);
	glDisable(GL_LIGHTING);

	// Draw HUD with help/author notice
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.5,639.5,-0.5,479.5,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//displayStatus();

	if (m_bShowInstructions)
		DrawInstructions();
	else
	{
		switch(m_eGameMode)
		{
		case GM_START:
			DrawStartScreen();
			break;

		case GM_PLAY:
			if (m_bShowLevelDetails)
				DrawLevelDetails();
			break;
			
		case GM_FINISH:
			DrawFinishScreen();
			break;
		}
	}
	glPopMatrix();
	glPopAttrib();
}

void Game::DrawStartScreen()
{
  glColor3f(1.0,0.0,0.0);
  glRasterPos2i(30,450);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"RoboRunner v0.2");

  glRasterPos2i(60,390);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"Little Lost Robot...");

  glColor3f(0.4,0.4,1.0);
  glRasterPos2i(60,360);
  printstring(GLUT_BITMAP_HELVETICA_12,"You must help guide 'Robbie' to the red exit square");
  glRasterPos2i(60,330);
  printstring(GLUT_BITMAP_HELVETICA_12,"in order to complete the level.");
  glRasterPos2i(60,300);
  printstring(GLUT_BITMAP_HELVETICA_12,"Robbie is capable of grabbing wooden crates and");
  glRasterPos2i(60,270);
  printstring(GLUT_BITMAP_HELVETICA_12,"moving them out of his way.");
  glRasterPos2i(60,240);
  printstring(GLUT_BITMAP_HELVETICA_12,"He can also activate switches by grabbing them too.");
  glRasterPos2i(60,210);
  printstring(GLUT_BITMAP_HELVETICA_12,"Good Luck!");

  glColor3f(0.4,1.0,0.4);
  glRasterPos2i(60,150);
  printstring(GLUT_BITMAP_HELVETICA_12,"press any key to continue");
}

void Game::DrawFinishScreen()
{

  glColor3f(1.0,0.0,0.0);
  glRasterPos2i(60,390);
  printstring(GLUT_BITMAP_TIMES_ROMAN_24,"CONGRATULATIONS!");

  glColor3f(0.4,0.4,1.0);
  glRasterPos2i(60,360);
  printstring(GLUT_BITMAP_HELVETICA_12,"You've completed the first two levels of");
  glRasterPos2i(60,330);
  printstring(GLUT_BITMAP_HELVETICA_12,"RoboRunner.");
  
  glRasterPos2i(60,270);
  printstring(GLUT_BITMAP_HELVETICA_12,"The full version features:");

  glColor3f(0.8,0.8,0.2);
  glRasterPos2i(60,240);
  printstring(GLUT_BITMAP_HELVETICA_12,"Moving platforms, intricate 3D puzzles and");
  glRasterPos2i(60,210);
  printstring(GLUT_BITMAP_HELVETICA_12,"Llamas.");

  glColor3f(0.4,1.0,0.4);
  glRasterPos2i(60,150);
  printstring(GLUT_BITMAP_HELVETICA_12,"press any key to continue");
}

void Game::DrawLevelDetails()
{
	if (pCurrentLevel)
	{
		glColor4f(0.0,0.0,0.0,0.7);
		glRecti(40,40,600,440);

		glColor3f(1.0,0.0,0.0);
		glRasterPos2i(60,390);
		printstring(GLUT_BITMAP_TIMES_ROMAN_24, pCurrentLevel->GetName());

		
		glColor3f(1.0,1.0,1.0);
		glRasterPos2i(60,340);
		printstring(GLUT_BITMAP_HELVETICA_18,"HINT: ");
		glColor3f(0.4,0.4,1.0);
		glRasterPos2i(90,310);
		printstring(GLUT_BITMAP_HELVETICA_18,pCurrentLevel->GetHint());

		glColor3f(0.4,1.0,0.4);
		glRasterPos2i(60,250);
		printstring(GLUT_BITMAP_HELVETICA_12,"press any key to continue");	
	}
}
