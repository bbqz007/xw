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
very lightweight.

![img](https://github.com/bbqz007/xw/blob/master/demo/XWQ.demo.gif)
## classes
CALayer

CATextLayer

CAAnimation

CGContext

NSAutoReleasePool

CGAffineTransform

## two way to write animations
1. use CAAnimation to commit a animation job.

2. implement your own CALayer, override the virtual method CALayer::applyAnimating() to control every frame.

## properties of CALayer for animation
1. Frame.

2. opacity.

3. transform matrix.

## custom draw CALayer
1. override the virtual method CALayer::drawInContext()

## autorelease
1. scope between _0_autorelease and _1_autorelease

2. NSObjects can use autorelease method.
