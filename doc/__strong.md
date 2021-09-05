### Overview
a implement to the keyword [`__strong`](https://developer.apple.com/library/archive/documentation/General/Conceptual/DevPedia-CocoaCore/ObjectOwnership.html) in cocoa programming.

implementing as a template class. you should specified the template parameter to indicate which NSObject class you want to apply to `__strong`.

### Associate
[`__weak`](__weak.md) keyword.

[`__autoreleasing`](__autorelease.md) keyword.

### example
```c++

__strong<CALayer> layer = NSObject::allocAndAutoreleasingT<CALayer>();
__autoreleasing<CALayer> layer2 = NSObject::allocT<CALayer>();
__weak<CALayer> weakLayer = layer;
__weak<CALayer> weakLayer2 = layer2;    
layer2 = layer;     // error: autorelease <- strong
layer = layer2;   

```








