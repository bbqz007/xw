/**
MIT License
Copyright (c) 2015 bbqz007 <https://github.com/bbqz007, http://www.cnblogs.com/bbqzsl>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// XWView.h : interface of the CXWView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "helper.h"
#include "CATestLayer.h"
#include "CGContext.h"
#include "CAAnimation.h"
#include "NSAutoreleasePool.h"
#include "NSString.h"

class CXWView : public CWindowImpl<CXWView>,
				public CDoubleBufferImpl<CXWView>
{
	long _tbase;
	CATestLayer* _testLayer;
	CALayer* _normalLayer;
public:
	DECLARE_WND_CLASS(NULL)

	~CXWView()
	{
		// error, may out of the main, gdiplus.dll released.
	}

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		pMsg;
		return FALSE;
	}

	BEGIN_MSG_MAP(CXWView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
		MESSAGE_HANDLER(WM_MOVING, OnMoving)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGING, OnWinPosChanging)
		MESSAGE_HANDLER(WM_WINDOWPOSCHANGED, OnWinPosChanged)
		MESSAGE_HANDLER(WM_CONTEXTMENU, OnContextMenu)
		MESSAGE_HANDLER(WM_NCHITTEST, OnNCHitTest)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
		MESSAGE_HANDLER(WM_NCACTIVATE, OnNCActivate)
		MESSAGE_HANDLER(WM_NCPAINT, OnNCPaint)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		//CHAIN_MSG_MAP(CDoubleBufferImpl<CXWView>)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		//layered style and opauq 0xff is neccesary.
		//whitout this, the underlying windows would not be redraw.
		::SetWindowLong(m_hWnd, GWL_EXSTYLE, ::GetWindowLong(m_hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
		::SetLayeredWindowAttributes(m_hWnd, 0xF0FFFF/*0*/, 255, LWA_COLORKEY /*LWA_ALPHA*/);
		::SetTimer((HWND)*this, 0xab, 17, NULL);
		_tbase = ::GetMessageTime();
		_testLayer = NSObject::allocT<CATestLayer>();
		_testLayer->setFrame(CGRect(20.f, 100.f, 40.f, 40.f));
		_testLayer->set_backgroundColor(CGColor(CGColor::Pink));
		_normalLayer = NSObject::allocT<CALayer>();
		_normalLayer->setFrame(CGRect(20.f, 500.f, 40.f, 40.f));
		_normalLayer->set_backgroundColor(CGColor(CGColor::Pink));
		CATestLayer* _testLayer2 = (CATestLayer*) NSObject::allocT<CATestLayer>()->autorelease();
		_testLayer2->setFrame(CGRect(5.f, 5.f, 10.f, 10.f));
		_testLayer2->set_backgroundColor(CGColor(123, 24, 53));
		_normalLayer->addSublayer(_testLayer2);

		::isKindOfClass<CALayer>(_testLayer2);
		::isKindOfClass<NSArray>(_testLayer2);
		//_testLayer2->release();

		NSString* str = NSString::stringWithFormat(NSString::stringWithCString((const char*)L"%s%S"), "1", L"2");
		return 0;   // no background painting needed
	}

	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		long timeout = ::GetMessageTime();
		if(1 || (timeout - _tbase) % 2000 > 1500)
		{
			CRect rc; GetWindowRect(&rc);
			rc.right -= rc.left, rc.bottom -= rc.top, rc.top = rc.left = 0;
			InvalidateRect(&rc);
			UpdateWindow();
		}
		if((timeout - _tbase) % 2000 < 40)
		{ _0_autoreleasepool
			_normalLayer->setFrame(CGRect(20.f, 500.f, 40.f, 40.f));
			_normalLayer->setTransform(CGAffineTransform());
			::CAAnimation* anime = CAAnimation::beginAnimating(_normalLayer, 1.f);
			{
				anime->setFrame(CGRect(320.f, 500.f, 20.f, 20.f));
				anime->translate(0.f, -100.f);
				anime->rotate(360.f);
				anime->commit();
			}
		  _1_autoreleasepool
		}

		::buildActivateAnimations();

		return 0;   // no background painting needed
	}

	LRESULT OnEraseBackground(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		return 1;   // no background painting needed
	}



	LRESULT OnMoving(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CRect rc; GetWindowRect(&rc);
		rc.right -= rc.left, rc.bottom -= rc.top, rc.top = rc.left = 0;
		InvalidateRect(&rc);
		UpdateWindow();
		return 1;   // no background painting needed
	}

	LRESULT OnWinPosChanging(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CRect rc; GetWindowRect(&rc);
		rc.right -= rc.left, rc.bottom -= rc.top, rc.top = rc.left = 0;
		InvalidateRect(&rc);
		UpdateWindow();
		return 1;   // no background painting needed
	}

	LRESULT OnWinPosChanged(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CRect rc; GetWindowRect(&rc);
		rc.right -= rc.left, rc.bottom -= rc.top, rc.top = rc.left = 0;
		InvalidateRect(&rc);
		UpdateWindow();
		return 1;   // no background painting needed
	}

	LRESULT OnContextMenu(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		UINT ht = DefWindowProc(WM_NCHITTEST, wParam, lParam);
		return 0;
	}

	LRESULT OnNCHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		UINT ht = DefWindowProc(uMsg, wParam, lParam);
		if(HTREDUCE == ht || HTZOOM == ht || HTCLOSE == ht || HTSYSMENU == ht)
			ht = HTCAPTION;
		return ht;
	}

	LRESULT OnNCActivate(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		////The DefWindowProc function draws the title bar or icon title in its active colors
		////////when the wParam parameter is TRUE and in its inactive colors when wParam is FALSE.

		return 0;
	}

	LRESULT OnNCPaint(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CDC dc(::GetDCEx(m_hWnd, (HRGN)wParam, DCX_WINDOW|DCX_INTERSECTRGN));
		return 0;
	}

	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
        // display layers
		{
			CGRect cgrc(rc.left, rc.top, rc.Width(), rc.Height());
			CGContext ctx(dc, dcMem, dcCraft, cgrc);
			_testLayer->display(&ctx);
			_normalLayer->display(&ctx);
		}

		return 0;
	}

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		// unregister message filtering and idle updates
		if((GetStyle() & (WS_CHILD | WS_POPUP)) == 0)
			::PostQuitMessage(1);

		if(_testLayer)
			_testLayer->release();
		_testLayer = NULL;

		if(_normalLayer)
			_normalLayer->release();
		_normalLayer = NULL;

		bHandled = FALSE;
		return 1;
	}

	void DoPaint(CDCHandle dcPaint)
	{
		int nContextState = dcPaint.SaveDC();



		dcPaint.RestoreDC( nContextState );
	}
};
