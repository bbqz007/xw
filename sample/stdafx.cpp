// stdafx.cpp : source file that includes just the standard includes
//	XW.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#if (_ATL_VER < 0x0700)
#include <atlimpl.cpp>
#endif //(_ATL_VER < 0x0700)

struct tagARGBBWBITMAPINFO
{
	BITMAPINFOHEADER bmiHeader; 
	RGBQUAD bmiColors[4]; 
};

static tagARGBBWBITMAPINFO argbBWBitmapInfo = 
{
	{ sizeof(BITMAPINFOHEADER), 0, 0, 1, 32, BI_RGB, 0, 2834, 2834, 0, 0 },
	{ { 0x00, 0xFF, 0x00, 0x00 }, { 0x00, 0xFF, 0xFF, 0xFF }, { 0x00, 0x00, 0x00, 0xFF }, { 0xFF, 0x00, 0x00, 0x00 } }
};

const LPBITMAPINFO ARGBBWBITMAPINFO = (const LPBITMAPINFO)&argbBWBitmapInfo;

