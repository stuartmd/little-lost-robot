/* A small OpenGL program which draws a unit square in white on 
   a black background. The main function can be used, with small
   modifications, for most other programs. */

/* First we include the GLUT library. This in turn includes other
   OpenGL libraries, so there is no need to include these separately.
*/

#include <GL/glut.h>
#include <stdio.h>
#include "threed_objects.h"
#include "Game.h"
#include "Level1.h"
#include "TextureManager.h"

/* Initialisation function */

TextureManager*	pTheTextureManager;
Game theGame;


bool bHoldingCrate = false;
int angle=0;

void init(void)
{
   /* specify colour for clearing window; black in this case */
   glClearColor(0.0, 0.0, 0.0, 0.0); 

   /* specify colour for drawing; white in this case */
   glColor3f(1.0, 1.0, 1.0);

   /* Set matrix mode so that we work with projection matrix */
   glMatrixMode(GL_PROJECTION);

   glFrontFace(GL_CCW);
   glCullFace(GL_BACK);
   glEnable(GL_CULL_FACE);

   glEnable(GL_DEPTH_TEST);

   
   /* Set up textures */
	pTheTextureManager->NewTexture(TEX_ROBCOM_FORWARD, "ROBCOM_FORWARD.tga");
	pTheTextureManager->NewTexture(TEX_ROBCOM_BACKWARD, "ROBCOM_BACKWARD.tga");
	pTheTextureManager->NewTexture(TEX_ROBCOM_LEFT, "ROBCOM_LEFT.tga");
	pTheTextureManager->NewTexture(TEX_ROBCOM_RIGHT, "ROBCOM_RIGHT.tga");
	pTheTextureManager->NewTexture(TEX_ROBCOM_GRASP, "ROBCOM_GRASP.tga");
	pTheTextureManager->NewTexture(TEX_ROBCOM_RELEASE, "ROBCOM_RELEASE.tga");
	
	pTheTextureManager->NewTexture(100, "simple_crate.tga");
	pTheTextureManager->NewTexture(110, "unmovable_crate.tga");
	pTheTextureManager->SetCurrentTexture(-1);
	
}

/* This is the designated display function. All commands which actually
   specify something to be drawn should be in this function, or in 
   function call from this function. */

void display( void )
{
	/* Work with model-view matrix */	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

 	GLfloat light_position[] = { 1.0, 1.0, 2.0, 0.0};
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white_light);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
   

   /* Set model-view matrix to the identity matrix */
	theGame.Draw();

   glFlush();
   glutSwapBuffers();
   glutPostRedisplay();
}

/* Main function, fairly standard for programs using GLUT */

void keyboard( unsigned char nKey, int x, int y)
{
	theGame.keyboard( nKey, x, y);
}

void special(int key, int x, int y)
{
	theGame.special( key, x, y);
}

void reshape(int w, int h)
{
	theGame.reshape( w, h);
}

int main(int argc, char** argv)
{
   /* GLUT initialisation function */
   glutInit(&argc,argv);

   /* Use single buffer, and colours specified by giving
      red, green and blue intensities */
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

   /* Set window width and height in pixels */
   glutInitWindowSize(450,450);

   /* Set window position */
   glutInitWindowPosition(200,200);

   /* Calls system commands to create the window */
   glutCreateWindow("RoboRunner!");

   /* Call your own initialisation function */
   pTheTextureManager = new TextureManager();
   init();

   /* Specify the display function */
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutReshapeFunc(reshape);

   /* Enter the callback loop */
   glutMainLoop();
   delete pTheTextureManager;
   return 0;
}

