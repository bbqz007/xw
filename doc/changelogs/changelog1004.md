# implement
* CATextLayer::Opaque

# bugfixed
* CATextLayer::font

### Opaque
when `Opaque` is set to `TRUE`，alpha and antialias are ignored. the CoreAnimation module choose a speed first policy to draw text.

if your `CGContext` is scaling, this `CATextLayer` would ignore the `Opaque`。

### font
in the old version, the size of font would be changed because of the different DPIs. 

now the size is confirmed to the standard DPI.

if you want to scale the dpi to scale the size of font, you should do it by yourself to calc the scaled size of font.
