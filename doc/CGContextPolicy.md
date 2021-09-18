* `CGContextPolicyBalance()`

the `CGContextPolicyForceSpeed()`, `CGContextPolicyPreferSpeed()` and `CGContextPolicyDefault()` are manual policies.

`CGContextPolicyBalance()` is the automate policy that make good performance when you use alpha, smoothing, antialias and any other advanced features.

once you call `CGContextPolicyBalance()`, other subsequential policy changings would be ignore.

you should  call `CGContextPolicyBalance()` after the `CGContext`'s constructure and before you use it. otherwise all things are unexpected.

