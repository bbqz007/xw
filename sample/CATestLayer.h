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

#ifndef _Z_CATestLayer_H_
#define _Z_CATestLayer_H_

#include "CALayer.h"
#include "CATextLayer.h"

/// classes:
///  CATestLayer
///  CATestArcAnimaLayer : show a turning arc
///  CATestBoardAnimaLayer : show a board within which two text layer animate.
///  CATestShakeAnimaLayer : show a layer, which shake every 5 seconds.

/// overwrite CALayer::applyAnimating();

class CATestLayer : public CALayer
{
public:
	virtual ~CATestLayer() {}
	CATestLayer();
public:
	typedef CATestLayer this_type;
	typedef CALayer base;
protected:
	virtual void applyAnimating();
	CGRect _frame_start;
	CGRect _frame_end;
	CGAffineTransform _transform_anime[4][2];
	CGPoint _translate0[2];
	CGFloat _rotate1[2];
	CGPoint _scale2[2];
	CGFloat _duration;
};

class CATestArcAnimaLayer : public CALayer
{
public:
	virtual ~CATestArcAnimaLayer() {}
	CATestArcAnimaLayer();
	virtual void drawInContext(CGContext* ctx);
public:
	typedef CATestArcAnimaLayer this_type;
	typedef CALayer base;
protected:
	virtual void applyAnimating();
	CGRect _frame_start;
	CGRect _frame_end;
	CGAffineTransform _transform_anime[4][2];
	CGPoint _translate0[2];
	CGFloat _rotate1[2];
	CGPoint _scale2[2];
	CGFloat _duration;
};

class CATestBoardAnimaLayer : public CALayer
{
public:
	virtual ~CATestBoardAnimaLayer();
	CATestBoardAnimaLayer();
	virtual void drawInContext(CGContext* ctx);
public:
	typedef CATestBoardAnimaLayer this_type;
	typedef CALayer base;
protected:
	virtual void applyAnimating();
private:
	CATextLayer* _textLayer1;
	CATextLayer* _textLayer2;
};


class CATestShakeAnimaLayer : public CALayer
{
public:
	virtual ~CATestShakeAnimaLayer();
	CATestShakeAnimaLayer();
	virtual void drawInContext(CGContext* ctx);
public:
	typedef CATestShakeAnimaLayer this_type;
	typedef CALayer base;
protected:
	virtual void applyAnimating();
private:
};

#endif
