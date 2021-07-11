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

#ifndef _Z_CATextLayer_H_
#define _Z_CATextLayer_H_

#include "CALayer.h"
#include "CoreGraphics.h"
#include "NSString.h"

enum CAAlignmentMode
{
	kCAAlignmentNatural = ::Gdiplus::StringAlignment::StringAlignmentNear,
	kCAAlignmentLeft = ::Gdiplus::StringAlignment::StringAlignmentNear,
	kCAAlignmentCenter = ::Gdiplus::StringAlignment::StringAlignmentCenter,
	kCAAlignmentRight = ::Gdiplus::StringAlignment::StringAlignmentFar,
	//kCAAlignmentJustified,
	/// Z@20210702
	kCAAlignmentVerticalCenter = 0x10,				// combine with one of values above.
};


class CATextLayer : public CALayer
{
public:
	CA_EXTERN virtual ~CATextLayer();
	CA_EXTERN CATextLayer();
	CA_EXTERN virtual void drawInContext(CGContext* ctx);
public:
	typedef CATextLayer this_type;
	typedef CALayer base;

	CA_EXTERN int fontSize();
	CA_EXTERN void setFontSize(int size);
	CA_EXTERN CGFontRef font();
	CA_EXTERN void setFont(CGFontRef font);
	CA_EXTERN void setFont(WCHAR* fontFamily, int fontSize, ::Gdiplus::FontStyle fontStyle = ::Gdiplus::FontStyleRegular);
	CA_EXTERN CGColor& foregroundColor();
	CA_EXTERN void setForegroundColor(const CGColor& color);
	CA_EXTERN void setString(const wchar_t* wstr);
	CA_EXTERN void setString(NSString* str);
	CA_EXTERN int wrapped();
	CA_EXTERN void setWrapped(int wrapped);
	CA_EXTERN int alignmentMode();
	CA_EXTERN void setAlignmentMode(int mode);
	CA_EXTERN int truncationMode();
	CA_EXTERN void setTruncationMode(int trunc);
	CA_EXTERN bool truncationString();
	CA_EXTERN void setTruncationString(bool trunc);

	_0_property_BOOL(isPreferBackingStore,setPreferBackingStore,			/*BOOL,*/	preferBackingStore);
	_0_property_BOOL(isPreferBackingStoreSharp,setPreferBackingStoreSharp,	/*BOOL,*/	preferBackingStoreSharp);
protected:
	CA_EXTERN virtual void makeBackingStore(CGContext* ctx);

protected:
	::Gdiplus::StringFormatFlags _fmtFlags;
	::Gdiplus::StringAlignment _alignment;
	::Gdiplus::Unit	_unit;		// font
	::Gdiplus::FontStyle _fontStyle;		// font
	CGFontRef _font;
	CGColor _foregroundColor;
	NSString* _string;

	::Gdiplus::Bitmap* _backingStore;
};


#endif // _Z_CATextLayer_H_
