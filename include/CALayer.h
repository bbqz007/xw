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

#ifndef _Z_CALayer_H_
#define _Z_CALayer_H_

#include "NSObject.h"
#include "NSArray.h"
#include "CoreGraphics.h"

# pragma warning(push)
# pragma warning(disable:4227)

class CALayer : public NSObject
{
public:
	CA_EXTERN virtual ~CALayer();
	CA_EXTERN CALayer();

	CA_EXTERN void setNeedslayout();
	CA_EXTERN BOOL needsLayout();
	CA_EXTERN void layoutIfNeeded();
	CA_EXTERN virtual void layoutSublayers();

	CA_EXTERN void display(CGContext* ctx);
	CA_EXTERN virtual void drawInContext(CGContext* ctx);
	CA_EXTERN void renderInContext(CGContext* ctx);

	CA_EXTERN void addSublayer(CALayer* layer);
protected:
	CA_EXTERN CGPathRef makeCornerRadiusPath();
private:
	CA_EXTERN virtual void applyAnimating();
#ifdef TEST_WIN32OC2
	_0_property(int, i)
	_0_property(int*, j)
	_0_property_pri_pwi_pti(PUB, k, { return _k; }, PUB, k, { _k = t1; }, PCT, CGRect, k)
	_0_property_retain(NSObject*, o)
#endif
protected:
	_0_property_setter01(setFrame,					CGRect, frame);
	_0_property_setter01(setBounds,					CGRect, bounds);
	_0_property_setter(setAnchorPoint,				CGPoint, anchorPoint);
	_0_property_setter(setZPosition,				CGFloat, zPosition);
	//_0_property_pri_pwi_pti(public:, transform, ;, public:, setTransform, ;, protected:,		CGAffineTransform, transform);
	_0_property_setter(setTransform,				CGAffineTransform, transform);
	_0_property_BOOL(isHidden,setHidden,			/*BOOL,*/	hidden);
	_0_property_assign2(setSuperLayer,				CALayer*, superLayer);
	_0_property_retain2(setSublayers,				NSArray*, sublayers);
	_0_property_retain2(setMask,					CALayer*, mask);			// no impl
	_0_property_BOOL(isMaskToBounds, setMaskToBounds,/*BOOL,*/	maskToBounds);		// no impl
#ifdef CALAYER_IMPL_CONTENTS
	NSObject* _contents;	// no impl
	CGRect _contentRect;
	NSString* _contentsGravity;
	CGFloat _contentScale;
	CGFloat _contentConter;
#endif
	_0_property_getset(isOpaque, setOpaque,			BOOL, opaque);
	_0_property_getter(isNeedsDisplayOnBoundsChange, BOOL, needsDisplayOnBoundsChange);
	_0_property_getter(isDrawsAsynchronously,		BOOL, drawsAsynchronously);	// no impl
	_0_property(CGColor, backgroundColor);
	_0_property_CGFloat(, cornerRadius);
	_0_property_CGFloat(, borderWidth);
	_0_property(CGColor, borderColor);
	_0_property_CGFloat(, opacity);
	_0_property_setter(isAllowsGroupOpacity,		BOOL, allowsGroupOpacity);
	_0_property_retain2(setFilters,					NSArray*, filters);
	_0_property_retain2(setBackgroundFilters,		NSArray*, backgroundFilters);
	_0_property_setter(isShouldRasterize,			BOOL, shouldRasterize);
	_0_property_CGFloat(, rasterizationScale);
	_0_property(CGColor, shadowColor);
	_0_property_CGFloat(, shadowOpacity);
	_0_property_CGFloat(, shadowRadius);
	_0_property_pri_pwi_pti(public:, shadowPath, ;, public:, setShadowPath, ;, protected:,		CGPath, shadowPath);

	_0_property_BOOL(isSmoothBorder,setSmoothBorder,			/*BOOL,*/	smoothBorder);
	_0_property_CGFloat(, smoothBorderWidth);
};

# pragma warning(pop)
#endif
