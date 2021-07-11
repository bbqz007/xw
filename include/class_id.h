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

#ifndef _Z_class_id_H_
#define _Z_class_id_H_

/****************************************************\
** author:
**		written by zsl at 2015.12.17
** aim:
**		to implement the isKindOfClass
**
\****************************************************/

#include "XWExport.h"

NS_EXTERN void class_id_build(ULONG_PTR* id, ULONG_PTR base_id);
NS_EXTERN void class_id_bind(void* obj, ULONG_PTR class_id);

//
//
//
template<typename _Ty>
struct _xx_class_id
{
	ULONG_PTR id;
	_xx_class_id()
	{
		ULONG_PTR base_id = class_id_get<_Ty::base>();
		class_id_build(&id, base_id);
	}
};

#if 0
class NSObject;
template<>
_xx_class_id<NSObject>::_xx_class_id()
{
	class_id_build(&id, 0);
}
#endif

template<typename _Ty> inline
ULONG_PTR class_id_get()
{
	static _xx_class_id<_Ty> __xx_class_id;
	return __xx_class_id.id;
}

//// Z@20210707
//// be very careful!!!
//// we can not use any global static _xx_class_id object.
//// that would make any constructures while dll is loading before main
//// singleton pattern can delay the constructures, but make calls
//// so i make the static _xx_class_id ctor call singleton getter
////	which fire singleton _xx_class_id ctor build unique one time,
//// singleton's pointer is stored into a static pointer.

#define NS_EXPORT_CLASS_ID(_Ty)	\
template<> \
struct _xx_class_id<_Ty>	\
{	\
	NS_EXTERN static _xx_class_id<_Ty>* unique_id;	\
	NS_EXTERN static _xx_class_id<_Ty>& get_unique_id();		\
	ULONG_PTR id;	\
	_xx_class_id()	\
	{		\
		unique_id = &get_unique_id();	\
	}	\
	_xx_class_id(int)	\
	{	\
		ULONG_PTR base_id = class_id_get<_Ty::base>();	\
		class_id_build(&id, base_id);	\
	}	\
};	\
template<> inline 	\
ULONG_PTR class_id_get<_Ty>() 	\
{	\
	static _xx_class_id<_Ty> unique_id_init_entrance;	\
	return _xx_class_id<_Ty>::unique_id->id;	\
}


#pragma section(".xx_class_id", read, write)

#define NS_DEFINE_CLASS_ID(_Ty)	\
_xx_class_id<_Ty>& _xx_class_id<_Ty>::get_unique_id()	\
{	\
	static _xx_class_id<_Ty> _inst(0);	\
	return _inst;	\
}	\
__declspec(allocate(".xx_class_id")) _xx_class_id<_Ty>* _xx_class_id<_Ty>::unique_id = 0;


class NSObject;
template<> 
struct _xx_class_id<NSObject>	
{	
	NS_EXTERN static _xx_class_id<NSObject>* unique_id;
	NS_EXTERN static _xx_class_id<NSObject>& get_unique_id();
	ULONG_PTR id;	
	_xx_class_id()	
	{		
		unique_id = &get_unique_id();	
	}	
	_xx_class_id(int)	
	{	
		class_id_build(&id, 0);	
	}	
};	

template<> 	inline
ULONG_PTR class_id_get<NSObject>()
{	
	static _xx_class_id<NSObject> unique_id_init_entrance;
	return _xx_class_id<NSObject>::unique_id->id;
}

NS_EXTERN BOOL obj_isKindOfClass(void* obj, ULONG_PTR class_id);

template<typename _Ty>
BOOL isKindOfClass(NSObject* obj)
{
	ULONG_PTR tmp = class_id_get<_Ty>();
	return obj_isKindOfClass(obj, tmp);
}

//
//
//
#define NSOBJECTALLOCATOR_BEGIN(Ty)	\
	ULONG_PTR tmp = class_id_get<Ty>();
#define NSOBJECTALLOCATOR_END	\
	class_id_bind(((NSObject*)p)->obj_class, tmp);	\
	return p;

#define NSOBJECTALLOCATOR(Ty, ctor)	NSOBJECTALLOCATOR_BEGIN(Ty)	Ty* p = new ctor; NSOBJECTALLOCATOR_END
#define NSOBJECTALLOCATOR2(Ty, a0, a1)	NSOBJECTALLOCATOR_BEGIN(Ty)	Ty* p = new Ty(a0, a1); NSOBJECTALLOCATOR_END

#define NSBaseClassID(T) public: typedef T base;

#endif
