# xw
an
animation
layer
engine
on
windows
platform
some
like
**Core**
**Animation**
in
cocoa
frameworks.

-----------------------------------------------

newest

![img](https://github.com/bbqz007/KTL/blob/master/resources/GIF_KTL_LOGO2.gif)

-----------------------------------------------

![img](https://github.com/bbqz007/xw/blob/master/demo/XWQ.demo.gif)

photo below is shown for wall-behive.

![img](https://img2020.cnblogs.com/blog/665551/202012/665551-20201230053200353-279860334.gif)

[PicInCN](https://img2020.cnblogs.com/blog/665551/202012/665551-20201230053200353-279860334.gif)
## ChangeLog
[changelog](doc/changelog.md)
## classes
[NSObject](doc/NSObject.md)

[CALayer](doc/CALayer.md)

[CARootLayer (2021)](doc/CARootLayer.md)

[CATextLayer](doc/CATextLayer.md)

[CAAnimation](doc/CAAnimation.md)

[CGContext](doc/CGContext.md)

[NSAutoReleasePool](doc/NSAutoReleasePool.md)

[NSDispatcher (2021)](doc/NSDispatcher.md)

[\_\_strong](doc/__strong.md)

[\_\_weak](doc/__weak.md)

[\_\_autoreleasing](doc/__autoreleasing.md)

[CGAffineTransform](doc/CGAffineTransform.md)

## use animation engine
1. attach a `CARootLayer` to win32 window handle
2. `addSublayer()` `CALayer` to this `CARootLayer`
3. `display()` this `CARootLayer` in the win32 window's `WM_PAINT` wndproc.
4. `setFrame()` while this win32 window's `WM_SIZE` etc.

## two way to write animations
1. use `CAAnimation` to `commit()` a animation job.

2. implement your own `CALayer`, override the virtual method `CALayer::applyAnimating()` to control every frame.

## properties of CALayer for animation
1. Frame.

2. opacity.

3. transform matrix.

## custom draw CALayer
1. derived Layer from `CALayer`
2. override the virtual method `CALayer::drawInContext()`

## autorelease
1. `NSAutoreleasePoolAttachCurrentThread()` before any `_0_autorelease` in the thread.
2. scope between `_0_autorelease` and `_1_autorelease`

3. NSObjects can use `autorelease()` method.
4. `NSAutoreleasePoolDettachCurrentThread()` after any `_1_autorelease` in the thread.
## lifetime
1. all the NSObjects only allowed to be created by `NSObject::allocT<Ty>()`, any `new` or scoped creation would throw.
2. `release()` by hand, or `autorelease()`
3. use `__strong<Ty>`, it `retain()` when the pointer checks in and `release()` when the pointer checks out.
## dispatch_queue
1. implement as `NSDispatcher` which associate to HWND, and `dispatch_async()` to UI thread which the HWND belongs to.
2. this `NSDispatcher` help you change `CALayer` in UI thread rather than a non UI thread.
3. you should process `process_dispatch_on_message()` in the HWND's `WM_NS_DIPATCH_NOTIRY` wndporc.

## performance
[CGContextPolicy](doc/CGContextPolicy.md)
1. `CGContextPolicyForceSpeed()`
2. `CGContextPolicyPreferSpeed()`
3. `CGContextPolicyDefault()`
4. `CGContextPolicyBalance()`
![img](https://github.com/bbqz007/KTL/blob/master/resources/GIF_KTL_PERF.gif)

## projects
[https://github.com/bbqz007/KTL](https://github.com/bbqz007/KTL)
![img](https://github.com/bbqz007/KTL/blob/master/resources/GIF_KTL_Load.gif)
![img](https://github.com/bbqz007/KTL/blob/master/resources/GIF_KTL_LOGO.gif)

## other associated demo
![img](https://github.com/bbqz007/stock-drawing-assistant-tool/blob/master/res/demo1.gif)

[if you are behive a wall, click here](https://www.cnblogs.com/bbqzsl/p/13285949.html)

https://github.com/bbqz007/stock-drawing-assistant-tool
