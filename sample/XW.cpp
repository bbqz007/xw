// XW.cpp : main source file for XW.exe
//

#include "stdafx.h"

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>

#include "resource.h"

#include "XWView.h"
#include "XWViewFoundation.h"
#include "aboutdlg.h"
#include "MainFrm.h"
#include "NSAutoreleasePool.h"

CAppModule _Module;

// Z@20151211
struct XWNSAotureleasePoolIdleHandler : public CIdleHandler
{
	BOOL OnIdle()
	{
		NSAutoreleasePoolDrain();
		return TRUE;
	}
};

int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	/*CMainFrame wndMain;

	if(wndMain.CreateEx() == NULL)
	{
		ATLTRACE(_T("Main window creation failed!\n"));
		return 0;
	}

	wndMain.ShowWindow(nCmdShow);*/

	XWNSAotureleasePoolIdleHandler autodrainIdleHandler;
	theLoop.AddIdleHandler(&autodrainIdleHandler);

	::Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	::Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	int nRet;

	_0_autoreleasepool {

	CXWView wndXW;
#if Ver_old
	wndXW.Create(0, ATL::CWindow::rcDefault, NULL, WS_CAPTION | WS_SYSMENU, WS_EX_LAYERED | WS_EX_TOPMOST);
#else
	CXWFoundationView foundationXW;
	foundationXW.Create(0, ATL::CWindow::rcDefault, NULL, WS_CAPTION | WS_SYSMENU, WS_EX_LAYERED);// | WS_EX_TOPMOST);

	CRect rc;
    GetWindowRect(foundationXW, &rc);
	//rc.left = 0;		// not a child window
	//rc.right = 0;		// not a child winodw
	wndXW.Create(foundationXW, rc, NULL, WS_POPUP, WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_LAYERED);// | WS_EX_TOPMOST);
	foundationXW.SetLayerEngineWindow(wndXW);

	foundationXW.ShowWindow(nCmdShow);
#endif

	wndXW.ShowWindow(nCmdShow);

	// @autoreleasepool {
	//NSAutoreleasePoolAttachCurrentThread();
	nRet = theLoop.Run();

	//NSAutoreleasePoolDettachCurrentThread();
	// }

	GCMatrixContextClear();

	}}

	_Module.RemoveMessageLoop();

	::Gdiplus::GdiplusShutdown(gdiplusToken);

	return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
