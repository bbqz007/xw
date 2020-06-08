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

/*********************************\
** author:
**		created by zsl (dennis. China)
**		at 2015.12.14
**
\*********************************/

#ifndef _Z_NSObjectCoreRuntime_H_
#define _Z_NSObjectCoreRuntime_H_

#define bit_available 1
#define bit_isweak 2
#define bit_canweak 3

#include "XWExport.h"

struct NS_EXTERN obj_class
{
	ULONG_PTR class_id;
	LONG refCount;
	void* obj;
	LONG weakCount;
	LONG flags;
	void deleteObject(void* obj);
	obj_class* objOfObject(void* obj);
};

NS_EXTERN void obj_class_init(obj_class*);
NS_EXTERN void* obj_class_get();
NS_EXTERN void obj_class_put(obj_class*);
NS_EXTERN void* obj_class_retain(obj_class*);
NS_EXTERN void* obj_class_weak_retain(obj_class*);
NS_EXTERN void* obj_class_release(obj_class*);
NS_EXTERN void obj_class_weak_release(obj_class*);
NS_EXTERN void* obj_class_weak_lock(obj_class*);


#endif
