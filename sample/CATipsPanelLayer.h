/**
MIT License
Copyright (c) 2015 bbqz007 <https://github.com/bbqz007, http://www.cnblogs.com/bbqzsl>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _Z_CATipsPanelLayer_H_
#define _Z_CATipsPanelLayer_H_

#include "CARootLayer.h"
#include "CATextLayer.h"

/// classes
///  CATipsPanelLayer : show four floating text.
///    one text on the left-top.
///    other three in the center.

/// overwrite: virtual CALayer::applyAnimating();

class CATipsPanelLayer : public CALayer
{
public:
	virtual ~CATipsPanelLayer();
	CATipsPanelLayer();
	virtual void drawInContext(CGContext* ctx);
private:
	virtual void applyAnimating();
public:
	typedef CATipsPanelLayer this_type;
	typedef CALayer base;
private:
	CATextLayer* _textLayer1;
	CATextLayer* _textLayer2;
	CATextLayer* _textLayer3;
	CATextLayer* _textLayer4;
};

#endif // _Z_CATipsPanelLayer_H_
