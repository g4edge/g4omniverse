

### Introduction

USD is a modern composition file format used by 3D workflows.
It is increasing being used in engineering/physics applications 
via NVIDIA Omniverse. 

![Example of usdview of G4-USD](./public/images/intro_image.png)

### Aims

1. Renderble USD file
2. Direct load to Geant4
3. As similar structure as GDML/G4

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

