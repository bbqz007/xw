### Overview
The root class of most CoreAnimation class hierarchies, from which subclasses inherit a basic interface to the runtime system and the ability to behave as NSObject objects..

a NSObject can use `isKindOfClass<T>` to check out the class hierarchies.

[**`__strong`**](__strong.md), [**`__weak`**](__weak.md) and [**`__autoreleasing`**](__autoreleasing.md) can apply to NSObject classes.

all the NSObject should use `NSObject::allocT<T>()` classified method to create object, and call `NSObject::release()` member method to release it.

any local value or `operator new` are forbidden. also you can not `operator delete` it.










