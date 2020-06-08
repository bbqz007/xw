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

#ifndef _Z_ZXOC2CPP_H_
#define _Z_ZXOC2CPP_H_

#define PUB public:
#define PRI private:
#define PCT protected:

#define self (*this)

#define _0_property(T, t)	\
	public:	\
	const T& t() { return _##t; }	\
	void set_##t(T& const t1) { _##t = (T)t1; }	\
	protected:	\
	T _##t;

#define _0_property_readonly(T, t)	\
	public:	\
	T t();

#define _0_property_getter(getter, T, t)	\
	public:	\
	const T& getter() { return _##t; }	\
	void set_##t(T& const t1) { _##t = (T)t1; }	\
	protected:	\
	T _##t;

#define _0_property_setter(setter, T, t)	\
	public:	\
	const T& t() { return (const T&)_##t; }	\
	void setter(T& const t1) { _##t = (T const)t1; }	\
	protected:	\
	T _##t;

#define _0_property_getset(getter, setter, T, t)	\
	public:	\
	const T& getter() { return _##t; }	\
	void setter(T& const t1) { _##t = (T)t1; }	\
	protected:	\
	T _##t;

#define _0_property_BOOL(getter, setter, t)	\
	public:	\
	BOOL getter() { return _##t; }	\
	void setter(BOOL const t1) { _##t = (BOOL)t1; }	\
	protected:	\
	BOOL _##t;

#define _0_property_BOOL_setter01(setter, t)	\
	public:	\
	const BOOL& t() { return _##t; }	\
	void setter(BOOL const t1);	\
	protected:	\
	T _##t;

#define _0_property_CGFloat(T, t)	\
	public:	\
	CGFloat t() { return _##t; }	\
	void set_##t(CGFloat const t1) { _##t = (CGFloat)t1; }	\
	protected:	\
	CGFloat _##t;

#define _0_property_setter01(setter, T, t)	\
	public:	\
	const T& t() { return _##t; }	\
	CA_EXTERN void setter(T& const t1);	\
	protected:	\
	T _##t;

//
#define _0_property_pri_pwi_pti(getprop, getter, getimpl, setprop, setter, setimpl, mbrprop, type, member)	\
getprop	type getter##() getimpl	\
setprop	void setter##(type& t1) setimpl	\
mbrprop	type _##member;

// implement getter and setter yourself

#define _0_property_2(T, t)		\
	_0_property_pri_pwi_pti(public:, t, ;, public:, set_##t, ;, protected:, T, t)

// full specify version with six arguments

#define _0_property_ri_wi_ti(getter, getimpl, setter, setimpl, type, member)	\
	_0_property_pri_pwi_pti(public:, getter, getimpl, public:, setter, setimpl, protected:, type, member)

// retain property

#define _0_property_retain(T, t) \
	_0_property_pri_pwi_pti(public:, t, { return (T)_##t->retain()->autorelease(); }, public:, set_##t, { if(_##t != t1) _##t->release(); _##t = (T)t1->retain(); }, protected:, T, t)

// retain property, and you can specify the name of setter

#define _0_property_retain2(setter, T, t) \
	_0_property_pri_pwi_pti(public:, t, { return (T)_##t->retain()->autorelease(); }, public:, setter, { if(_##t != t1) _##t->release(); _##t = (T)t1->retain(); }, protected:, T, t)

// assign property, and you can specify the name of setter

#define _0_property_assign2(setter, T, t) \
	_0_property_pri_pwi_pti(public:, t, { return (T)_##t; }, public:, setter, { _##t = (T)t1; }, protected:, T, t)

#define _00_property(sub, T, t) _00_property2(sub, T, t)
#define _00_property2(sub, getter, setter, T, t)	\
	_00_property2_##sub(getter, setter, T, t)
#define _00_property2_assign(getter, setter, T, t)	\
	_0_property_pri_pwi_pti(public:, t, ;, public:, set_##t, ;, protected:, T, t)
#define _00_property2_assign_getter(getter, setter, T, t)	\
	_0_property_pri_pwi_pti(public:, getter, ;, public:, set_##t, ;, protected:, T, t)
#define _00_property2_assign_setter(getter, setter, T, t)	\
	_0_property_pri_pwi_pti(public:, t, ;, public:, setter, ;, protected:, T, t)
#define _00_property2_assign_getset(getter, setter, T, t)	\
	_0_property_pri_pwi_pti(public:, getter, ;, public:, setter, ;, protected:, T, t)
#define assign_getter(getter) assign_getter, getter, 0
#define assign_setter(setter) assign_setter, 0, 0
#define assign_getset(getter, setter) assign_getset, getter, setter
#define _a_property(sub, T, t)	_a_property2(sub, T, t)
#define _a_property2(sub, getter, getimpl, setter, setimpl, type, member) \
	_a_property2##_sub(getter, getimpl, setter, setimpl, type, member)
//#define assign_getter(getter) assign,getter,;
//#define _a_property2_assign(getter, getimpl, setter, setimpl, type, member)	\
//	_0_property_pri_pwi_pti(public:, getter, getimpl, public:, setter, setimpl, protected:, type, member)



/**
* Variadic Macros
*
*/
#define HELPER_INIT_SUB_NSOBJECTS(...) \
	do { \
		void* subobjs[] = {__VA_ARGS__};		\
		::__initSubNSObjects((NSObject***)subobjs, sizeof(subobjs)/sizeof(NSObject*));		\
	} while (0);

#define HELPER_RELEASE_SUB_NSOBJECTS(...)	\
	do { \
		NSObject* subobjs[] = {__VA_ARGS__};	\
		::__releaseSubNSObjects(subobjs, sizeof(subobjs)/sizeof(NSObject*));	\
	} while (0);

#define CHK_VALID_NSOBJECT(obj) ((obj) && (obj) != ::nilObject)

#endif
