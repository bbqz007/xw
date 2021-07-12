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
core
animation
in
cocoa
frameworks.

![img](https://github.com/bbqz007/xw/blob/master/demo/XWQ.demo.gif)

photo below is shown for wall-behive.

![img](https://img2020.cnblogs.com/blog/665551/202012/665551-20201230053200353-279860334.gif)

[PicInCN](https://img2020.cnblogs.com/blog/665551/202012/665551-20201230053200353-279860334.gif)
## classes
NSObject

CALayer

CARootLayer (2021)

CATextLayer

CAAnimation

CGContext

NSAutoReleasePool

NSDispatcher (2021)

\_\_strong

\_\_weak

CGAffineTransform

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
1. scope between `_0_autorelease` and `_1_autorelease`

2. NSObjects can use `autorelease()` method.
## lifetime
1. all the NSObjects only allowed to be created by `NSObject::allocT<Ty>()`, any `new` or scoped creation would throw.
2. `release()` by hand, or `autorelease()`
3. use `__strong<Ty>`, it `retain()` when the pointer checks in and `release()` when the pointer checks out.
## dispatch_queue
1. implement as `NSDispatcher` which associate to HWND, and `dispatch_async()` to UI thread which the HWND belongs to.
2. this `NSDispatcher` help you change `CALayer` in UI thread rather than a non UI thread.
3. you should process `process_dispatch_on_message()` in the HWND's `WM_NS_DIPATCH_NOTIRY` wndporc.
## other associated demo
![img](https://github.com/bbqz007/stock-drawing-assistant-tool/blob/master/res/demo1.gif)

[if you are behive a wall, click here](https://www.cnblogs.com/bbqzsl/p/13285949.html)

https://github.com/bbqz007/stock-drawing-assistant-tool
