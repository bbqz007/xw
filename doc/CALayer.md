### overvivew
CALayer is implemented to a very basic.

_frame_ indicates position and size, _transform_ indicates the tranlastion, rotation and scale, _opacity_ indicates the alpha transparent.

it draws background color and border on the _frame_, _cornerRadius_ can easily make radius corners to border.

_smoothBorder_ indicates consuming performance to make smooth radius corners。

### properties
* **frame** : `CGRect`
  * \[getter] frame()
  * \[setter] setFrame() 
* **bounds** : `CGRect`
  * \[getter] bounds()
    * X and Y are always 0.f. 
  * \[setter] setBounds()
    * ignore X and Y.  
* anchorPoint : `CGPoint` \[NoImpl] 
  * by default, the anchor point is located at the center of bounds. 
* zPosition : `CGFloat` \[NoImpl] 
* **transform** : `CGAffineTransform`
  * \[getter] transform()
  * \[setter] setTransform() 
* **hidden** : `BOOL`
  * \[getter] isHidden()
  * \[setter] setHidden() 
* **superLayer** : `CALayer*`
  * \[getter] superLayer()
  * \[setter] setSuperLayer() 
* **sublayers** : `NSArray*`
  * \[getter] sublayers()
  * \[setter] setSublayers() 
* mask : `CALayer*` \[NoImpl]
* maskToBounds : `BOOL` \[NoImpl]
* opaque ：`BOOL` \[NoImpl]
* needsDisplayOnBoundsChange : `BOOL` \[NoImpl]
* drawsAsynchronously : `BOOL` \[NoImpl] 
* **backgroundColor** : `CGColor`
  * \[getter] backgroundColor()
  * \[setter] set_backgroundColor()  
* **cornerRadius** : `CGFloat`
  * \[getter] cornerRadius()
  * \[setter] set_cornerRadius()  
* **borderWidth** : `CGFloat`
  * \[getter] borderWidth()
  * \[setter] set_borderWidth()  
* **borderColor** : `CGFloat`
  * \[getter] borderColor()
  * \[setter] set_borderColor()  
* **opacity** : `CGFloat`
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
* **smoothBorder** : `BOOL` \[Extend] 
  * would consume some performance. 
  * \[getter] smoothBorder()
  * \[setter] set_smoothBorder()  
* **smoothBorderWidth** : `CGFloat` \[Extend]  
  * recommand to set twice of _borderWidth_.
  * \[getter] smoothBorderWidth()
  * \[setter] set_smoothBorderWidth()  

### extendable functions
the three virtual functions below are called by `display()`.
* **`virtual void applyAnimating()`**
  * if one layer commits a `CAAnimation` and the `CAAnimation` is now activated, this function will be called.
  * by defalut, `CALayer::applyAnimating()` changes _frame_, _transform_ and _opacity_ proportionally to time track.
* **`virtual void layoutSublayers()`**
  * `applyAnimating()` would change _frame_, so you can layout all the _sublayers_ here.
* **`virtual void drawInContext(CGContext* ctx)`**
  * custom drawing. 
