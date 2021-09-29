### Overview
  [Grand Central Dispatch (GCD)](https://developer.apple.com/library/archive/documentation/General/Conceptual/ConcurrencyProgrammingGuide/OperationQueues/OperationQueues.html) in apple's cocoa programming.
  
we use `dipatch_async()` to dispatch behives to `dispatch_get_main_queuq` which is the unique **UI Thread** in cocoa program.

In windows application, the window is implemented using active-object pattern. 

we also need to dispatch window behives to the **ui thread** which created it and performs the message loop, by calling `SendMessage()` or `PostMessage()`.

here, CALayer is a Layer on window rather than a window, we should need to dispatch layer behives to the **ui thread** from a **non-ui thread**.

we can treat windows message loop like the cocoa CFRunLoop. but there could be any ui thread in windows application, while only main thread CFRunLoop can run Window.

so, the ui thread is not always equal to main thread in windows.

a HWND should run in a **ui thread** which it belongs to. 

thus, `NsDispatcher` is implemented to dispatch behives to the **ui thread** which created the HWND.

### Conditions
`NSDispatcher` is designed based on c++11 features.

you should swith on the compiler option `/Zc:__cplusplus` to indicate wether your compiler support c++11 or not.

a `NSDispatcher` should be created in the **ui thread**, otherwise it would throw and abort your program.

### Usage
you can easily use `NSDispatcher` with `CARootLayer`.

after you called `attachWindow()` to attach your `CARootLayer` to a HWND in `WM_CREATE` wndproc, you can call `CARootLayer::dispatcher()` member function to create a dipsatcher in this **ui thread**.

then you can pass this `NSDispatcher` to other thread by lambda capturing __strong<NSDispatcher>. other thread can dispatch CALayer behives to **ui thread** by this dispatcher.

you should run the `NSDispatcher::process_dispatch_on_message()` classified function to pretranlate the message in your message loop or wndproc at the most first. 
### example

```c++
  CARootLayer* rootLayer = ...;
  // ...
  case WM_CREATE:
    rootLayer->attachWindow(hwnd);
    __strong<NSDispatcher> dispatcher = rootLayer->dispatcher();
    __strong<CALayer> layer = ...; // a sub layer of rootLayer
    std::thread([=](){
      int result;
      // do some calc to make result.
      dispatcher->dispatch_async([](){
        layer->updateValue(result);
      });
    });
    break;
```














