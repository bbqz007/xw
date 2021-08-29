### properties
* frame : `CGRect`
  * \[getter] frame()
  * \[setter] setFrame() 
* bounds : `CGRect`
  * \[getter] bounds()
    * X and Y are always 0.f. 
  * \[setter] setBounds()
    * ignore X and Y.  
* anchorPoint : `CGPoint` \[NoImpl] 
  * by default, the anchor point is located at the center of bounds. 
* zPosition : `CGFloat` \[NoImpl] 
* transform : `CGAffineTransform`
  * \[getter] transform()
  * \[setter] setTransform() 
* hidden : `BOOL`
  * \[getter] isHidden()
  * \[setter] setHidden() 
* superLayer : `CALayer*`
  * \[getter] superLayer()
  * \[setter] setSuperLayer() 
* sublayers : `NSArray*`
  * \[getter] sublayers()
  * \[setter] setSublayers() 
* mask : `CALayer*` \[NoImpl]
* maskToBounds : `BOOL` \[NoImpl]
* opaque ：`BOOL` \[NoImpl]
* needsDisplayOnBoundsChange : `BOOL` \[NoImpl]
* drawsAsynchronously : `BOOL` \[NoImpl] 
* backgroundColor : `CGColor`
  * \[getter] backgroundColor()
  * \[setter] set_backgroundColor()  
* cornerRadius : `CGFloat`
  * \[getter] cornerRadius()
  * \[setter] set_cornerRadius()  
* borderWidth : `CGFloat`
  * \[getter] borderWidth()
  * \[setter] set_borderWidth()  
* borderColor : `CGFloat`
  * \[getter] borderColor()
  * \[setter] set_borderColor()  
* opacity : `CGFloat`
  * \[getter] opacity()
  * \[setter] set_opacity()  
* allowsGroupOpacity : `BOOL` \[NoImpl] 
* filters : `NSArray*` \[NoImpl] 
* backgroundFilters : `NSArray*` \[NoImpl] 
* shouldRasterize : `BOOL` \[NoImpl] 
* rasterizationScale : `CGFloat` \[NoImpl] 
* shadowColor : `CGColor` \[NoImpl] 
* shadowOpacity : `CGFloat` \[NoImpl] 
* shadowRadius : `CGFloat` \[NoImpl] 
* shadowPath : `CGPath` \[NoImpl] 
* smoothBorder : `BOOL` \[Extend] 
  * \[getter] smoothBorder()
  * \[setter] set_smoothBorder()  
* smoothBorderWidth : `CGFloat` \[Extend]  
  * \[getter] smoothBorderWidth()
  * \[setter] set_smoothBorderWidth()  
