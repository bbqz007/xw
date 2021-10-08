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
template<class T> class __autoreleasing;

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
	template<typename _Ty>
	static __autoreleasing<_Ty> allocAndAutoreleasingT();
	template<typename _Ty, typename _Arg0>
	static __autoreleasing<_Ty> allocAndAutoreleasingT1(_Arg0 a0);
	template<typename _Ty, typename _Arg0, typename _Arg1>
	static __autoreleasing<_Ty> allocAndAutoreleasingT2(_Arg0 a0, _Arg1 a1);
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
private:
	NS_EXTERN_DELEETE NSObject(const NSObject&);
	NS_EXTERN_DELEETE NSObject& operator=(const NSObject&);
};

//#define nilObject getNilObject()
//NS_EXTERN NSObject* getNilObject();
extern "C" NS_EXTERN NSObject* const nilObject;

inline NSObject::operator bool()
{
	return this != nilObject;
}

NS_EXTERN void __initSubNSObjects(NSObject*** objs, size_t count);
//void __initSubNSObjects(NSObject*& objs[], size_t count);		// error C2234 引用数组是非法的
NS_EXTERN void __releaseSubNSObjects(NSObject** objs, size_t count);

#include "ZXOC2CPP.h"

/****************************************************\
** author:
**		extended by zsl (dennis. China)
**		at 2021.07.xx
\****************************************************/

template<class T1, class Base>
struct zhelper_assert_nsobject2 : public zhelper_assert_nsobject2<typename Base, typename Base::base>
{

};

template<class T1>
struct zhelper_assert_nsobject2<T1, T1>
{
private:
	virtual void compilerErorYourClassIsNotNSObject() = 0;
};

template<class T>
struct zhelper_assert_nsobject
{
	typedef typename zhelper_assert_nsobject2<typename T, typename T::base> value;
};

template<>
struct zhelper_assert_nsobject2<NSObject, NSObject>
{
	typedef NSObject result;
};

#define HELPER_ASSERT_NSOBJECT(Class) zhelper_assert_nsobject<Class>::value ___assert_your_class_is_a_NSObject___;

#define nil (nilObject)

class __strong_obj
{
protected:
	NSObject* _obj;
protected:
	~__strong_obj()
	{
		_obj->release();
	}
	__strong_obj()
		: _obj(nilObject)
	{

	}
	__strong_obj(NSObject* obj)
		: _obj(obj->retain())
	{

	}
	template <class T>
	__strong_obj(NSObject* obj, /**__unused*/ __autoreleasing<T>*)
		: _obj(obj)
	{

	}
public:
	bool operator == (NSObject* other) const
	{
		return _obj == other;
	}
	bool operator == (const __strong_obj& other) const
	{
		return _obj == other._obj;
	}
	bool operator != (NSObject* other) const
	{
		return _obj != other;
	}
	bool operator != (const __strong_obj& other) const
	{
		return _obj != other._obj;
	}
};

inline 
bool operator == (NSObject* other, const __strong_obj& strong)
{
	return strong == other;
}

inline
bool operator != (NSObject* other, const __strong_obj& strong)
{
	return strong != other;
}

template<class T> class __weak;

template<class T>
class __strong : public __strong_obj
{
public:
	~__strong()
	{
		HELPER_ASSERT_NSOBJECT(T);
	}
	__strong() : __strong_obj()
	{

	}
	__strong(T* obj)
		: __strong_obj(reinterpret_cast<NSObject*>(obj))
	{

	}
	__strong(__strong& other)
		: __strong_obj(reinterpret_cast<NSObject*>(other._obj))
	{

	}
	__strong(const __strong& other)
		: __strong_obj(reinterpret_cast<NSObject*>(other._obj))
	{

	}
	__strong(__weak<typename T>&);
	__strong(__autoreleasing<typename T>&);
	__strong(const __autoreleasing<typename T>&);
	__strong& operator = (T* obj)
	{
		_obj->release();
		_obj = reinterpret_cast<NSObject*>(obj)->retain();
		return *this;
	}
	__strong& operator = (__strong& other)
	{
		_obj->release();
		_obj = other._obj->retain();
		return *this;
	}
	__strong& operator = (__weak<typename T>&);
	__strong& operator = (__autoreleasing<typename T>&);

	T* operator -> ()
	{
		return reinterpret_cast<T*>(_obj);
	}
	operator bool()
	{
		return NULL != _obj && nil != _obj;
	}
	friend class __weak<typename T>;
};

template<class T>
class __autoreleasing : public __strong_obj
{
public:
	~__autoreleasing()
	{
		HELPER_ASSERT_NSOBJECT(T);
	}
	__autoreleasing() : __strong_obj()
	{

	}
	__autoreleasing(T* obj)
		: __strong_obj(reinterpret_cast<NSObject*>(obj), this)
	{

	}
	__autoreleasing& operator = (T* obj)
	{
		_obj->release();
		_obj = obj;
		return *this;
	}
	T* operator -> ()
	{
		return reinterpret_cast<T*>(_obj);
	}
	operator bool()
	{
		return NULL != _obj && nil != _obj;
	}
	friend class __strong<typename T>;
	friend class NSObject;
private:
	__autoreleasing(__autoreleasing& other)
	{
		_obj = other._obj;
		other._obj = nil;
	}
	__autoreleasing(const __autoreleasing&);
	__autoreleasing(__strong<typename T>& other);
	__autoreleasing(const __strong<typename T>& other);
	__autoreleasing(__weak<typename T>&);
	__autoreleasing& operator = (__strong<typename T>& other);
	__autoreleasing& operator = (__weak<typename T>&);
	void operator delete(void*);
	void* operator new(size_t);
};

class NS_EXTERN __weak_obj
{
protected:
	obj_class* _obj;
protected:
	~__weak_obj();
	__weak_obj();
	__weak_obj(NSObject*);
	__weak_obj(obj_class*);
	NSObject* lock();
	void assign(NSObject*);
	void assign(obj_class*);
};

template<class T>
class __weak : public __weak_obj
{
public:
	~__weak()
	{
		HELPER_ASSERT_NSOBJECT(T);
	}
	__weak()
		: __weak_obj()
	{

	}
	__weak(T* obj)
		: __weak_obj(reinterpret_cast<NSObject*>(obj))
	{

	}
	__weak(__weak& other)
		: __weak_obj(other._obj)
	{

	}
	__weak(__strong<typename T>& strong)
		: __weak(reinterpret_cast<NSObject*>(strong._obj))
	{

	}
	__weak(__autoreleasing<typename T>& strong)
		: __weak(reinterpret_cast<NSObject*>(strong._obj))
	{

	}
	__weak& operator = (T* obj)
	{
		assign(reinterpret_cast<NSObject*>(obj));
		return *this;
	}
	__weak& operator = (__weak& other)
	{
		assign(other._obj);
		return *this;
	}
	__weak& operator = (__strong<typename T>& strong)
	{
		assign(reinterpret_cast<NSObject*>(strong._obj));
		return *this;
	}
	__weak& operator = (__autoreleasing<typename T>& strong)
	{
		assign(reinterpret_cast<NSObject*>(strong._obj));
		return *this;
	}
	friend class __strong<typename T>;
};


template<class T>
inline
__strong<T>::__strong(__weak<typename T>& weak)
{
	_obj = weak.lock();
}

template<class T>
inline
__strong<T>::__strong(__autoreleasing<typename T>& other)
	: __strong_obj(reinterpret_cast<NSObject*>(other._obj))
{

}

template<class T>
inline
__strong<T>::__strong(const __autoreleasing<typename T>& other)
	: __strong_obj(reinterpret_cast<NSObject*>(other._obj))
{

}

template<class T>
inline
__strong<T>& __strong<T>::operator = (__weak<typename T>& weak)
{
	_obj->release();
	_obj = weak.lock();
	return *this;
}

template<class T>
inline
__strong<T>& __strong<T>::operator = (__autoreleasing<typename T>& other)
{
	_obj->release();
	_obj = other._obj->retain();
	return *this;
}

template<typename _Ty>
inline
__autoreleasing<_Ty> NSObject::allocAndAutoreleasingT() { return __autoreleasing<_Ty>(NSObject::allocT<_Ty>()); }
template<typename _Ty, typename _Arg0>
inline
__autoreleasing<_Ty> NSObject::allocAndAutoreleasingT1(_Arg0 a0) { return __autoreleasing<_Ty>(NSObject::allocT1<_Ty>(a0)); }
template<typename _Ty, typename _Arg0, typename _Arg1>
inline
__autoreleasing<_Ty> NSObject::allocAndAutoreleasingT2(_Arg0 a0, _Arg1 a1) { return __autoreleasing<_Ty>(NSObject::allocT2<_Ty>(a0, a1)); }

#endif
