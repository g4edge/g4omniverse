
### Questions
* Stage path to maintain structure?
* References between prims


### Notes
* Logical -> some collection or container
  * Needs a solid
* Assembly -> some collection or container 
* Placement -> XForm
* Solid -> Mesh
* PhysicalMaterial ->


### Quick build instructions

* `ln -s g4omniverse/schema openusd/extras/g4`
* edit `extras/CMakeLists.txt` to include g4 directory
* `python build_scripts/build_usd.py ../openusd-build/`
* `python> from pxr import G4`


