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

#ifndef _Z_CGContext_H_
#define _Z_CGContext_H_

// v1 design
//
// matrixes are multiplied by prepend.
//
// a screen is rect in the ms window, is the virtual screen device
// UIWindow should belong to a UIScreen
// ParentMatrix: PM, PM = AM(-1) x MM x AM x OM x PM
// OriginOffsetMatrix: OM, according to the current layer frame origin
// AnchorMatrix: AM, according to the current layer anchorPoint
// ModelMatrix: MM, according to the current layer transform matrix
//
// getCurrentGraphic, means a graphic in dcMem, and transform set to LM x MM x EM x PM
// LM = OM(-1) x AM(-1)
// EM = AM x OM
//
// NSArray of CGContextStates, PM, OM, AM, MM
// CGContext(dcPaint, dcMem, dcCraft, CGRect)
//  orign effects the PM
//  size effects the bounds

#include "CoreGraphics.h"

struct CGContextState
{
	CGAffineTransform _pT; // parentTransform
	CGAffineTransform _oT; // originTranslateTransform
	CGAffineTransform _aT; // anchorTranslateTransform
	CGAffineTransform _mT; // modelTransform
	CGRect _bounds;
	void* _hdcPaint;
	void* _hdcMem;
	void* _hdcCraft;
};

class CALayer;
class CG_EXTERN CGContext : protected CGContextState
{
public:
	~CGContext();
	CGContext(void* hdcPaint, void* hdcMem, void* hdcCraft, CGRect frame);
	CGContext(void* hdcPaint, void* hdcMem, void* hdcCraft, CALayer* layer);
	void enterLayer(CALayer* layer);
	void leaveLayer();
	void* getDcMem() {return _hdcMem;}
	void* getBackingBackgrnd() {return _backingBackground;}
	::Gdiplus::Bitmap* getBackingBackgrndImage();
	void applyGraphics(::Gdiplus::Graphics& g);
	operator ::Gdiplus::Graphics& ();
	operator ::Gdiplus::Pen& ();
	operator ::Gdiplus::SolidBrush& ();
	operator ::Gdiplus::GraphicsPath& ();
	const CGColor& textColor();
	const CGColor& fillColor();
	const CGColor& strokeColor();
	void setTextColor(CGColor&);
	void setFillColor(CGColor&);
	void setStrokeColor(CGColor&);
	void setBackingBackground(void* backing);

	::Gdiplus::Graphics& underlying();
	int underlyingSave();
	void underlyingRestore(int);
private:
	CGContext();
	CGContext(const CGContext&);
	void operator = (const CGContext&);
	void enterSuperLayer(CALayer* layer);
protected:
	void* _stack;
	::Gdiplus::Graphics _g;
	::Gdiplus::Color _textColor;
	::Gdiplus::Color _fillColor;
	::Gdiplus::Color _strokeColor;
	::Gdiplus::Pen _pen;	// stroke, and line attributes
	::Gdiplus::SolidBrush _brush;	// fill
	::Gdiplus::StringFormat _textFormat; //
	::Gdiplus::GraphicsPath _path;
	void* _backingBackground;
	::Gdiplus::Bitmap* _backingBackgrndImage;
};

#endif
