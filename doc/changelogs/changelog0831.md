### implement 
* gstate
  * `CGContextSaveGState(CGContextRef c)`
  * `CGContextRestoreGState(CGContextRef c)`
* text
  * `CGContextSetTextPosition(CGContextRef c, CGFloat x, CGFloat y)`
  * `CGContextGetTextPosition(CGContextRef context)`
  * `CGContextSetTextDrawingMode(CGContextRef c, /**CGTextDrawingMode*/ unsigned int mode)`
  * `CGContextSetFont(CGContextRef c, CGFontRef font)`
  * `CGContextSetFontSize(CGContextRef c, CGFloat size)`
  * `CGContextShowText(CGContextRef c, const char *string, size_t length)`
  * `CGContextShowTextAtPoint(CGContextRef c, CGFloat x, CGFloat y, const char *string, size_t length)`
* antialias
  * `CGContextSetShouldAntialias(CGContextRef context, bool shouldAntialias)`
  * `CGContextSetShouldSmoothFonts(CGContextRef context, bool shouldSmoothFonts)`

### changes
* CGContext
  * compatible
    * old ver constructure
    * new functional functions are noop, such as text, gradient.
  * new
    * new ver constructure with ver argurement to indicate the version of header of CGContext. 



