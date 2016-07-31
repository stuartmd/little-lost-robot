// SOWater_StraightCrated.cpp: implementation of the SOWater_StraightCrated class.
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

#include "SOWater_StraightCrated.h"
#include "SimpleCrate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SOWater_StraightCrated::SOWater_StraightCrated()
{
    m_bAniInit = false;
    m_bObstacle = false;
    m_bStatic = false;
}

SOWater_StraightCrated::~SOWater_StraightCrated()
{

}

void SOWater_StraightCrated::Draw()
{
    SOWater_Straight::Draw();
    if (m_bAniInit) {
        glTranslatef(0, 0, 4.0 * ((15.0 - m_nAniStep) / 15.0));
        if (++m_nAniStep == 15) {
            m_bAniInit = false;
            m_bObstacle = false;
        }
    }
    SimpleCrate::DrawObject();

}

void SOWater_StraightCrated::InitAnimation()
{
    m_bAniInit = true;
    m_nAniStep = 0.0;
    m_bObstacle = true;
}
