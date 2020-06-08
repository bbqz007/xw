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

#ifndef _Z_CGAffineTransform_H_
#define _Z_CGAffineTransform_H_

#ifndef _CGFloat_
#define _CGFloat_
#include <Gdiplus.h>
typedef ::Gdiplus::REAL CGFloat;
#endif

struct CGAffineTransform {
  CGFloat a, b, c, d;		// m11, m12, m21, m22
  CGFloat tx, ty;			// dx, dy
  CGAffineTransform() {a = 1, b = 0, c = 0, d = 1, tx = 0, ty = 0;}
  CGAffineTransform(CGFloat m11, CGFloat m12, CGFloat m21, CGFloat m22, CGFloat dx, CGFloat dy)
  {a = m11, b = m12, c = m21, d = m22, tx = dx, ty = dy;}
};

CG_EXTERN CGAffineTransform CGAffineTransformMake(CGFloat a, CGFloat b,
  CGFloat c, CGFloat d, CGFloat tx, CGFloat ty);

/* Return a transform which translates by `(tx, ty)':
     t' = [ 1 0 0 1 tx ty ] */

CG_EXTERN CGAffineTransform CGAffineTransformMakeTranslation(CGFloat tx,
  CGFloat ty);

/* Return a transform which scales by `(sx, sy)':
     t' = [ sx 0 0 sy 0 0 ] */

CG_EXTERN CGAffineTransform CGAffineTransformMakeScale(CGFloat sx, CGFloat sy);

/* Return a transform which rotates by `angle' radians:
     t' = [ cos(angle) sin(angle) -sin(angle) cos(angle) 0 0 ] */

CG_EXTERN CGAffineTransform CGAffineTransformMakeRotation(CGFloat angle);

/* Return true if `t1' and `t2' are equal, false otherwise. */

CG_EXTERN bool CGAffineTransformIsIdentity(CGAffineTransform t);	// no impl

/* Translate `t' by `(tx, ty)' and return the result:
     t' = [ 1 0 0 1 tx ty ] * t */

CG_EXTERN CGAffineTransform CGAffineTransformTranslate(CGAffineTransform t,
  CGFloat tx, CGFloat ty);

/* Scale `t' by `(sx, sy)' and return the result:
     t' = [ sx 0 0 sy 0 0 ] * t */

CG_EXTERN CGAffineTransform CGAffineTransformScale(CGAffineTransform t,
  CGFloat sx, CGFloat sy);

/* Rotate `t' by `angle' radians and return the result:
     t' =  [ cos(angle) sin(angle) -sin(angle) cos(angle) 0 0 ] * t */

CG_EXTERN CGAffineTransform CGAffineTransformRotate(CGAffineTransform t,
  CGFloat angle);

/* Invert `t' and return the result. If `t' has zero determinant, then `t'
   is returned unchanged. */

CG_EXTERN CGAffineTransform CGAffineTransformInvert(CGAffineTransform t);

/* Concatenate `t2' to `t1' and return the result:
     t' = t1 * t2 */

CG_EXTERN CGAffineTransform CGAffineTransformConcat(CGAffineTransform t1,
  CGAffineTransform t2);

/* Return true if `t1' and `t2' are equal, false otherwise. */

CG_EXTERN bool CGAffineTransformEqualToTransform(CGAffineTransform t1,
  CGAffineTransform t2);

/* Transform `point' by `t' and return the result:
     p' = p * t
   where p = [ x y 1 ]. */

CG_EXTERN CGPoint CGPointApplyAffineTransform(CGPoint point,
  CGAffineTransform t);

/* Transform `size' by `t' and return the result:
     s' = s * t
   where s = [ width height 0 ]. */

CG_EXTERN CGSize CGSizeApplyAffineTransform(CGSize size, CGAffineTransform t);

CG_EXTERN BOOL operator != (const CGAffineTransform& l, const CGAffineTransform& r);

CG_EXTERN void GCMatrixContextClear();
#endif
