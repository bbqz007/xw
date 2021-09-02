### overview
A GC mechanism for autoreleasing NSObjects rather than releasing NSObjects by hand.

you should attach a thread to NSAutoreleasePool mechanism, before you use `NSAutoreleasePool`.

`NSAutoreleasePool` is scoped in call frame. do not try to make it to global or member of class or heap.

### example
```c++
NSAutoreleasePoolAttachCurrentThread();     // not necessary

{
  NSAutoreleasePool node;
  NSObject* o = some->retain()->autorelease(); // node accept this autorelease
} // node acomplish the autoreleases

NSAutoreleasePoolDrain();
NSAutoreleasePoolDettachCurrentThread();
```

or 

```c++
_0_autoreleasepool 

NSObject* o = some->retain()->autorelease(); // node accept this autorelease

_1_autoreleasepool
```

### interfaces
* classes
  * `NSAutoreleasePool`
* functions
  * `BOOL NSAutoreleasePoolAttachCurrentThread();`
  * `NSAutoreleasePoolDrain();`
  * `NSAutoreleasePoolDettachCurrentThread();`

