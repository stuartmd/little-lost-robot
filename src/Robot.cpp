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


#include <GL/glut.h>

#include "Robot.h"
#include "threed_objects.h"


Robot::Robot()
{
    m_InteractObjectAngle = 0;
    m_nBodyAngle = m_nTorsoAngle = 0;
    m_nTorsoHeight = 0;
    m_bArmsExtended = false;
}

Robot::~Robot()
{
}

bool Robot::Draw()
{
    glPushMatrix();
    glRotatef(-m_nBodyAngle, 0, 0, 1);
    glPushMatrix();
    DrawTracks();
    glRotatef(-m_nTorsoAngle, 0, 0, 1);
    DrawTorso();
    DrawHead();
    glPopMatrix();
    if (m_pInteractingObject) {
        DrawInteractObject();
    }
    glPopMatrix();

    return false;
}

bool Robot::DrawTracks()
{
    glPushMatrix();
// Left Track
    glTranslatef(-1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    //Top
    glNormal3f(0, 0, 1);
    glColor3f(.8, .0, .0);
    glVertex3f(-0.5, 1.5, 1.0);
    glVertex3f(-0.5, -1.5, 1.0);
    glVertex3f(0.5, -1.5, 1.0);
    glVertex3f(0.5, 1.5, 1.0);

    //Left
    glNormal3f(-1, 0, 0);
    glColor3f(.5, .5, .5);
    glVertex3f(-0.5, 1.5, 1.0);
    glVertex3f(-0.5, 1.0, 0.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(-0.5, -1.5, 1.0);

    //Right
    glNormal3f(1, 0, 0);
    glVertex3f(0.5, -1.5, 1.0);
    glVertex3f(0.5, -1.0, 0.0);
    glVertex3f(0.5, 1.0, 0.0);
    glVertex3f(0.5, 1.5, 1.0);

    //Front
    glNormal3f(0, 1, 0);
    glVertex3f(-0.5, 1.5, 1.0);
    glVertex3f(0.5, 1.5, 1.0);
    glVertex3f(0.5, 1.0, 0.0);
    glVertex3f(-0.5, 1.0, 0.0);

    //Back
    glNormal3f(0, -1, 0);
    glVertex3f(-0.5, -1.5, 1.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.5, 1.0);
    glEnd();


    // -->Right

    glTranslatef(2.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    //Top
    glNormal3f(0, 0, 1);
    glColor3f(.8, .0, .0);
    glVertex3f(-0.5, 1.5, 1.0);
    glVertex3f(-0.5, -1.5, 1.0);
    glVertex3f(0.5, -1.5, 1.0);
    glVertex3f(0.5, 1.5, 1.0);

    //Left
    glNormal3f(-1, 0, 0);
    glColor3f(.5, .5, .5);
    glVertex3f(-0.5, 1.5, 1.0);
    glVertex3f(-0.5, 1.0, 0.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(-0.5, -1.5, 1.0);

    //Right
    glNormal3f(1, 0, 0);
    glVertex3f(0.5, -1.5, 1.0);
    glVertex3f(0.5, -1.0, 0.0);
    glVertex3f(0.5, 1.0, 0.0);
    glVertex3f(0.5, 1.5, 1.0);

    //Front
    glNormal3f(0, 1, 0);
    glVertex3f(-0.5, 1.5, 1.0);
    glVertex3f(0.5, 1.5, 1.0);
    glVertex3f(0.5, 1.0, 0.0);
    glVertex3f(-0.5, 1.0, 0.0);

    //Back
    glNormal3f(0, -1, 0);
    glVertex3f(-0.5, -1.5, 1.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.0, 0.0);
    glVertex3f(0.5, -1.5, 1.0);
    glEnd();
    glPopMatrix();

// Draw Axle
    glTranslatef(0.0, 0.0, 0.5);
    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_QUADS);

    // Top
    glNormal3f(0, 0, 1);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);

    // Front
    glNormal3f(0, 1, 0);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    // Back
    glNormal3f(0, -1, 0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.5);

    glEnd();
    glTranslatef(0.0, 0.0, 0.5);

    return false;
}

bool Robot::DrawTorso()
{
    glRotatef(-m_nTorsoAngle, 0, 1, 0);
    float fRadius = 0.4;

// Draw Telescopic abdomen
    GLUquadricObj* pObj;
    pObj = gluNewQuadric();

    glColor3f(0.6, 0.6, 0.8);
    for (int i = 0; i < (m_nTorsoHeight * 4 + 1); i++) {
        gluCylinder(pObj, fRadius, fRadius, 1.0, 16, 1);
        glTranslatef(0.0, 0.0, 1.0);
        gluDisk(pObj, fRadius - 0.025, fRadius, 16, 1);
        fRadius -= 0.025;

    }
    gluDeleteQuadric(pObj);


// Draw Chest
    glColor3f(0.0, 0.0, 0.7);
    glBegin(GL_QUADS);
    //Front
    glVertex3f(1.0, 1.0, 2.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(-1.0, 0.5, 0.0);
    glVertex3f(-1.0, 1.0, 2.0);
    //Back
    glNormal3f(0, -1, 0);
    glVertex3f(1.0, -0.5, 2.0);
    glVertex3f(-1.0, -0.5, 2.0);
    glVertex3f(-1.0, -0.5, 0.0);
    glVertex3f(1.0, -0.5, 0.0);
    // Left
    glNormal3f(-1, 0, 0);
    glVertex3f(-1.0, -0.5, 2.0);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, 0.5, 0.0);
    glVertex3f(-1.0, -0.5, 0.0);
    // Right
    glNormal3f(1, 0, 0);
    glVertex3f(1.0, 1.0, 2.0);
    glVertex3f(1.0, -0.5, 2.0);
    glVertex3f(1.0, -0.5, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    //Top
    glNormal3f(0, 0, 1);
    glVertex3f(1.0, 1.0, 2.0);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, -0.5, 2.0);
    glVertex3f(1.0, -0.5, 2.0);
    // Bottom
    glEnd();

    glPushMatrix();
    glTranslatef(-1.0, 0.0, 1.5);
    glRotatef(90, 0, -1, 0);
    DrawArm();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1.0, 0.0, 1.5);
    glRotatef(90, 0, -1, 0);
    glScalef(1.0, 1.0, -1.0);
    glCullFace(GL_FRONT);
    DrawArm();
    glCullFace(GL_BACK);
    glPopMatrix();
    glTranslatef(0.0, 0.0, 2.0);
    return false;
}

bool Robot::DrawArm()
{
// Draws a 'left' arm
    float fShoulderSize = (m_bArmsExtended) ? 1.0 : 0.5;

    GLUquadricObj* pObj;
    pObj = gluNewQuadric();

    glColor3f(0.6, 0.6, 0.8);
    gluCylinder(pObj, 0.35, 0.35, fShoulderSize, 16, 1);


    glTranslatef(0.0, 0.0, fShoulderSize);

    glPushMatrix();
    glTranslatef(-0.65, 0, 0);
    globjCuboid(2.1, 0.8, 0.25);

    glTranslatef(-0.75, 0.6, 0);
    globjCuboid(0.6, 0.4, 0.25);

    if (m_bArmsExtended)
        glTranslatef(0.0, 4.0, 0.0);

    glTranslatef(0.0, 0.5, 0);
    glColor3f(1.0, 0.0, 0.0);
    globjCuboid(0.6, 0.6, 0.25);
    glPopMatrix();

    if (m_bArmsExtended) {
        glColor3f(1.0, 0.7, 0.3);
        glTranslatef(-1.5, 0.8, 0.125);
        glRotatef(-90, 1, 0, 0);
        gluCylinder(pObj, 0.075, 0.075, 4.0, 16, 1);
        glTranslatef(0.225, 0.0, 0.0);
        gluCylinder(pObj, 0.075, 0.075, 4.0, 16, 1);
    }


    gluDeleteQuadric(pObj);
    return false;
}

bool Robot::DrawHead()
{
    globjCuboid(1.0, 0.75, 0.5);
    return false;
}

bool Robot::SetInteractObject(RobotInteractObject* pObject, float angle)
{
    m_pInteractingObject = pObject;
    m_InteractObjectAngle = angle;
    return true;
}

void Robot::DrawInteractObject()
{
    glTranslatef(0.0, 5.0, m_nTorsoHeight * 4);
    glRotatef(m_InteractObjectAngle, 0 , 0, 1);
    m_pInteractingObject->Draw();
}

float Robot::GetTorsoHeight()
{
    return m_nTorsoHeight;
}

float Robot::GetInteractObjectAngle()
{
    return m_InteractObjectAngle;
}
