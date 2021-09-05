### Overview
The root class of most CoreAnimation class hierarchies.

a NSObject can use `isKindOf<T>` to check the class hierarchies.

[**`__strong`**](__strong.md), [**`__weak`**](__weak.md) and [**`__autoreleasing`**](__autoreleasing.md) can apply to NSObject classes.

all the NSObject should use `NSObject::allocT<T>()` classified method to create object, and call `NSObject::release()` member method to release it.

any local value or `operator new` are forbidden. also you can not `operator delete` it.










