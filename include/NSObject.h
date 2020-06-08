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

#ifndef _Z_NSObject_H_
#define  _Z_NSObject_H_


/****************************************************\
** author:
**		created by zsl (dennis. China)
**		at 2015.11.2x
\****************************************************/

#include <windows.h>
#include <deque>
#include "class_id.h"
#include "XWExport.h"

struct obj_class;

class NSObject
{
public:
	NS_EXTERN virtual ~NSObject();
	NS_EXTERN NSObject* retain();
	NS_EXTERN void release();
	NS_EXTERN NSObject* autorelease();
	NS_EXTERN operator bool();
public:
	typedef NSObject this_type;
	typedef this_type base;
	static NSObject* alloc() { return new NSObject; }
	template<typename _Ty>
	static _Ty* allocT() { /*return new _Ty;*/NSOBJECTALLOCATOR(_Ty, _Ty); }
	template<typename _Ty, typename _Arg0>
	static _Ty* allocT1(_Arg0 a0) { /*return new typename _Ty(a0);*/NSOBJECTALLOCATOR(_Ty, _Ty(a0)); }
	template<typename _Ty, typename _Arg0, typename _Arg1>
	static _Ty* allocT2(_Arg0 a0, _Arg1 a1) { /*return new typename _Ty(a0, a1);*/NSOBJECTALLOCATOR2(_Ty, a0, a1); }
protected:
	NS_EXTERN NSObject();
protected:
	LONG _retainCount;
#ifndef _WIN64
	INT32 _retainCountEven64;
#endif
	obj_class* obj_class;
	friend struct obj_class;
	NS_EXTERN void operator delete(void*);
private:
	NS_EXTERN void* operator new(size_t);
	NS_EXTERN void drill();
};

//#define nilObject getNilObject()
//NS_EXTERN NSObject* getNilObject();
extern "C" NS_EXTERN NSObject* nilObject;

inline NSObject::operator bool()
{
	return this != nilObject;
}

NS_EXTERN void __initSubNSObjects(NSObject*** objs, size_t count);
//void __initSubNSObjects(NSObject*& objs[], size_t count);		// error C2234 引用数组是非法的
NS_EXTERN void __releaseSubNSObjects(NSObject** objs, size_t count);

#include "ZXOC2CPP.h"






#endif
