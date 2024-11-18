from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setBox(box, x = 5, y = 5, z =5 ) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(x)
    box.GetYAttr().Set(y)
    box.GetZAttr().Set(z)

def setXform(prim, pos = [0,0,0], rot = [0,0,0]) :
    # Transformation
    xform = UsdGeom.Xformable(prim)
    # Translation
    xform.AddTranslateOp().Set(Gf.Vec3d(*pos))
    # Rotate
    xform.AddRotateZYXOp().Set(Gf.Vec3d(*rot))

def test_subtraction_reference(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_subtraction_reference.usda")

    sub1 = G4.Subtraction.Define(stage,       "/sub1")
    solid1 = G4.Box.Define(stage,             "/sub1/solid1")
    solid2d = G4.DisplacedSolid.Define(stage, "/sub1/solid2")
    solid2s = G4.Box.Define(stage,            "/sub1/solid2/box")
    solid2s.GetPrim().GetReferences().AddInternalReference(solid1.GetPrim().GetPath())

    result  = UsdGeom.Mesh.Define(stage,      "/sub1/result")

    setBox(solid1, 10,10,10 )
    # setBox(solid2s, 10, 10, 10)
    setXform(solid2d.GetPrim(), [10, 10, 10], [45, 0, 0])
    sub1.GetSolid1primAttr().Set("solid1")
    sub1.GetSolid2primAttr().Set("solid2")
    sub1.GetSolid3primAttr().Set("result")

    sub1.Update()

    stage.Save()

    return sub1

