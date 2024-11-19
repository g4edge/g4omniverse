
### Introduction

![image](./public/images/intro_image.png)

### Quick build instructions

* clone openusd `git clone https://github.com/PixarAnimationStudios/OpenUSD.git `
* clone g4omniverse `git clone https://github.com/g4edge/g4omniverse.git`
* `cd openusd`
* `ln -s ../g4omniverse/schema openusd/extras/g4`
* edit `extras/CMakeLists.txt` to include g4 directory
* `python build_scripts/build_usd.py ../openusd-build/`
* `python> from pxr import G4`

### Regenerate schema

* `usdGenSchema g4.schema .`

