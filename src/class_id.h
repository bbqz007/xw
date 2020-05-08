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

void class_id_build(ULONG_PTR* id, ULONG_PTR base_id);
void class_id_bind(void* obj, ULONG_PTR class_id);

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

class NSObject;
template<>
_xx_class_id<NSObject>::_xx_class_id()
{
	class_id_build(&id, 0);
}

template<typename _Ty>
ULONG_PTR class_id_get()
{
	static _xx_class_id<_Ty> __xx_class_id;
	return __xx_class_id.id;
}

BOOL obj_isKindOfClass(void* obj, ULONG_PTR class_id);

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

#endif
