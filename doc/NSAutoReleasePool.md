### overview
A GC mechanism for autoreleasing NSObjects rather than releasing NSObjects by hand.

you should attach a thread to NSAutoreleasePool mechanism, before you use `NSAutoreleasePool`.

`NSAutoreleasePool` is scoped in call frame. do not try to make it to global or member of class or heap.

###
```c++
NSAutoreleasePoolAttachCurrentThread();

{
  NSAutoreleasePool node;
  NSObject* o = some->retain()->autorelease(); // node accept this autorelease
} // node acomplish the autoreleases

NSAutoreleasePoolDrain();
NSAutoreleasePoolDettachCurrentThread();
```

### 
* classes
  * `NSAutoreleasePool`
* functions
  * `BOOL NSAutoreleasePoolAttachCurrentThread();`
  * `NSAutoreleasePoolDrain();`
  * `NSAutoreleasePoolDettachCurrentThread();`

