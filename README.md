
### Questions
* Stage path to maintain structure?
* References between prims


### Notes
* Logical -> Xform (solid, material, field) 
* Assembly -> Xform (no solid)
* Placement -> Xform (with instance)
* Replica -> Xform (Xform(solid), Xform(solid), Xform(solid)...)
* Division -> Xform (Xform(solid1), Xform(sold2), Xform(solid2)...)
* Parametrised -> Xform (Xform(variant(solid)), Xform(variant(solid)), Xform(variant(solid)) ...)
* Solid -> Mesh 
* Boolean -> Xform (solid1, Xform(solid2), string type)
* MultiUnion -> Xform (Xform(solid1), Xform(solid2), Xform(solid3)... )
* ScaledSolid -> Custom type (derived from VSolid)
* PhysicalMaterial -> Custom type 

* Sensitive detector -> Custom type


### Quick build instructions

* `ln -s g4omniverse/schema openusd/extras/g4`
* edit `extras/CMakeLists.txt` to include g4 directory
* `python build_scripts/build_usd.py ../openusd-build/`
* `python> from pxr import G4`

### Regenerate schema

* `usdGenSchema g4.schema .`

