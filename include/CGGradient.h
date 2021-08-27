/**
MIT License
Copyright (c) 2015 - 2021 bbqz007 <https://github.com/bbqz007, http://www.cnblogs.com/bbqzsl>
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

#ifndef _Z_CGGradient_H_
#define  _Z_CGGradient_H_

#include "CGBase.h"
#include "CGColor.h"

typedef uintptr_t CGColorSpaceRef;

#define CGColorSpaceCreateDeviceRGB() (0)

typedef CGColor* CGColorArrayRef;

enum CGGradientDrawingOptions
{
	kCGGradientDrawsBeforeStartLocation = (1 << 0),
	kCGGradientDrawsAfterStartLocation = (1 << 1)
};

typedef ::Gdiplus::LinearGradientBrush CGLinearGradient;
typedef ::Gdiplus::PathGradientBrush CGRadialGradient;

//// CGCradient is a lite object for function scope.
//// if you have more than 4 colors, use CGGradientCreateWithColors() to create a large object.
////  and do not forget use CGGradientRelease() to delete this object.
//// CoreGraphics objects are not NSObject, they are not managed by refcount.

class CGGradient;
typedef CGGradient* CGGradientRef;
class CGGradient
{
public:
	virtual ~CGGradient()
	{
		_count = 0;
	}
	CGGradient(CGColorArrayRef colors, const CGFloat *locations, size_t count)
	{
		_count = min(4, count);
		switch (count)
		{
		case 1:
			_colors[0] = colors[0];
			_locations[0] = 1.f;
			break;
		case 2:
			_colors[0] = colors[0];
			_colors[1] = colors[1];
			_locations[0] = 0.f;
			_locations[1] = 1.f;
			break;
		case 3:
			_colors[0] = colors[0];
			_colors[1] = colors[1];
			_locations[0] = locations[0];
			_locations[1] = locations[1];
			_colors[2] = colors[2];
			_locations[2] = locations[2];
			break;
		case 4:
			_colors[0] = colors[0];
			_colors[1] = colors[1];
			_locations[0] = locations[0];
			_locations[1] = locations[1];
			_colors[2] = colors[2];
			_colors[3] = colors[3];
			_locations[2] = locations[2];
			_locations[3] = locations[3];
			break;
		default:
			break;
		}
	}
	CGColor _colors[4];
	CGFloat _locations[4];
protected:
	unsigned int _count;
protected:
	CGGradient();
private:
	CG_EXTERN void(operator delete)(void* in_pVoid);
	CG_EXTERN void* (operator new)(size_t in_size);
	void* (operator new)(size_t in_size, void*);
	void(operator delete[])(void* in_pVoid);	// delete
	void* (operator new[])(size_t in_size);		// delete
	friend CG_EXTERN CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef space, CGColorArrayRef colors, const CGFloat *locations, size_t count);
	friend CG_EXTERN void CGGradientRelease(CGGradientRef gradient);
};

typedef CGLinearGradient* CGLinearGradientRef;
typedef CGRadialGradient* CGRadialGradientRef;

CG_EXTERN CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef space, CGColorArrayRef colors, const CGFloat *locations, size_t count);
CG_EXTERN void CGGradientRelease(CGGradientRef gradient);

#endif // _Z_CGGradient_H_
