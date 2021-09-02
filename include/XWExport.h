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

#ifndef _XW_EXPORT__H_
#define _XW_EXPORT__H_


#ifdef BUILD_DLL
#define XWEXPORT __declspec(dllexport)
#else
#define XWEXPORT __declspec(dllimport)
#endif

#define NS_EXTERN XWEXPORT
#define CA_EXTERN XWEXPORT

/// Z#20210902
class CA_EXTERN CoreAnimationModule
{
public:
	CoreAnimationModule();
	~CoreAnimationModule();
	uintptr_t _reserved[4];
};
#ifndef BUILD_DLL
__declspec(selectany) CoreAnimationModule ____CoreAnimationModule;
#endif

#endif // _XW_EXPORT__H_
