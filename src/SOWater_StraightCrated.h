// SOWater_StraightCrated.h: interface for the SOWater_StraightCrated class.
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

#if !defined(AFX_SOWATER_STRAIGHTCRATED_H__45FD1A61_2D17_11D4_95D9_60AA51C19A15__INCLUDED_)
#define AFX_SOWATER_STRAIGHTCRATED_H__45FD1A61_2D17_11D4_95D9_60AA51C19A15__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SOWater_Straight.h"

class SOWater_StraightCrated : public SOWater_Straight  
{
public:
	virtual void InitAnimation();
	virtual void Draw();
	SOWater_StraightCrated();
	virtual ~SOWater_StraightCrated();

protected:
	float	m_nAniStep;
	bool	m_bAniInit;
};

#endif // !defined(AFX_SOWATER_STRAIGHTCRATED_H__45FD1A61_2D17_11D4_95D9_60AA51C19A15__INCLUDED_)
