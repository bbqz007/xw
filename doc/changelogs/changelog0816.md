implement CGGradient

### classes
* CGGradient

### api
* CGContextDrawRadialGradient(CGContextRef, CGGradientRef, CGPoint startCenter, CGFloat startRadius, CGPoint endCenter, CGFloat endRadius, CGGradientDrawingOptions)
  * this function fill a cycle with the radial gradient .
  * the cycle is at the absolute endCenter, and its radius is endRadius.
  * the startCenter indicates the beginning of the center of the radial gradient, 
  * while endCenter and endRadius indicate a cycle which is the end of the surround of the radial gradient.
  * the path of CGContext will clip what this function draw.
* CGContextDrawLinearGradient(CGContextRef, CGGradientRef, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions)
  * the vector <startPoint, endPoint> indicates how the linear gradient directs and distance of one cycle of gradient.
  * fill the path of CGContext with the linear gradient.
### example
```c++
{
				CGFloat radius = 50.f;
				CGRect fillrc(40.f, 300.f, radius * 2, radius * 2);
				CGPoint offset(-20.f, -30.f);
				CGPoint endPoint(CGRectGetMidX(fillrc), CGRectGetMidY(fillrc)), startPoint = endPoint + offset;
				CGColor clrs[] = { CGColor::AliceBlue, CGColor::Aquamarine };
				CGFloat locations[] = { 0.f, 1.f };
				CGGradient gradient(clrs, locations, sizeof(clrs) / sizeof(CGColor));
				CGContextBeginPath(ctx);
				CGContextAddEllipseInRect(ctx, fillrc);
				CGContextDrawRadialGradient(ctx, &gradient, startPoint, 0.f, endPoint, radius, CGGradientDrawingOptions::kCGGradientDrawsAfterStartLocation);
}
```

```c++
{
				CGPoint startPoint(640.f, 140.f), endPoint(440.f, 40.f);
				CGColor clrs[] = { CGColor::Red, CGColor::Green, CGColor::Blue };
				CGFloat locations[] = { 0.f, .6f, 1.f };
				CGGradient gradient(clrs, locations, sizeof(clrs) / sizeof(CGColor));
				CGContextBeginPath(ctx);
				CGContextAddRect(ctx, CGRect(440.f, 40.f, 400.f, 200.f));
				CGContextDrawLinearGradient(ctx, &gradient, startPoint, endPoint, CGGradientDrawingOptions::kCGGradientDrawsAfterStartLocation);
}
```















