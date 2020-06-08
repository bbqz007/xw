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

#pragma once

inline HBITMAP CreateColorDBIBitmap(HDC hdc, const RECT& rc, DWORD color)
{
	DWORD nWidth = rc.right - rc.left;
    DWORD nHeight = rc.bottom - rc.top;
	BITMAPV5HEADER bi;
    void *lpBits;

    ZeroMemory(&bi,sizeof(BITMAPV5HEADER));
    bi.bV5Size        = sizeof(BITMAPV5HEADER);
    bi.bV5Width       = nWidth;
    bi.bV5Height      = nHeight;
    bi.bV5Planes      = 1;
    bi.bV5BitCount    = 32;
    bi.bV5Compression = BI_BITFIELDS;
    bi.bV5RedMask     = 0x00FF0000;
    bi.bV5GreenMask   = 0x0000FF00;
    bi.bV5BlueMask    = 0x000000FF;
    bi.bV5AlphaMask   = 0xFF000000;

	HBITMAP hbmp = CreateDIBSection(hdc, (BITMAPINFO *)&bi, DIB_RGB_COLORS,
        (void **)&lpBits, NULL, (DWORD)0);

	DWORD *lpdwPixel = (DWORD *)lpBits;
    DWORD x, y;

	DWORD nSize = nWidth * nHeight;
	__asm
	{
		push eax;
		push ecx;
		push edi;
		lea edi,[nSize];
		mov eax, [color];
		cld;
		mov ecx, dword ptr [edi];
		mov edi, [lpdwPixel];
		rep stosd;
		pop edi;
		pop ecx;
		pop eax;
	}

	return hbmp;
}


class CXWFoundationView : public CWindowImpl<CXWFoundationView>,
				public CDoubleBufferImpl<CXWFoundationView>
{
public:
public:
	DECLARE_WND_CLASS(_T("zsl_XW_Engine_Fundation"))
	~CXWFoundationView()
	{
		// error, may out of the main, gdiplus.dll released.
	}

	BOOL PreTranslateMessage(MSG* pMsg)
	{
		pMsg;
		return FALSE;
	}

	BEGIN_MSG_MAP(CXWFoundationView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_CONTEXTMENU, OnContextMenu)
		MESSAGE_HANDLER(WM_MOVING, OnMoving)
		MESSAGE_HANDLER(WM_NCHITTEST, OnNCHitTest)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		//CHAIN_MSG_MAP(CDoubleBufferImpl<CXWView>)
	END_MSG_MAP()

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		CWindowDC dc(m_hWnd);
		CDC dcscr(0);
		CRect rc; GetWindowRect(&rc);
		rc.right -= rc.left, rc.bottom -= rc.top, rc.top = rc.left = 0;
		CDC dcMem; dcMem.CreateCompatibleDC(dc.m_hDC);
		CBitmap bmpCraft = CreateColorDBIBitmap(dc, rc, 0xffdddddd);

		HBITMAP oldbmpCraft = dcMem.SelectBitmap(bmpCraft);

		//CBrush brush; brush.CreateSolidBrush(0xa2a6a5);
		//dcMem.FillRect(rc, BLACK_BRUSH);
		/**
		* if you fill bitmap(as src to update layered window), don't use AC_SRC_ALPHA, set it to 0.
		* because GDI fill bitmap with color regradless alpha value, in other word, all the pixels are set with 0 alpha value.
		*
		*/
		BLENDFUNCTION blend = { AC_SRC_OVER, 0, 144, AC_SRC_ALPHA };
		BitBlt(dc, 0, 0, rc.Width(), rc.Height(), dcMem, 0, 0, SRCCOPY|CAPTUREBLT);
		GetWindowRect(&rc);
		POINT wndPos = { rc.left, rc.top };
		SIZE wndSize = { rc.Width(), rc.Height() };
		POINT po = { 0, 0 };
		UpdateLayeredWindow(*this, dcscr, &wndPos, &wndSize, dcMem, &po, 0, &blend, ULW_ALPHA);
		dcMem.SelectBitmap(oldbmpCraft);
		return 1;
	}

	LRESULT OnContextMenu(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		UINT ht = DefWindowProc(WM_NCHITTEST, wParam, lParam);
		return 0;
	}

	LRESULT OnNCHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		UINT ht = DefWindowProc(uMsg, wParam, lParam);
		if(HTREDUCE == ht || HTZOOM == ht || HTCLOSE == ht || HTSYSMENU == ht || HTCLIENT == ht)
			ht = HTCAPTION;
		return ht;
	}


	LRESULT OnMoving(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		LPRECT prc = (LPRECT)lParam;
		::MoveWindow(_layerEngineWindow, prc->left, prc->top, prc->right - prc->left, prc->bottom - prc->top, FALSE);
		return 1;
	}

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		// unregister message filtering and idle updates
		if((GetStyle() & (WS_CHILD | WS_POPUP)) == 0)
			::PostQuitMessage(1);

		bHandled = FALSE;
		return 1;
	}

	void SetLayerEngineWindow(HWND hwnd)
	{
		_layerEngineWindow = hwnd;
	}
private:
	CWindow _layerEngineWindow;
};
