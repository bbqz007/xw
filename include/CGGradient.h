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

#include "CoreGraphics.h"
#include <vector>

typedef uintptr_t CGColorSpaceRef;

#define CGColorSpaceCreateDeviceRGB() (0)

typedef CGColor* CGColorArrayRef;
typedef ::Gdiplus::LinearGradientBrush CGLinearGradient;
typedef ::Gdiplus::PathGradientBrush CGRadialGradient;

enum CGGradientDrawingOptions
{
	kCGGradientDrawsBeforeStartLocation = (1 << 0),
	kCGGradientDrawsAfterStartLocation = (1 << 1)
};

class CGGradient
{
public:
	CGGradient(CGColorArrayRef colors, const CGFloat *locations, size_t count)
	{
		_colors.reserve(count);
		_colors.assign(colors, colors + count);
		if (!locations)
		{
			_locations.clear();
			_locations.push_back(0.f);
			_locations.push_back(1.f);
		}
		else
		{
			_locations.reserve(count);
			_locations.assign(locations, locations + count);
		}
	}
	std::vector<CGColor> _colors;
	std::vector<CGFloat> _locations;
};

typedef CGGradient* CGGradientRef;
typedef CGLinearGradient* CGLinearGradientRef;
typedef CGRadialGradient* CGRadialGradientRef;

CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef space, CGColorArrayRef colors, const CGFloat *locations);


#endif // _Z_CGGradient_H_