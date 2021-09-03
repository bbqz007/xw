/**
MIT License
Copyright (c) 2015-2021 bbqz007 <https://github.com/bbqz007, http://www.cnblogs.com/bbqzsl>
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

#ifndef __Z_NSDispatcher_H_
#define __Z_NSDispatcher_H_

#ifdef _MSC_VER
#if _MSC_VER > 1600
#include <functional>
#include <deque>
#include <vector>
#include <mutex>

#include <Windows.h>
#include "NSObject.h"

#define WM_NS_DIPATCH_NOTIRY (WM_USER + 100000)

class NS_EXTERN NSDispatcher : public NSObject
{
	NSBaseClassID(NSObject)
public:
	~NSDispatcher();
	NSDispatcher(HWND hwnd, const size_t max = 1 << 10);
	size_t dispatch_async(const std::function<void(void)>& cont);
	int process_dispatch_on_message(WPARAM wParam, LPARAM lParam);
	static int process_dispatch_on_message(HWND hwnd, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
protected:
	void* priv_;
	uintptr_t reseverd_;
};

NS_EXPORT_CLASS_ID(NSDispatcher)

#define NS_CAN_USE_NSDispatcher 1

#else
class NS_EXTERN NSDispatcher : public NSObject
{
protected:
	void* priv_;
	uintptr_t reseverd_;
};

#endif	// _MSC_VER
#endif	// _MSC_VER

#endif // __Z_NSDispatcher_H_
