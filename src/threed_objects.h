

#ifndef _THREED_OBJECTS_H
#define _THREED_OBJECTS_H


/*
	globjCuboid
	===========
	Draws a 3D cuboid, with its base at z==0;
*/
void globjCuboid(float fWidth, float fDepth, float fHeight);
void globjBaselessCuboid(float fWidth, float fDepth, float fHeight);
void globjRectangle(float fWidth, float fDepth);


void globjTexCube(float fSize, 
				  int nFaceTop, 
				  int nFaceBottom,
				  int nFaceFront,
				  int nFaceLeft,
				  int nFaceBack,
				  int nFaceRight);

#endif