### overview
`CARootLayer` is a helper Layer on the top of Layer Hierarchy. 

It helps to use Core Animation Engine.

The Core Animation Engine is implemented to attach to one WIN32 window.

It is no border and no background by default.

### WTL mode
you should use `static void CARootLayer::init(WTL::CAppModule*,,,)` to init the Core Animation Engine with WTL.

this mode you should not handle anything. otherwise you should handle many stuffs by hand.

### Win32 mode
you should use `static void CARootLayer::initAgainstWTL()` to init the Core Animation Engine without WTL.

you should handle these stuffs below:
* call `static BOOL CARootLayer::PreTranslateMessageInMessgaeLoop(MSG*)` in your message loop.
* or call `static BOOL CARootLayer::PreProcessMessageInWndProc(HWND, UINT, WPARAM, LPARAM)` in your attached window's wndproc at the most first.

### display
you should call `CALayer::display(CGContext*)` in WM_PAINT wndproc of the attached window. 

`CARootLayer::displayInWindow()` or `CARootLayer::displayInClient()` helps to display regardless of CGContext.

call `CARootLayer::displayInWindow()` if you `setFrame()` as the frame of `::GetWindowRect()`.

or call `CARootLayer::displayInClient()` if you `setFrame()` as the frame of `::GetClientRect()`.

### manuals
* call `static void CARootLayer::init(WTL::CAppModule*,,,)` or `static void CARootLayer::initAgainstWTL()` when app init.
* call `void CARootLayer::attachWindow(HWND hwnd)` to attach a window after a `CARootLayer` is created.
* call `CARootLayer::displayInWindow()` or `CARootLayer::displayInClient()` in WM_PAINT wndproc of the attached window.

### animation
any animation of layer which has `addSublayer()` to the Layer Hierarchy of the `CARootLayer`, will belongs to the same engine.

animations should commit in ui thread. use `NSDispatcher` to dispatch `commit()` from non ui thread to ui thread.



































