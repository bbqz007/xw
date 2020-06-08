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
#include "CATipsPanelLayer.h"
#include "NSString.h"

CATipsPanelLayer::~CATipsPanelLayer()
{
	if(_textLayer1)
		_textLayer1->release();
	_textLayer1 = NULL;
	if(_textLayer2)
		_textLayer2->release();
	_textLayer2 = NULL;
	if(_textLayer3)
		_textLayer3->release();
	_textLayer3 = NULL;
	if(_textLayer4)
		_textLayer4->release();
	_textLayer4 = NULL;
}

CATipsPanelLayer::CATipsPanelLayer()
{
	_textLayer1 = (CATextLayer*) NSObject::allocT<CATextLayer>();
	_textLayer1->setString(NSString::stringWithCString((LPCSTR)L"×ÖÌå²âÊÔ, scale from 0.5 to 1.f"));
	_textLayer1->setFrame(CGRect(10.f, 70.f, 300.f, 20.f));
	_textLayer1->set_backgroundColor(CGColor(kClearColor));
	_textLayer1->set_borderWidth(0.f);
	_textLayer1->setForegroundColor(CGColor(CGColor::MakeARGB(255, 23, 35, 45)));
	addSublayer(_textLayer1);

	_textLayer2 = (CATextLayer*) NSObject::allocT<CATextLayer>();
	_textLayer2->setString(NSString::stringWithCString((LPCSTR)L"×ÖÌå²âÊÔ, scale from 0.5 to 1.f"));
	_textLayer2->setFrame(CGRect(400.f, 300.f, 300.f, 20.f));
	_textLayer2->set_backgroundColor(CGColor(kClearColor));
	_textLayer2->set_borderWidth(0.f);
	_textLayer2->setForegroundColor(CGColor(CGColor::MakeARGB(255, 23, 35, 45)));
	addSublayer(_textLayer2);

	_textLayer3 = (CATextLayer*) NSObject::allocT<CATextLayer>();
	_textLayer3->setString(NSString::stringWithCString((LPCSTR)L"×ÖÌå²âÊÔ, scale from 0.5 to 1.f"));
	_textLayer3->setFrame(CGRect(400.f, 400.f, 300.f, 20.f));
	_textLayer3->set_backgroundColor(CGColor(kClearColor));
	_textLayer3->set_borderWidth(0.f);
	_textLayer3->setForegroundColor(CGColor(CGColor::MakeARGB(255, 23, 35, 45)));
	addSublayer(_textLayer3);

	_textLayer4 = (CATextLayer*) NSObject::allocT<CATextLayer>();
	_textLayer4->setString(NSString::stringWithCString((LPCSTR)L"×ÖÌå²âÊÔ, scale from 0.5 to 1.f"));
	_textLayer4->setFrame(CGRect(750.f, 380.f, 300.f, 20.f));
	_textLayer4->set_backgroundColor(CGColor(kClearColor));
	_textLayer4->set_borderWidth(0.f);
	_textLayer4->setForegroundColor(CGColor(CGColor::MakeARGB(255, 23, 35, 45)));
	addSublayer(_textLayer4);
}

void CATipsPanelLayer::drawInContext(CGContext* ctx)
{
}

void CATipsPanelLayer::applyAnimating()
{
	LONG _tbase = 0;
	LONG timemark = ::GetMessageTime();
	CGFloat sy = _textLayer1->frame().Y;
	CGFloat sy0 = sy + 100.f;
	// sy0 + v * t - .5 * a * t * t = sy;
	// 100.f = .5 * a * t * t - v * t;
	// 100.f + v * t = .5 * a * t * t;
	// a = (100.f + v * t) / .5 * t * t;
	CGFloat dura = .5f;
	if((timemark % 4000) <= (LONG)(dura * 500))
	{
		CGFloat t = (timemark % 4000) / dura / 1000;
		CGFloat v = 120.f;
		CGFloat a = 750.f;
		CGFloat v0 = v - a * dura;
		CGFloat factor = ((timemark / 4000) & 2) ? -1.f : 1.f;
		_textLayer1->set_opacity(1.f);
		if((timemark / 4000) & 1)
		{
			// go away
			//t = dura - t;
			CGFloat ty = sy - (v0 + a * t) * t - .5f * a * t * t;
			_textLayer1->setTransform(::CGAffineTransformMakeTranslation(0.f, factor * (int)(ty - sy)));
			//::OutputDebugStringW((LPCWSTR)NSString::stringWithFormat(NSString::stringWithCString((const char*)L"- %f, %f, %f\n"), v0, ty, t)->cStringUsingEncoding());
		}
		else
		{
			t = dura - t;
			CGFloat ty = sy - (v0 + a * t) * t - .5f * a * t * t;
			_textLayer1->setTransform(::CGAffineTransformMakeTranslation(0.f, factor * (int)(ty - sy)));
			//::OutputDebugStringW((LPCWSTR)NSString::stringWithFormat(NSString::stringWithCString((const char*)L"+ %f, %f, %f\n"), v0, ty, t)->cStringUsingEncoding());
		}

	}
	else
	{
		if((timemark / 4000) & 1)
		{
			_textLayer1->set_opacity(0.f);
		}
	}

	timemark -= 200;
	//
	//
	//
	if((timemark % 4000) <= (LONG)(dura * 500))
	{
		CGFloat sy = _textLayer2->frame().Y;
		CGFloat sy0 = sy + 100.f;
		CGFloat sx = _textLayer2->frame().X;
		CGFloat tx = sx;
		CGFloat ty = sy;
		CGFloat t = (timemark % 4000) / dura / 1000;
		CGFloat v = 120.f;
		CGFloat a = 750.f;
		CGFloat v0 = v - a * dura;
		CGFloat factor = ((timemark / 4000) & 2) ? -1.f : 1.f;
		_textLayer2->set_opacity(1.f);
		if((timemark / 4000) & 1)
		{
			//t = dura - t;
			ty = sy - (v0 + a * t) * t - .5f * a * t * t;
		}
		else
		{
			t = dura - t;
			ty = sy - (v0 + a * t) * t - .5f * a * t * t;
		}
		t = (timemark % 4000) / dura / 1000;
		v = 220.f;
		a = 750.f;
		v0 = v - a * dura;
		if((timemark / 4000) & 1)
		{
			//t = dura - t;
			tx = sx - (v0 + a * t) * t - .5f * a * t * t;
		}
		else
		{
			t = dura - t;
			tx = sx - (v0 + a * t) * t - .5f * a * t * t;
		}

		_textLayer2->setTransform(::CGAffineTransformMakeTranslation(-(int)(tx - sx), 0.f));
	}
	else
	{
		if((timemark / 4000) & 1)
		{
			_textLayer2->set_opacity(0.f);
		}
	}

	timemark -= 200;
	//
	//
	//
	if((timemark % 4000) <= (LONG)(dura * 500))
	{
		CGFloat sy = _textLayer3->frame().Y;
		CGFloat sy0 = sy + 100.f;
		CGFloat sx = _textLayer3->frame().X;
		CGFloat tx = sx;
		CGFloat ty = sy;
		CGFloat t = (timemark % 4000) / dura / 1000;
		CGFloat v = 120.f;
		CGFloat a = 750.f;
		CGFloat v0 = v - a * dura;
		CGFloat factor = ((timemark / 4000) & 2) ? -1.f : 1.f;
		_textLayer3->set_opacity(1.f);
		if((timemark / 4000) & 1)
		{
			//t = dura - t;
			ty = sy - (v0 + a * t) * t - .5f * a * t * t;
		}
		else
		{
			t = dura - t;
			ty = sy - (v0 + a * t) * t - .5f * a * t * t;
		}
		t = (timemark % 4000) / dura / 1000;
		v = 220.f;
		a = 750.f;
		v0 = v - a * dura;
		if((timemark / 4000) & 1)
		{
			//t = dura - t;
			tx = sx - (v0 + a * t) * t - .5f * a * t * t;
		}
		else
		{
			t = dura - t;
			tx = sx - (v0 + a * t) * t - .5f * a * t * t;
		}

		_textLayer3->setTransform(::CGAffineTransformMakeTranslation(-(int)(tx - sx), -(int)((tx - sx) * (-.55f))));
	}
	else
	{
		if((timemark / 4000) & 1)
		{
			_textLayer3->set_opacity(0.f);
		}
	}

	timemark -= 200;
	//
	//
	//
	if((timemark % 4000) <= (LONG)(dura * 500))
	{
		CGFloat sy = _textLayer4->frame().Y;
		CGFloat sy0 = sy + 100.f;
		CGFloat sx = _textLayer4->frame().X;
		CGFloat tx = sx;
		CGFloat ty = sy;
		CGFloat t = (timemark % 4000) / dura / 1000;
		CGFloat v = 120.f;
		CGFloat a = 950.f;
		CGFloat v0 = v - a * dura;
		CGFloat factor = ((timemark / 4000) & 2) ? -1.f : 1.f;
		_textLayer4->set_opacity(1.f);
		if((timemark / 4000) & 1)
		{
			//t = dura - t;
			ty = sy - (v0 + a * t) * t - .5f * a * t * t;
		}
		else
		{
			t = dura - t;
			ty = sy - (v0 + a * t) * t - .5f * a * t * t;
		}
		t = (timemark % 4000) / dura / 1000;
		v = 220.f;
		a = 750.f;
		v0 = v - a * dura;
		if((timemark / 4000) & 1)
		{
			//t = dura - t;
			tx = sx - (v0 + a * t) * t - .5f * a * t * t;
			_textLayer4->setTransform(::CGAffineTransformMakeTranslation((int)(tx - sx), 0.f));
		}
		else
		{
			t = dura - t;
			tx = sx - (v0 + a * t) * t - .5f * a * t * t;
			_textLayer4->setTransform(::CGAffineTransformMakeTranslation(0.f, -(int)(ty - sy)));
		}


	}
	else
	{
		if((timemark / 4000) & 1)
		{
			_textLayer4->set_opacity(0.f);
		}
	}
}
