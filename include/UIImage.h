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

#ifndef _Z_UIImage_H_
#define _Z_UIImage_H_

#include "NSObject.h"
#include "CoreGraphics.h"

typedef enum {
	UIImageOrientationUp,            // default orientation
    UIImageOrientationDown,          // 180 deg rotation
    UIImageOrientationLeft,          // 90 deg CCW
    UIImageOrientationRight,         // 90 deg CW
    UIImageOrientationUpMirrored,    // as above but image mirrored along other axis. horizontal flip
    UIImageOrientationDownMirrored,  // horizontal flip
    UIImageOrientationLeftMirrored,  // vertical flip
    UIImageOrientationRightMirrored, // vertical flip
} UIImageOrientation;

typedef enum {
	UIImageResizingModeTile,
    UIImageResizingModeStretch,
} UIImageResizingMode;

typedef enum {
	UIImageRenderingModeAutomatic,          // Use the default rendering mode for the context where the image is used

    UIImageRenderingModeAlwaysOriginal,     // Always draw the original image, without treating it as a template
    UIImageRenderingModeAlwaysTemplate,     // Always draw the image as a template image, ignoring its color information
} UIImageRenderingMode;

class NSData;
class UIImage : public NSObject
{
public:
	typedef NSString this_type;
	typedef NSObject base;

	~UIImage();

	static UIImage* imageNamed(NSString* name);
	static UIImage* imageWithContentsOfFile(NSString* path);
	static UIImage* imageWithData(NSData* data);

	_0_property_readonly(CGSize,	size);


	void drawAtPoint(CGPoint point);
	void drawAtPoint(CGPoint point, CGBlendMode blendMode, CGFloat alpha);
	void drawInRect(CGRect rect);
	void drawInRect(CGRect rect, CGBlendMode blendMode, CGFloat alpha);

	void darwAsPatternInRect:(CGRect rect);
protected:
	UIImage();
	UIImage* initWithNamed(NSString* name);
	UIImage* initWithContentsOfFile(NSString* path);
	UIImage* initWithData(NSData* data);

private:
	void* _imageRef;
	CGFloat _scale;
	struct {
	unsigned int named:1;
	unsigned int imageOrientation:3;
	unsigned int cached:1;
	unsigned int hasPattern:1;
	unsigned int isCIImage:1;
	unsigned int renderingMode:2;
        unsigned int suppressesAccessibilityHairlineThickening:1;
        unsigned int hasDecompressionInfo:1;
    } _imageFlags;
};
#endif
