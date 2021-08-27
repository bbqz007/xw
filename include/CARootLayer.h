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

#ifndef _Z_CARootLayer_H_
#define _Z_CARootLayer_H_

#include "CALayer.h"

#define HAS_WTL 1
//// if you do not want to use wtl any way, comment the line above.
#ifdef HAS_WTL
#include <atlapp.h>
#endif

namespace WTL { class CAppModule; }

class CARootLayer : public CALayer
{
public:
	CA_EXTERN virtual ~CARootLayer();
	CA_EXTERN CARootLayer();
	CA_EXTERN virtual void drawInContext(CGContext* ctx);
	//// don't derive new class from this class, otherwise you miss the functionals below
	CA_EXTERN HWND getHostWindow();
	CA_EXTERN void attachWindow(HWND hwnd);
	CA_EXTERN void displayInWindow();
	CA_EXTERN void displayInClient();
#ifdef HAS_WTL
	//// if you call TrackPopupMenu(), 
	////  you should call PreTranslateMessageInMessgaeLoop() in your message loop 
	////  or PreProcessMessageInWndProc() in your attched window's wndproc,
	////  although you init with WTL.
	//// because TrackPopupMenu() has its own controlled messgae loop.
	CA_EXTERN static void init(WTL::CAppModule*,
		WTL::CMessageLoop*(WTL::CAppModule::*get)(DWORD) const = &WTL::CAppModule::GetMessageLoop,
		BOOL(WTL::CMessageLoop::*add)(WTL::CMessageFilter*) = &WTL::CMessageLoop::AddMessageFilter,
		BOOL(WTL::CMessageLoop::*rv)(WTL::CMessageFilter*) = &WTL::CMessageLoop::RemoveMessageFilter);
#endif
	CA_EXTERN static void initAgainstWTL();
	CA_EXTERN static BOOL PreTranslateMessageInMessgaeLoop(MSG*);
	CA_EXTERN static BOOL PreProcessMessageInWndProc(HWND, UINT, WPARAM, LPARAM);

public:
	CA_EXTERN BOOL acquireHighFrameRateMode();
	CA_EXTERN BOOL releaseHighFrameRateMode();
public:
	typedef CARootLayer this_type;
	typedef CALayer base;
protected:
};

template<> NS_EXTERN
CARootLayer* NSObject::allocT<CARootLayer>();

NS_EXPORT_CLASS_ID(CARootLayer)

#endif // _Z_CARootLayer_H_
