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

#ifndef _Z_NSString_H_
#define _Z_NSString_H_

/****************************************************\
** author:
**		created by zsl (dennis. China)
**		at 2015.12.26
\****************************************************/
#include "NSObject.h"
#include "NSObjectRuntime.h"
#include "NSRange.h"

enum {
    NSASCIIStringEncoding = 1,		/* 0..127 only */
    NSUnicodeStringEncoding = 10,

    NSUTF16StringEncoding = NSUnicodeStringEncoding,      /* An alias for NSUnicodeStringEncoding */
};

typedef NSUInteger NSStringEncoding;

class NS_EXTERN NSString : public NSObject
{
public:
	typedef NSString this_type;
	typedef NSObject base;

	~NSString();
	NSString();

	NSString(const char* nullTerminatedCString, NSStringEncoding encoding = NSUnicodeStringEncoding);
	NSString(NSString* aString);
	NSString(NSString* format, va_list argptr);

	static NSString* string();
	static NSString* stringWithCString(const char* nullTerminatedCString, NSStringEncoding encoding = NSUnicodeStringEncoding);
	static NSString* stringWithString(NSString* string);
	static NSString* stringWithFormat(NSString* format, ...);

	_0_property_readonly(NSUInteger,	length);
	unichar characterAtIndex(NSUInteger index);

	void getCharacters(unichar* buffer, NSRange aRange);

	NSString* substringFromIndex(NSUInteger from);
	NSString* substringToIndex(NSUInteger to);
	NSString* substringWithRange(NSRange range);

	BOOL isEqualToString(NSString* aString);
	BOOL hasPrefix(NSString* aString);
	BOOL hasSuffix(NSString* aString);

	NSString* stringByAppendingString(NSString* aString);
	NSString* stringByAppendingFormat(NSString* format, ...);

	_0_property_readonly(NSUInteger,	hash);

	const char* cStringUsingEncoding(NSStringEncoding encoding = NSUnicodeStringEncoding);

protected:
	friend class NSString;
	void* _impl;
};

#endif
