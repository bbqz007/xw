### Overview
a implement to the keyword [`__strong`](https://developer.apple.com/library/archive/documentation/General/Conceptual/DevPedia-CocoaCore/ObjectOwnership.html) in cocoa programming.

implementing as a template class. you should specified the template parameter to indicate which NSObject class you want to apply to `__strong`.

### Associate
[`__weak`](__weak.md) keyword.

[`__autoreleasing`](__autorelease.md) keyword.

### Difference
**`__strong`** retain the NSObject which check-in and release the NSObject which check-out.

**`__autoreleasing`** only release the NSObject which check-out.

**`__weak`** would not retain or release the NSObject. you should check out the NSObject by the only way upgrading it from `__weak` to `__strong`.

**`__autoreleasing`** vs **NSAutoReleasePool**.

### Forbidden
you can not use **`__strong`**, **`__weak`** and **`__autoreleasing`** to apply to a non NSObject class;

`zhelper_assert_nsobject<T>` would make the a compiler error to indicate that you are doing a forbidden thing.

### Example
```c++

__strong<CALayer> layer = NSObject::allocAndAutoreleasingT<CALayer>();
__autoreleasing<CALayer> layer2 = NSObject::allocT<CALayer>();
__weak<CALayer> weakLayer = layer;
__weak<CALayer> weakLayer2 = layer2;    
layer2 = layer;     // error: autorelease <- strong
layer = layer2;   

```








