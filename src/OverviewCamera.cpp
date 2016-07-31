// OverviewCamera.cpp: implementation of the OverviewCamera class.
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

#include "Game.h"
#include "Level.h"
#include "OverviewCamera.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OverviewCamera::OverviewCamera(Game* pGame) : Camera(pGame)
{

    m_eProjMode = PROJ_PERSP;
    m_FOV = 30.0;
    m_ClipNear = 1.0;
    m_ClipFar = 200.0;
}

OverviewCamera::~OverviewCamera()
{

}

void OverviewCamera::Update()
{
    Level* pLevel = m_pGame->pCurrentLevel;

    if (pLevel != m_pLastLevel) {
        m_pLastLevel = pLevel;
        m_pos[0] = -2.5 + 0.5 * pLevel->GetWidth();
        m_pos[1] = -2.5 + 0.5 * pLevel->GetDepth();
        m_pos[2] = 0.5 * pLevel->GetWidth() / tan(m_FOV * DEG2RAD / 2);
    }
}
