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

#ifndef _Z_CAAnimation_H_
#define _Z_CAAnimation_H_

#include "CALayer.h"

class CA_EXTERN CAAnimation : public NSObject
{
public:
	virtual ~CAAnimation();
	void animeWithLayer(CALayer*);
	static CAAnimation* beginAnimating(CALayer* animeLayer, CGFloat dura);
	void setFrame(const CGRect& frame);
	void setAlpha(const CGFloat alpha);
	void translate(CGFloat tx, CGFloat ty);
	void scale(CGFloat sx, CGFloat sy);
	void rotate(CGFloat angle);
	void commit();
	ULONG_PTR hash();
	BOOL isExpired();
	BOOL isActivate();
protected:
	friend class NSObject;
	CAAnimation(CALayer* animeLayer, CGFloat dura);
private:
	CAAnimation();
protected:
	BOOL _commited;
	CGRect _beginFrame;
	CGFloat _beginAlpha;
	CGAffineTransform _beginTransform;
	long _beginTime;
	long _duration;
	CGRect _endFrame;
	CGFloat _endAlpha;
	NSArray* _endTransforms;
	CALayer* _animeLayer;
};

CA_EXTERN CAAnimation* queryAnimating(CALayer* animeLayer);
CA_EXTERN void removeAnimating(CAAnimation* anime);
CA_EXTERN void buildActivateAnimations();
CA_EXTERN void commitAnimating(CAAnimation* anime);
#endif
