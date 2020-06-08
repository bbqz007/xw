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

#include "stdafx.h"
#include "CATestLayer.h"
#include "CoreGraphics.h"

CATestLayer::CATestLayer()
{
	_translate0[0].X = 0.f; _translate0[0].Y = 0.f;
	_translate0[1].X = 100.f; _translate0[1].Y = 100.f;
	_rotate1[0] = 0.f;
	_rotate1[1] = 720.f;
	_scale2[0].X = 1.f;
	_scale2[1].X = 2.f;
	_scale2[0].Y = 1.f;
	_scale2[1].Y = 2.f;
}

void CATestLayer::applyAnimating()
{
	long timemark = ::GetMessageTime();
	timemark %= 2000;
	CGFloat rate = timemark / 2000.f;
	CGAffineTransform m;
	m = ::CGAffineTransformTranslate(m, (_translate0[1].X - _translate0[0].X) * rate + _translate0[0].X, (_translate0[1].Y - _translate0[0].Y) * rate + _translate0[0].Y);
	m = ::CGAffineTransformRotate(m, (_rotate1[1] - _rotate1[0]) * rate);
	m = ::CGAffineTransformScale(m, (_scale2[1].X - _scale2[0].X) * rate + _scale2[0].X, (_scale2[1].Y - _scale2[0].Y) * rate + _scale2[0].Y);
	self.setTransform(m);
}


////////////////////////////////////////

CATestArcAnimaLayer::CATestArcAnimaLayer()
{
	_translate0[0].X = 0.f; _translate0[0].Y = 0.f;
	_translate0[1].X = 100.f; _translate0[1].Y = 100.f;
	_rotate1[0] = 0.f;
	_rotate1[1] = 720.f;
	_scale2[0].X = 1.f;
	_scale2[1].X = 2.f;
	_scale2[0].Y = 1.f;
	_scale2[1].Y = 2.f;
}

void CATestArcAnimaLayer::applyAnimating()
{
	long timemark = ::GetMessageTime();
	timemark %= 4000;
	CGFloat rate = timemark / 2000.f * ::sin(timemark / 4000.f * 2 * M_PI);
	CGAffineTransform m;
	::CGPoint centerPoint(CGRectGetMidX(_frame), CGRectGetMidY(_frame));
	//m = ::CGAffineTransformTranslate(m, (_translate0[1].X - _translate0[0].X) * rate + _translate0[0].X, (_translate0[1].Y - _translate0[0].Y) * rate + _translate0[0].Y);
	//m = ::CGAffineTransformTranslate(m, centerPoint.X, centerPoint.Y);
	m = ::CGAffineTransformRotate(m, (_rotate1[1] - _rotate1[0]) * rate);
	//m = ::CGAffineTransformTranslate(m, -centerPoint.X, -centerPoint.Y);
	//m = ::CGAffineTransformScale(m, (_scale2[1].X - _scale2[0].X) * rate + _scale2[0].X, (_scale2[1].Y - _scale2[0].Y) * rate + _scale2[0].Y);
	self.setTransform(m);
}

void CATestArcAnimaLayer::drawInContext(CGContext* ctx)
{
	::CGContextSetStrokeColorWithColor(ctx, &CGColor(CGColor::Azure));
	::CGContextSetLineWidth(ctx, 4.);
	::Gdiplus::Graphics& g = (::Gdiplus::Graphics&)*ctx;
	g.DrawArc(&(::Gdiplus::Pen&)*ctx, 0.f, 0.f, CGRectGetWidth(_frame), CGRectGetHeight(_frame), 180.f, 270.f);
}

////////////////////////////////////////
CATestBoardAnimaLayer::CATestBoardAnimaLayer()
{
	_textLayer1 = NSObject::allocT<CATextLayer>();
	_textLayer2 = NSObject::allocT<CATextLayer>();

	_textLayer1->setString(NSString::stringWithCString((LPCSTR)L"×ÖÌå²âÊÔ, scale from 0.5 to 1.f"));
	_textLayer1->setFrame(CGRect(10.f, 10.f, 180.f, 20.f));
	_textLayer1->set_backgroundColor(CGColor(kClearColor));
	_textLayer1->set_borderWidth(0.f);
	_textLayer1->setForegroundColor(CGColor(CGColor::MakeARGB(255, 23, 35, 45)));
	addSublayer(_textLayer1);

	_textLayer2->setString(NSString::stringWithCString((LPCSTR)L"×ÖÌå²âÊÔ, scale from 0.5 to 1.f"));
	_textLayer2->setFrame(CGRect(10.f, 40.f, 180.f, 20.f));
	_textLayer2->set_backgroundColor(CGColor(kClearColor));
	_textLayer2->set_borderWidth(0.f);
	//_textLayer2->setForegroundColor(CGColor(CGColor::MakeARGB(255, 23, 35, 45)));
	_textLayer2->setForegroundColor(CGColor(CGColor::Black));
	addSublayer(_textLayer2);
}

CATestBoardAnimaLayer::~CATestBoardAnimaLayer()
{
	_textLayer1->release();
	_textLayer1 = 0;
	_textLayer2->release();
	_textLayer2 = 0;
}

void CATestBoardAnimaLayer::drawInContext(CGContext* ctx)
{

}

void CATestBoardAnimaLayer::applyAnimating()
{
	LONG _tbase = 0;
	LONG timeout = ::GetMessageTime();
	::Gdiplus::REAL timeline = ((timeout - _tbase) % 2000);
	::Gdiplus::REAL rotate = timeline / 2000 * 720;				// 2 cycles
	::Gdiplus::REAL sx = 1 - 0.8 * sin(M_PI * timeline / 2000);
	::Gdiplus::REAL sy = sx;

	CGRect path2bounds = _frame;
	//path2.GetBounds(&path2bounds);
	CGAffineTransform m2;
	CGAffineTransform m1;
	if(((timeout - _tbase + 1000) / 1000) % 3 == 1)
	{
		{
			m2 = ::CGAffineTransformTranslate(m2, -path2bounds.Width * 0.4 * (1.5 - sx), -path2bounds.Height * 0.4 * (1.5 - sy));
			m2 = ::CGAffineTransformRotate(m2, rotate);
			m2 = ::CGAffineTransformTranslate(m2, path2bounds.Width * 0.4 * (1.5 - sx), path2bounds.Height * 0.4 * (1.5 - sy));
			m2 = ::CGAffineTransformScale(m2, sx, sy);
		}
	}
	m1 = m2;
	self.setTransform(m1);
	if(((timeout - _tbase + 1000) / 1000) % 6 < 2 || ((timeout - _tbase + 1000) / 1000) % 6 > 3)
	{
		//self.set_opacity(1.f);
		self.set_backgroundColor(CGColor(CGColor::Azure));
	}
	else
	{
		//self.set_opacity(0.f);
		self.set_backgroundColor(CGColor(kClearColor));
	}

	if(((timeout - _tbase) / 2000) & 1)
	{
		if((((timeout - _tbase) / 2000) & 3) == 1)
		{
			m1 = ::CGAffineTransformMakeScale(0.5 + ((timeout - _tbase) % 2000)/(double)2000 * (1.f - 0.5), 1.f);
			_textLayer1->setTransform(m1);

			m1 = ::CGAffineTransformMakeScale(0.5 + ((timeout - _tbase) % 2000)/(double)2000 * (1.f - 0.5), 1.f);
			_textLayer2->setTransform(m1);
		}
		else
		{
			m1 = CGAffineTransformMakeScale(1.f, 1.f);
			_textLayer1->setTransform(m1);
			_textLayer2->setTransform(m1);
		}

		_textLayer1->set_opacity(1.f);
		_textLayer2->set_opacity(1.f);
	}
	else
	{
		_textLayer1->set_opacity(0.f);
		_textLayer2->set_opacity(0.f);
	}
}


///////////////////////////////

CATestShakeAnimaLayer::~CATestShakeAnimaLayer()
{
}

CATestShakeAnimaLayer::CATestShakeAnimaLayer()
{
	_backgroundColor = CGColor(kClearColor);
	_borderColor = CGColor(kClearColor);
	_borderWidth = 0.f;
}

void CATestShakeAnimaLayer::drawInContext(CGContext* ctx)
{
}

void CATestShakeAnimaLayer::applyAnimating()
{
	LONG _tbase = 0;
	LONG timemark = ::GetMessageTime();
	if(((timemark / 4000) & 3) == 3
		&& (timemark % 2000) <= 1000)
	{
		static bool left = true;
		left = !left;
		CGAffineTransform m = CGAffineTransformMakeTranslation(50 - (timemark%100), 0.f);
		self.setTransform(m);
		::OutputDebugStringA("a");
	}
	else
	{
		CGAffineTransform m = CGAffineTransformMakeTranslation(0.f, 0.f);
		self.setTransform(m);
	}
}
