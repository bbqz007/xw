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
protected:
	void* priv_;
};

NS_EXPORT_CLASS_ID(NSDispatcher)

#endif	// _MSC_VER
#endif	// _MSC_VER

#endif // __Z_NSDispatcher_H_
