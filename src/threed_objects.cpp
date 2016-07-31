
#include <GL/glut.h>
#include "threed_objects.h"

/*
    globjCuboid
    ===========
    Draws a 3D cuboid, with its base at z==0;
*/
void globjCuboid(float fWidth, float fDepth, float fHeight)
{
    float fHalfWidth = fWidth / 2;
    float fHalfDepth = fDepth / 2;

    glBegin(GL_QUADS);
    // bottom
    glNormal3f(0, 0, -1);
    glVertex3f(-fHalfWidth, fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(-fHalfWidth, -fHalfDepth, 0.0);
    // top
    glNormal3f(0, 0, 1);
    glVertex3f(-fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(-fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, fHalfDepth, fHeight);
    // left
    glNormal3f(-1, 0, 0);
    glVertex3f(-fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(-fHalfWidth, fHalfDepth, 0.0);
    glVertex3f(-fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(-fHalfWidth, -fHalfDepth, fHeight);
    // front
    glNormal3f(0, 1, 0);
    glVertex3f(-fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, fHalfDepth, 0.0);
    glVertex3f(-fHalfWidth, fHalfDepth, 0.0);
    // right
    glNormal3f(1, 0, 0);
    glVertex3f(fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, fHalfDepth, 0.0);
    // back
    glNormal3f(0, -1, 0);
    glVertex3f(-fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(-fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, -fHalfDepth, fHeight);
    glEnd();
}


/*
    globjCuboid
    ===========
    Draws a 3D cuboid, with its base at z==0;
*/
void globjTexCube(float fSize,
                  int nFaceTop = 0,
                  int nFaceBottom = 1,
                  int nFaceFront = 2,
                  int nFaceLeft = 3,
                  int nFaceBack = 4,
                  int nFaceRight = 5)
{
    float fHalfSize = fSize / 2.0;
    double xStep = 1.0 / 8.0;
    glBegin(GL_QUADS);
    // bottom
    glNormal3f(0, 0, -1);

    glTexCoord2f(xStep * nFaceBottom,
                 0.0);

    glVertex3f(-fHalfSize, fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceBottom + 1), 0.0);

    glVertex3f(fHalfSize, fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceBottom + 1), 1.0);

    glVertex3f(fHalfSize, -fHalfSize, 0.0);

    glTexCoord2f(xStep * nFaceBottom, 1.0);

    glVertex3f(-fHalfSize, -fHalfSize, 0.0);

    // top
    glNormal3f(0, 0, 1);

    glTexCoord2f(xStep * nFaceTop, 1.0);
    glVertex3f(-fHalfSize, fHalfSize, fSize);

    glTexCoord2f(xStep * nFaceTop, 0.0);
    glVertex3f(-fHalfSize, -fHalfSize, fSize);

    glTexCoord2f(xStep * (nFaceTop + 1), 0.0);
    glVertex3f(fHalfSize, -fHalfSize, fSize);

    glTexCoord2f(xStep * (nFaceTop + 1), 1.0);
    glVertex3f(fHalfSize, fHalfSize, fSize);

    // left
    glNormal3f(-1, 0, 0);
    glTexCoord2f(xStep * nFaceLeft, 1.0);
    glVertex3f(-fHalfSize, fHalfSize, fSize);

    glTexCoord2f(xStep * nFaceLeft, 0.0);
    glVertex3f(-fHalfSize, fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceLeft + 1), 0.0);
    glVertex3f(-fHalfSize, -fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceLeft + 1), 1.0);
    glVertex3f(-fHalfSize, -fHalfSize, fSize);

    // front
    glNormal3f(0, 1, 0);
    glTexCoord2f(xStep * (nFaceFront + 1), 1.0);
    glVertex3f(-fHalfSize, fHalfSize, fSize);

    glTexCoord2f(xStep * nFaceFront, 1.0);
    glVertex3f(fHalfSize, fHalfSize, fSize);

    glTexCoord2f(xStep * nFaceFront, 0.0);
    glVertex3f(fHalfSize, fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceFront + 1), 0.0);
    glVertex3f(-fHalfSize, fHalfSize, 0.0);

    // right
    glNormal3f(1, 0, 0);
    glTexCoord2f(xStep * (nFaceRight + 1), 1.0);
    glVertex3f(fHalfSize, fHalfSize, fSize);

    glTexCoord2f(xStep * nFaceRight, 1.0);
    glVertex3f(fHalfSize, -fHalfSize, fSize);

    glTexCoord2f(xStep * nFaceRight, 0.0);
    glVertex3f(fHalfSize, -fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceRight + 1), 0.0);
    glVertex3f(fHalfSize, fHalfSize, 0.0);

    // back
    glNormal3f(0, -1, 0);
    glTexCoord2f(xStep * nFaceBack, 1.0);
    glVertex3f(-fHalfSize, -fHalfSize, fSize);

    glTexCoord2f(xStep * nFaceBack, 0.0);
    glVertex3f(-fHalfSize, -fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceBack + 1), 0.0);
    glVertex3f(fHalfSize, -fHalfSize, 0.0);

    glTexCoord2f(xStep * (nFaceBack + 1), 1.0);
    glVertex3f(fHalfSize, -fHalfSize, fSize);
    glEnd();
}


void globjBaselessCuboid(float fWidth, float fDepth, float fHeight)
{
    float fHalfWidth = fWidth / 2;
    float fHalfDepth = fDepth / 2;

    glBegin(GL_QUADS);
    // top
    glNormal3f(0, 0, 1);
    glVertex3f(-fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(-fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, fHalfDepth, fHeight);
    // left
    glNormal3f(-1, 0, 0);
    glVertex3f(-fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(-fHalfWidth, fHalfDepth, 0.0);
    glVertex3f(-fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(-fHalfWidth, -fHalfDepth, fHeight);
    // front
    glNormal3f(0, 1, 0);
    glVertex3f(-fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, fHalfDepth, 0.0);
    glVertex3f(-fHalfWidth, fHalfDepth, 0.0);
    // right
    glNormal3f(1, 0, 0);
    glVertex3f(fHalfWidth, fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, fHalfDepth, 0.0);
    // back
    glNormal3f(0, -1, 0);
    glVertex3f(-fHalfWidth, -fHalfDepth, fHeight);
    glVertex3f(-fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, -fHalfDepth, 0.0);
    glVertex3f(fHalfWidth, -fHalfDepth, fHeight);
    glEnd();
}

void globjRectangle(float fWidth, float fDepth)
{
    float fHalfWidth = fWidth / 2;
    float fHalfDepth = fDepth / 2;


    glBegin(GL_QUADS);
    // top
    glNormal3f(0.0, 0.0, 1.0);
    glVertex2f(-fHalfWidth, fHalfDepth);
    glVertex2f(-fHalfWidth, -fHalfDepth);
    glVertex2f(fHalfWidth, -fHalfDepth);
    glVertex2f(fHalfWidth, fHalfDepth);
    glEnd();
}
