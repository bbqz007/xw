### Overview
a `CATextLayer` help you to write animation of text.

easy way to scale, rotate, translate the text.

easy way to change alpha of the text.

easy way to set alignment in bounds of `CALayer`.

easy way to set font and size.

easy way to layout and locate.

transparent background by default.

### properties
* font
  *  size (point)
  *  name
* string
* color
* alignments
  *  kCAAlignmentLeft
  *  kCAAlignmentCenter
  *  kCAAlignmentRight
  *  kCAAlignmentVerticalCenter

### animation base
jsut animated the text rather than change value.

by default, the `CATextLayer` supports a backing store to help to animate the text.

### value base
change value always rather than animated it.

disable the backing store by hand. otherwise, it brings to a bad perfermance.

if your text just simply show string and neither scale nor rotate nor alpha, you can set the `opaque` to TRUE to tell the CoreAnimation module to do more simply.
