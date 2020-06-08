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

#ifndef _Z_CoreGraphics_H_
#define _Z_CoreGraphics_H_

#include <Gdiplus.h>
#include "XWExport.h"

#define CG_EXTERN XWEXPORT
#define CG_AVAILABLE_STARTING(mac, ios)

class CGContext;
extern "C" CG_EXTERN ::Gdiplus::ARGB kClearColor;

#ifndef _CGFloat_
#define _CGFloat_
typedef ::Gdiplus::REAL CGFloat;
#endif
typedef ::Gdiplus::SizeF CGSize;
typedef ::Gdiplus::PointF CGPoint;
typedef ::Gdiplus::RectF CGRect;
typedef ::Gdiplus::Color CGColor;
typedef ::Gdiplus::Font CGFont;
typedef ::Gdiplus::GraphicsPath CGPath;
typedef ::Gdiplus::LineJoin CGLineJoin;
typedef ::Gdiplus::LineCap CGLineCap;

typedef CGFont* CGFontRef;
typedef CGPath* CGPathRef;
typedef CGColor* CGColorRef;
typedef CGContext* CGContextRef;
//typedef ::Gdiplus::Matrix CGAffineTransform;

#include "CGAffineTransform.h"
#include "CGContext.h"
#include "CGContext+Func.h"

#define CGRectGetX(rect)		rect.X
#define CGRectGetY(rect)		rect.Y
#define CGRectGetWidth(rect)	rect.Width
#define CGRectGetHeight(rect)	rect.Height
#define CGRectGetTop(rect)		rect.GetTop()
#define CGRectGetLeft(rect)		rect.GetLeft()
#define CGRectGetRight(rect)	rect.GetRight()
#define CGRectGetBottom(rect)	rect.GetBottom()
#define CGRectGetMidX(rect)		((CGRectGetX(rect) + CGRectGetX(rect) + CGRectGetWidth(rect)) / 2)
#define CGRectGetMidY(rect)		((CGRectGetY(rect) + CGRectGetY(rect) + CGRectGetHeight(rect)) / 2)
#define CGRectGetCenter(rect)	CGPoint(CGRectGetMidX(rect), CGRectGetMidY(rect))

#define MATRIX_GETTER_IMPL(t)	\
{ CGFloat m[6]; _##t.GetElements(&m[0]); t1.SetElements(m[0], m[1], m[2], m[3], m[4], m[5]); }

#define MATRIX_SETTER_IMPL(t)	\
{ CGFloat m[6]; t1.GetElements(&m[0]); _##t.SetElements(m[0], m[1], m[2], m[3], m[4], m[5]); }


#endif
