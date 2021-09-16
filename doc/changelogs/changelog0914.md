## implement
* CGContextPolicyForceSpeed
* CGContextPolicyPreferSpeed
* CGContextPolicyDefault

-----------------
any smoothing and antialias, alpha color as well, would need eat some more preformance.

when you stroke or fill, `CGContextPolicyForceSpeed()` help you to ignore any smoothing and antialias filters, alpha color as well.

`CGContextPolicyPreferSpeed()` let the CoreAnimation module determine the policy, as long as there are not any smoothing and antialias and alpha color.

`CGContextPolicyDefault()` is the original policy.
