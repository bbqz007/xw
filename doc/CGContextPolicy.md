* CGContextPolicyForceSpeed
* CGContextPolicyPreferSpeed
* CGContextPolicyDefault

-----------------
any smoothing and antialias, alpha color as well, would need eat some more preformance.

when you stroke or fill, `CGContextPolicyForceSpeed()` help you to ignore any smoothing and antialias filters, alpha color as well.

`CGContextPolicyPreferSpeed()` let the CoreAnimation module determine the policy, as long as there are not any smoothing and antialias and alpha color.

`CGContextPolicyDefault()` is the original policy.



* `CGContextPolicyBalance()`

-----------------
the `CGContextPolicyForceSpeed()`, `CGContextPolicyPreferSpeed()` and `CGContextPolicyDefault()` are manual policies.

`CGContextPolicyBalance()` is the automate policy that make good performance when you use alpha, smoothing, antialias and any other advanced features.

once you call `CGContextPolicyBalance()`, other subsequential policy changings would be ignore.

you should  call `CGContextPolicyBalance()` after the `CGContext`'s constructure and before you use it. otherwise all things are unexpected.

