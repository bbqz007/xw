### overview
a CAAnimation captures all the animation properties of the layer currently.

change the end properties by specifing values to the CAAnimation.

commit this CAAnimation.

the layer should be in the sublayers tree of [CARootLayer](CARootLayer.md)

### properties of CALayer for animation
1. Frame.

2. opacity.

3. transform matrix.

### example
```
CALayer* layer = ...;
CAAnimation* anime = NSObject::allocT2<CAAnimation>(layer, 2.f /**seconds*/);
anime->setFrame(endFrame);
anime->setAlpha(endAlpha);
anime->translate(endTranslateCTM);
anime->scale(endScaleCTM);
anime->rotate(endRotateCTM);
anime->commit();
```
