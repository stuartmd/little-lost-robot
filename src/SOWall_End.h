// SOWall_End.h: interface for the SOWall_End class.
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

#if !defined(AFX_SOWALL_END_H__3FF1F900_29BC_11D4_95D9_B0B151C1F816__INCLUDED_)
#define AFX_SOWALL_END_H__3FF1F900_29BC_11D4_95D9_B0B151C1F816__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SONormalSquare.h"

class SOWall_End : public SONormalSquare  
{
public:
	virtual void Draw();
	SOWall_End();
	virtual ~SOWall_End();

};

#endif // !defined(AFX_SOWALL_END_H__3FF1F900_29BC_11D4_95D9_B0B151C1F816__INCLUDED_)
