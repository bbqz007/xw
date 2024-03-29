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

#ifndef _Z_CGContext_Func_H_
#define _Z_CGContext_Func_H_

#include "CGContext.h"
#include "CGGradient.h"

/** Graphics state functions. **/

/* Push a copy of the current graphics state onto the graphics state stack.
   Note that the path is not considered part of the graphics state, and is
   not saved. */

CG_EXTERN void CGContextSaveGState(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Restore the current graphics state from the one on the top of the
   graphics state stack, popping the graphics state stack in the process. */

CG_EXTERN void CGContextRestoreGState(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Coordinate space transformations. **/

/* Scale the current graphics state's transformation matrix (the CTM) by
   `(sx, sy)'. */

CG_EXTERN void CGContextScaleCTM(CGContextRef c, CGFloat sx, CGFloat sy)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Translate the current graphics state's transformation matrix (the CTM) by
   `(tx, ty)'. */

CG_EXTERN void CGContextTranslateCTM(CGContextRef c, CGFloat tx, CGFloat ty)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Rotate the current graphics state's transformation matrix (the CTM) by
   `angle' radians. */

CG_EXTERN void CGContextRotateCTM(CGContextRef c, CGFloat angle)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Concatenate the current graphics state's transformation matrix (the CTM)
   with the affine transform `transform'. */

CG_EXTERN void CGContextConcatCTM(CGContextRef c, CGAffineTransform transform)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the current graphics state's transformation matrix. */

CG_EXTERN CGAffineTransform CGContextGetCTM(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Drawing attribute functions. **/

/* Set the line width in the current graphics state to `width'. */

CG_EXTERN void CGContextSetLineWidth(CGContextRef c, CGFloat width)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the line cap in the current graphics state to `cap'. */

CG_EXTERN void CGContextSetLineCap(CGContextRef c, CGLineCap cap)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the line join in the current graphics state to `join'. */

CG_EXTERN void CGContextSetLineJoin(CGContextRef c, CGLineJoin join)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the miter limit in the current graphics state to `limit'. */

CG_EXTERN void CGContextSetMiterLimit(CGContextRef c, CGFloat limit)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the line dash patttern in the current graphics state of `c'. */

CG_EXTERN void CGContextSetLineDash(CGContextRef c, CGFloat phase,
  const CGFloat lengths[], size_t count)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the path flatness parameter in the current graphics state of `c' to
   `flatness'. */

CG_EXTERN void CGContextSetFlatness(CGContextRef c, CGFloat flatness)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the alpha value in the current graphics state of `c' to `alpha'. */

CG_EXTERN void CGContextSetAlpha(CGContextRef c, CGFloat alpha)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#if 0
/* Set the blend mode of `context' to `mode'. */

CG_EXTERN void CGContextSetBlendMode(CGContextRef context, CGBlendMode mode)
  CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);
#endif
/** Path construction functions. **/

/* Note that a context has a single path in use at any time: a path is not
   part of the graphics state. */

/* Begin a new path. The old path is discarded. */

CG_EXTERN void CGContextBeginPath(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Start a new subpath at point `(x, y)' in the context's path. */

CG_EXTERN void CGContextMoveToPoint(CGContextRef c, CGFloat x, CGFloat y)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Append a straight line segment from the current point to `(x, y)'. */

CG_EXTERN void CGContextAddLineToPoint(CGContextRef c, CGFloat x, CGFloat y)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Append a cubic Bezier curve from the current point to `(x,y)', with
   control points `(cp1x, cp1y)' and `(cp2x, cp2y)'. */

CG_EXTERN void CGContextAddCurveToPoint(CGContextRef c, CGFloat cp1x,
  CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Append a quadratic curve from the current point to `(x, y)', with control
   point `(cpx, cpy)'. */

CG_EXTERN void CGContextAddQuadCurveToPoint(CGContextRef c, CGFloat cpx,
  CGFloat cpy, CGFloat x, CGFloat y)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Close the current subpath of the context's path. */

CG_EXTERN void CGContextClosePath(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Path construction convenience functions. **/

/* Add a single rect to the context's path. */

CG_EXTERN void CGContextAddRect(CGContextRef c, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add a set of rects to the context's path. */

CG_EXTERN void CGContextAddRects(CGContextRef c, const CGRect rects[],
  size_t count) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add a set of lines to the context's path. */

CG_EXTERN void CGContextAddLines(CGContextRef c, const CGPoint points[],
  size_t count) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add an ellipse inside `rect' to the current path of `context'. See the
   function `CGPathAddEllipseInRect' for more information on how the path
   for the ellipse is constructed. */

CG_EXTERN void CGContextAddEllipseInRect(CGContextRef context, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Add an arc of a circle to the context's path, possibly preceded by a
   straight line segment. `(x, y)' is the center of the arc; `radius' is its
   radius; `startAngle' is the angle to the first endpoint of the arc;
   `endAngle' is the angle to the second endpoint of the arc; and
   `clockwise' is 1 if the arc is to be drawn clockwise, 0 otherwise.
   `startAngle' and `endAngle' are measured in radians. */

CG_EXTERN void CGContextAddArc(CGContextRef c, CGFloat x, CGFloat y,
  CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add an arc of a circle to the context's path, possibly preceded by a
   straight line segment. `radius' is the radius of the arc. The arc is
   tangent to the line from the current point to `(x1, y1)', and the line
   from `(x1, y1)' to `(x2, y2)'. */

CG_EXTERN void CGContextAddArcToPoint(CGContextRef c, CGFloat x1, CGFloat y1,
  CGFloat x2, CGFloat y2, CGFloat radius)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add `path' to the path of context. The points in `path' are transformed
   by the CTM of context before they are added. */

CG_EXTERN void CGContextAddPath(CGContextRef context, CGPathRef path)
  CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);

/** Path stroking. **/
#if 0
/* Replace the path in `context' with the stroked version of the path, using
   the parameters of `context' to calculate the stroked path. The resulting
   path is created such that filling it with the appropriate color will
   produce the same results as stroking the original path. You can use this
   path in the same way you can use the path of any context; for example,
   you can clip to the stroked version of a path by calling this function
   followed by a call to "CGContextClip". */

CG_EXTERN void CGContextReplacePathWithStrokedPath(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);
#endif
/** Path information functions. **/

/* Return true if the path of `context' contains no elements, false
   otherwise. */

CG_EXTERN bool CGContextIsPathEmpty(CGContextRef context)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the current point of the current subpath of the path of
   `context'. */

CG_EXTERN CGPoint CGContextGetPathCurrentPoint(CGContextRef context)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the bounding box of the path of `context'. The bounding box is the
   smallest rectangle completely enclosing all points in the path, including
   control points for Bezier and quadratic curves. */

CG_EXTERN CGRect CGContextGetPathBoundingBox(CGContextRef context)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return a copy of the path of `context'. The returned path is specified in
   the current user space of `context'. */

CG_EXTERN CGPathRef CGContextCopyPath(CGContextRef context)
  CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);
#if 0
/* Return true if `point' is contained in the current path of `context'. A
   point is contained within a context's path if it is inside the painted
   region when the path is stroked or filled with opaque colors using the
   path drawing mode `mode'. `point' is specified is user space. */

CG_EXTERN bool CGContextPathContainsPoint(CGContextRef context, CGPoint point,
  CGPathDrawingMode mode) CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Path drawing functions. **/

/* Draw the context's path using drawing mode `mode'. */

CG_EXTERN void CGContextDrawPath(CGContextRef c, CGPathDrawingMode mode)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/** Path drawing convenience functions. **/

/* Fill the context's path using the winding-number fill rule. Any open
   subpath of the path is implicitly closed. */

CG_EXTERN void CGContextFillPath(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill the context's path using the even-odd fill rule. Any open subpath of
   the path is implicitly closed. */

CG_EXTERN void CGContextEOFillPath(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Stroke the context's path. */

CG_EXTERN void CGContextStrokePath(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill `rect' with the current fill color. */

CG_EXTERN void CGContextFillRect(CGContextRef c, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill `rects', an array of `count' CGRects, with the current fill
   color. */

CG_EXTERN void CGContextFillRects(CGContextRef c, const CGRect rects[],
  size_t count) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Stroke `rect' with the current stroke color and the current linewidth. */

CG_EXTERN void CGContextStrokeRect(CGContextRef c, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Stroke `rect' with the current stroke color, using `width' as the the
   line width. */

CG_EXTERN void CGContextStrokeRectWithWidth(CGContextRef c, CGRect rect,
  CGFloat width) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Clear `rect' (that is, set the region within the rect to transparent). */

CG_EXTERN void CGContextClearRect(CGContextRef c, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Fill an ellipse (an oval) inside `rect'. */

CG_EXTERN void CGContextFillEllipseInRect(CGContextRef context, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Stroke an ellipse (an oval) inside `rect'. */

CG_EXTERN void CGContextStrokeEllipseInRect(CGContextRef context, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/* Stroke a sequence of line segments one after another in `context'. The
   line segments are specified by `points', an array of `count' CGPoints.
   This function is equivalent to

     CGContextBeginPath(context);
     for (k = 0; k < count; k += 2) {
       CGContextMoveToPoint(context, s[k].x, s[k].y);
       CGContextAddLineToPoint(context, s[k+1].x, s[k+1].y);
     }
     CGContextStrokePath(context); */

CG_EXTERN void CGContextStrokeLineSegments(CGContextRef c,
  const CGPoint points[], size_t count)
  CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);

/** Clipping functions. **/

/* Intersect the context's path with the current clip path and use the
   resulting path as the clip path for subsequent rendering operations. Use
   the winding-number fill rule for deciding what's inside the path. */

CG_EXTERN void CGContextClip(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#if 0
/* Intersect the context's path with the current clip path and use the
   resulting path as the clip path for subsequent rendering operations. Use
   the even-odd fill rule for deciding what's inside the path. */

CG_EXTERN void CGContextEOClip(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Add `mask' transformed to `rect' to the clipping area of `context'. The
   mask, which may be either an image mask or an image, is mapped into the
   specified rectangle and intersected with the current clipping area of the
   context.

   If `mask' is an image mask, then it clips in a manner identical to the
   behavior if it were used with "CGContextDrawImage": it indicates an area
   to be masked out (left unchanged) when drawing. The source samples of the
   image mask determine which points of the clipping area are changed,
   acting as an "inverse alpha": if the value of a source sample in the
   image mask is S, then the corresponding point in the current clipping
   area will be multiplied by an alpha of (1-S). (For example, if S is 1,
   then the point in the clipping area becomes clear, while if S is 0, the
   point in the clipping area is unchanged.

   If `mask' is an image, then it serves as alpha mask and is blended with
   the current clipping area. The source samples of mask determine which
   points of the clipping area are changed: if the value of the source
   sample in mask is S, then the corresponding point in the current clipping
   area will be multiplied by an alpha of S. (For example, if S is 0, then
   the point in the clipping area becomes clear, while if S is 1, the point
   in the clipping area is unchanged.

   If `mask' is an image, then it must be in the DeviceGray color space, may
   not have alpha, and may not be masked by an image mask or masking
   color. */

CG_EXTERN void CGContextClipToMask(CGContextRef c, CGRect rect,
  CGImageRef mask) CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);
#endif
/* Return the bounding box of the clip path of `c' in user space. The
   bounding box is the smallest rectangle completely enclosing all points in
   the clip. */

CG_EXTERN CGRect CGContextGetClipBoundingBox(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** Clipping convenience functions. **/

/* Intersect the current clipping path with `rect'. Note that this function
   resets the context's path to the empty path. */

CG_EXTERN void CGContextClipToRect(CGContextRef c, CGRect rect)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Intersect the current clipping path with the clipping region formed by
   creating a path consisting of all rects in `rects'. Note that this
   function resets the context's path to the empty path. */

CG_EXTERN void CGContextClipToRects(CGContextRef c, const CGRect rects[],
  size_t count) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Primitive color functions. **/

/* Set the current fill color in the context `c' to `color'. */

CG_EXTERN void CGContextSetFillColorWithColor(CGContextRef c, CGColorRef color)
  CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/* Set the current stroke color in the context `c' to `color'. */

CG_EXTERN void CGContextSetStrokeColorWithColor(CGContextRef c,
  CGColorRef color) CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** Color space functions. **/
#if 0
/* Set the current fill color space in `context' to `space'. As a
   side-effect, set the fill color to a default value appropriate for the
   color space. */

CG_EXTERN void CGContextSetFillColorSpace(CGContextRef context,
  CGColorSpaceRef space) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `space'. As a
   side-effect, set the stroke color to a default value appropriate for the
   color space. */

CG_EXTERN void CGContextSetStrokeColorSpace(CGContextRef context,
  CGColorSpaceRef space) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/** Color functions. **/
#if 0
/* Set the components of the current fill color in `context' to the values
   specifed by `components'. The number of elements in `components' must be
   one greater than the number of components in the current fill color space
   (N color components + 1 alpha component). The current fill color space
   must not be a pattern color space. */

CG_EXTERN void CGContextSetFillColor(CGContextRef context,
  const CGFloat components[])
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the components of the current stroke color in `context' to the values
   specifed by `components'. The number of elements in `components' must be
   one greater than the number of components in the current stroke color
   space (N color components + 1 alpha component). The current stroke color
   space must not be a pattern color space. */

CG_EXTERN void CGContextSetStrokeColor(CGContextRef context,
  const CGFloat components[])
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Pattern functions. **/

/* Set the components of the current fill color in `context' to the values
   specifed by `components', and set the current fill pattern to `pattern'.
   The number of elements in `components' must be one greater than the
   number of components in the current fill color space (N color components
   + 1 alpha component). The current fill color space must be a pattern
   color space. */

CG_EXTERN void CGContextSetFillPattern(CGContextRef context,
  CGPatternRef pattern, const CGFloat components[])
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the components of the current stroke color in `context' to the values
   specifed by `components', and set the current stroke pattern to
   `pattern'. The number of elements in `components' must be one greater
   than the number of components in the current stroke color space (N color
   components + 1 alpha component). The current stroke color space must be a
   pattern color space. */

CG_EXTERN void CGContextSetStrokePattern(CGContextRef context,
  CGPatternRef pattern, const CGFloat components[])
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/* Set the pattern phase in the current graphics state of `context' to
   `phase'. */

CG_EXTERN void CGContextSetPatternPhase(CGContextRef context, CGSize phase)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Color convenience functions. **/
#if 0
/* Set the current fill color space in `context' to `DeviceGray' and set the
   components of the current fill color to `(gray, alpha)'. */

CG_EXTERN void CGContextSetGrayFillColor(CGContextRef context, CGFloat gray,
  CGFloat alpha) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `DeviceGray' and set
   the components of the current stroke color to `(gray, alpha)'. */

CG_EXTERN void CGContextSetGrayStrokeColor(CGContextRef context, CGFloat gray,
  CGFloat alpha) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/* Set the current fill color space in `context' to `DeviceRGB' and set the
   components of the current fill color to `(red, green, blue, alpha)'. */

CG_EXTERN void CGContextSetRGBFillColor(CGContextRef context, CGFloat red,
  CGFloat green, CGFloat blue, CGFloat alpha)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `DeviceRGB' and set
   the components of the current stroke color to `(red, green, blue,
   alpha)'. */

CG_EXTERN void CGContextSetRGBStrokeColor(CGContextRef context, CGFloat red,
  CGFloat green, CGFloat blue, CGFloat alpha)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#if 0
/* Set the current fill color space in `context' to `DeviceCMYK' and set the
   components of the current fill color to `(cyan, magenta, yellow, black,
   alpha)'. */

CG_EXTERN void CGContextSetCMYKFillColor(CGContextRef context, CGFloat cyan,
  CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the current stroke color space in `context' to `DeviceCMYK' and set
   the components of the current stroke color to `(cyan, magenta, yellow,
   black, alpha)'. */

CG_EXTERN void CGContextSetCMYKStrokeColor(CGContextRef context, CGFloat cyan,
  CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Rendering intent. **/

/* Set the rendering intent in the current graphics state of `context' to
   `intent'. */

CG_EXTERN void CGContextSetRenderingIntent(CGContextRef context,
  CGColorRenderingIntent intent)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/** Image functions. **/
#if 0
/* Draw `image' in the rectangular area specified by `rect' in the context
   `c'. The image is scaled, if necessary, to fit into `rect'. */

CG_EXTERN void CGContextDrawImage(CGContextRef c, CGRect rect,
  CGImageRef image) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Draw `image' tiled in the context `c'. The image is scaled to the size
   specified by `rect' in user space, positioned at the origin of `rect' in
   user space, then replicated, stepping the width of `rect' horizontally
   and the height of `rect' vertically, to fill the current clip region.
   Unlike patterns, the image is tiled in user space, so transformations
   applied to the CTM affect the final result. */

CG_EXTERN void CGContextDrawTiledImage(CGContextRef c, CGRect rect,
  CGImageRef image) CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Return the interpolation quality for image rendering of `context'. The
   interpolation quality is a gstate parameter which controls the level of
   interpolation performed when an image is interpolated (for example, when
   scaling the image). Note that it is merely a hint to the context: not all
   contexts support all interpolation quality levels. */

CG_EXTERN CGInterpolationQuality
  CGContextGetInterpolationQuality(CGContextRef context)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the interpolation quality of `context' to `quality'. */

CG_EXTERN void CGContextSetInterpolationQuality(CGContextRef context,
  CGInterpolationQuality quality)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/** Shadow support. **/
#if 0
/* Set the shadow parameters in `context'. `offset' specifies a translation
   in base-space; `blur' is a non-negative number specifying the amount of
   blur; `color' specifies the color of the shadow, which may contain a
   non-opaque alpha value. If `color' is NULL, it's equivalent to specifying
   a fully transparent color. The shadow is a gstate parameter. After a
   shadow is specified, all objects drawn subsequently will be shadowed. To
   turn off shadowing, set the shadow color to a fully transparent color (or
   pass NULL as the color), or use the standard gsave/grestore mechanism. */

CG_EXTERN void CGContextSetShadowWithColor(CGContextRef context, CGSize offset,
  CGFloat blur, CGColorRef color)
  CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/* Equivalent to calling
     CGContextSetShadowWithColor(context, offset, blur, color)
   where color is black with 1/3 alpha (i.e., RGBA = {0, 0, 0, 1.0/3.0}) in
   the DeviceRGB color space. */

CG_EXTERN void CGContextSetShadow(CGContextRef context, CGSize offset,
  CGFloat blur) CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);
#endif

/** Gradient and shading functions. **/

/* Fill the current clipping region of `context' with a linear gradient from
   `startPoint' to `endPoint'. The location 0 of `gradient' corresponds to
   `startPoint'; the location 1 of `gradient' corresponds to `endPoint';
   colors are linearly interpolated between these two points based on the
   values of the gradient's locations. The option flags control whether the
   gradient is drawn before the start point or after the end point. */

CG_EXTERN void CGContextDrawLinearGradient(CGContextRef context,
  CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint,
  CGGradientDrawingOptions options)
  CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/* Fill the current clipping region of `context' with a radial gradient
   between two circles defined by the center point and radius of each
   circle. The location 0 of `gradient' corresponds to a circle centered at
   `startCenter' with radius `startRadius'; the location 1 of `gradient'
   corresponds to a circle centered at `endCenter' with radius `endRadius';
   colors are linearly interpolated between these two circles based on the
   values of the gradient's locations. The option flags control whether the
   gradient is drawn before the start circle or after the end circle. */

CG_EXTERN void CGContextDrawRadialGradient(CGContextRef context,
  CGGradientRef gradient, CGPoint startCenter, CGFloat startRadius,
  CGPoint endCenter, CGFloat endRadius, CGGradientDrawingOptions options)
  CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

#if 0
/* Fill the current clipping region of `context' with `shading'. */

CG_EXTERN void CGContextDrawShading(CGContextRef context, CGShadingRef shading)
  CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);
#endif

/** Text functions. **/
#if 0
/* Set the current character spacing in `context' to `spacing'. The
   character spacing is added to the displacement between the origin of one
   character and the origin of the next. */

CG_EXTERN void CGContextSetCharacterSpacing(CGContextRef context,
  CGFloat spacing) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/* Set the user-space point at which text will be drawn in the context `c'
   to `(x, y)'. */

CG_EXTERN void CGContextSetTextPosition(CGContextRef c, CGFloat x, CGFloat y)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the user-space point at which text will be drawn in `context'. */

CG_EXTERN CGPoint CGContextGetTextPosition(CGContextRef context)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#if 0
/* Set the text matrix in the context `c' to `t'. */

CG_EXTERN void CGContextSetTextMatrix(CGContextRef c, CGAffineTransform t)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Return the text matrix in the context `c'. */

CG_EXTERN CGAffineTransform CGContextGetTextMatrix(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif	// Text functions

#if 1
/* Set the text drawing mode in the current graphics state of the context
   `c' to `mode'. */

CG_EXTERN void CGContextSetTextDrawingMode(CGContextRef c,
	enum CGTextDrawingMode mode) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif

#if 1
/* Set the font in the current graphics state of the context `c' to
   `font'. */

CG_EXTERN void CGContextSetFont(CGContextRef c, CGFontRef font)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Set the font size in the current graphics state of the context `c' to
   `size'. */

CG_EXTERN void CGContextSetFontSize(CGContextRef c, CGFloat size)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif // font

/** Text convenience functions. **/
#if 1
/* Draw `string', a string of `length' bytes, at the point specified by the
text matrix in the context `c'. Each byte of the string is mapped through
the encoding vector of the current font to obtain the glyph to
display. */

CG_EXTERN void CGContextShowText(CGContextRef c, const char *string,
	size_t length) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Draw `string', a string of `length' bytes, at the point `(x, y)',
specified in user space, in the context `c'. Each byte of the string is
mapped through the encoding vector of the current font to obtain the
glyph to display. */

CG_EXTERN void CGContextShowTextAtPoint(CGContextRef c, CGFloat x, CGFloat y,
	const char *string, size_t length)
	CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif	// ShowText

#if 0
/* Draw `glyphs', an array of `count' CGGlyphs, at the points specified by
   `positions'. Each element of `positions' specifies the position from the
   associated glyph; the positions are specified in user space. */

CG_EXTERN void CGContextShowGlyphsAtPositions(CGContextRef context,
  const CGGlyph glyphs[], const CGPoint positions[], size_t count)
  CG_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
#endif
/** PDF functions. **/
#if 0
/* Draw `page' in the current user space of the context `c'. */

CG_EXTERN void CGContextDrawPDFPage(CGContextRef c, CGPDFPageRef page)
  CG_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** Output page functions. **/

/* Begin a new page. */

CG_EXTERN void CGContextBeginPage(CGContextRef c, const CGRect *mediaBox)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* End the current page. */

CG_EXTERN void CGContextEndPage(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** Context functions. **/

/* Equivalent to `CFRetain(c)'. */

CG_EXTERN CGContextRef CGContextRetain(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Equivalent to `CFRelease(c)'. */

CG_EXTERN void CGContextRelease(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Flush all drawing to the destination. */

CG_EXTERN void CGContextFlush(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Synchronized drawing. */

CG_EXTERN void CGContextSynchronize(CGContextRef c)
  CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#endif
/** Antialiasing functions. **/

/* Turn on antialiasing if `shouldAntialias' is true; turn it off otherwise.
   This parameter is part of the graphics state. */

CG_EXTERN void CGContextSetShouldAntialias(CGContextRef context,
  bool shouldAntialias) CG_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
#if 0
/* Allow antialiasing in `context' if `allowsAntialiasing' is true; don't
   allow it otherwise. This parameter is not part of the graphics state. A
   context will perform antialiasing if both `allowsAntialiasing' and the
   graphics state parameter `shouldAntialias' are true. */

CG_EXTERN void CGContextSetAllowsAntialiasing(CGContextRef context,
  bool allowsAntialiasing) CG_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_2_0);
#endif
/** Font display functions. **/

/* Turn on font smoothing if `shouldSmoothFonts' is true; turn it off
   otherwise. This parameter is part of the graphics state. Note that this
   doesn't guarantee that font smoothing will occur: not all destination
   contexts support font smoothing. */

CG_EXTERN void CGContextSetShouldSmoothFonts(CGContextRef context,
  bool shouldSmoothFonts) CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);
#if 0
/* If `allowsFontSmoothing' is true, then allow font smoothing when
   displaying text in `context'; otherwise, don't allow font smoothing. This
   parameter is not part of the graphics state. Fonts will be smoothed if
   they are antialiased when drawn and if both `allowsFontSmoothing' and the
   graphics state parameter `shouldSmoothFonts' are true. */

CG_EXTERN void CGContextSetAllowsFontSmoothing(CGContextRef context,
  bool allowsFontSmoothing) CG_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_2_0);
#endif

/** Policy functions **/
CG_EXTERN void CGContextPolicyForceSpeed(CGContextRef context);
CG_EXTERN void CGContextPolicyPreferSpeed(CGContextRef context);
CG_EXTERN void CGContextPolicyBalance(CGContextRef context);
CG_EXTERN void CGContextPolicyDefault(CGContextRef context);
#endif
