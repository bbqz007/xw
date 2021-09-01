### overview
implement a part of CoreGraphics. 

all the CG Objects are not NSObject.

CALayer display() use CGContext and CGContext functions and CG Objects.

### api
* _gstate
  * save and restore
    * **CGContextSaveGState**`(CGContextRef c)`
    * **CGContextRestoreGState**`(CGContextRef c)`
  * transformation
    * **CGContextScaleCTM**`(CGContextRef c, CGFloat sx, CGFloat sy)`
    * **CGContextTranslateCTM**`(CGContextRef c, CGFloat tx, CGFloat ty)` 
    * **CGContextRotateCTM**`(CGContextRef c, CGFloat angle)`
    * **CGContextConcatCTM**`(CGContextRef c, CGAffineTransform transform)`
    * `CGAffineTransform` **CGContextGetCTM**`(CGContextRef c)`
  * line
    * lineWidth 
    * lineCap
    * lineJoin
    * lineDash
  * color
    * **CGContextSetFillColorWithColor**`(CGContextRef c, CGColorRef color)`
    * **CGContextSetStrokeColorWithColor**`(CGContextRef c, CGColorRef color) `
    * **CGContextSetRGBFillColor**`(CGContextRef context, CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha)`
    * **CGContextSetRGBStrokeColor**`(CGContextRef context, CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha)`
* _path
  * **CGContextBeginPath**`(CGContextRef c)`
  * **CGContextMoveToPoint**`(CGContextRef c, CGFloat x, CGFloat y)`
  * **CGContextAddLineToPoint**`(CGContextRef c, CGFloat x, CGFloat y)`
  * **CGContextAddCurveToPoint**`(CGContextRef c, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y)`
  * **CGContextClosePath**`(CGContextRef c)`
  * **CGContextAddRect**`(CGContextRef c, CGRect rect)`
  * **CGContextAddRects**`(CGContextRef c, const CGRect rects[], size_t count)`
  * **CGContextAddLines**`(CGContextRef c, const CGPoint points[], size_t count)`
  * **CGContextAddEllipseInRect**`(CGContextRef context, CGRect rect)`
  * **CGContextAddArc**`(CGContextRef c, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise)`
  * **CGContextAddArcToPoint**`(CGContextRef c, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius)`
  * **CGContextAddPath**`(CGContextRef context, CGPathRef path)`
  * **CGContextIsPathEmpty**`(CGContextRef context)`
  * **CGContextGetPathCurrentPoint**`(CGContextRef context)`
  * **CGContextGetPathBoundingBox**`(CGContextRef context)`
* _stroke
  * **CGContextStrokePath**`(CGContextRef c)`
  * **CGContextStrokeRect**`(CGContextRef c, CGRect rect)`
  * **CGContextStrokeRectWithWidth**`(CGContextRef c, CGRect rect, CGFloat width)`
  * **CGContextStrokeEllipseInRect**`(CGContextRef context, CGRect rect)`
  * **CGContextStrokeLineSegments**`(CGContextRef c, const CGPoint points[], size_t count)`
* _fill
  * **CGContextFillPath**`(CGContextRef c)`
  * **CGContextFillRect**`(CGContextRef c, CGRect rect)`
  * **CGContextFillRects**`(CGContextRef c, const CGRect rects[], size_t count)`
  * **CGContextFillEllipseInRect**`(CGContextRef context, CGRect rect)`
* _text
  * **CGContextSetTextPosition**`(CGContextRef c, CGFloat x, CGFloat y)`
  * **CGContextGetTextPosition**`(CGContextRef context)`
  * **CGContextSetTextDrawingMode**`(CGContextRef c, CGTextDrawingMode mode)`
  * **CGContextSetFont**`(CGContextRef c, CGFontRef font)`
  * **CGContextSetFontSize**`(CGContextRef c, CGFloat size)`
  * **CGContextShowText**`(CGContextRef c, const char *string, size_t length)`
  * **CGContextShowTextAtPoint**`(CGContextRef c, CGFloat x, CGFloat y, const char *string, size_t length)`
* gradient
  * **CGContextDrawLinearGradient**`(CGContextRef context, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options)`
  * **CGContextDrawRadialGradient**`(CGContextRef context, CGGradientRef gradient, CGPoint startCenter, CGFloat startRadius, CGPoint endCenter, CGFloat endRadius, CGGradientDrawingOptions options)`
* _antialias
  * **CGContextSetShouldAntialias**`(CGContextRef context, bool shouldAntialias)`
  * **CGContextSetShouldSmoothFonts**`(CGContextRef context, bool shouldSmoothFonts)`



