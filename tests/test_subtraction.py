from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setDefaultBox(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(5)
    box.GetYAttr().Set(5)
    box.GetZAttr().Set(5)

def setDefaultBox2(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(2)
    box.GetYAttr().Set(2)
    box.GetZAttr().Set(2)

def setXform(prim, pos = [0,0,0], rot = [0,0,0]) :
    # Transformation
    xform = UsdGeom.Xformable(prim)
    # Translation
    xform.AddTranslateOp().Set(Gf.Vec3d(*pos))
    # Rotate
    xform.AddRotateZYXOp().Set(Gf.Vec3d(*rot))



def test_subtraction(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_subtraction.usda")

    s = G4.Subtraction.Define(stage, "/s1")

    b1 = G4.Box.Define(stage, "/s1/b1")
    b1m = UsdGeom.Mesh.Define(stage,"/s1/s1result")

    setDefaultBox(b1)
    x = G4.DisplacedSolid.Define(stage, "/s1/solid2")
    b2 = G4.Box.Define(stage, "/s1/solid2/b2")
    setDefaultBox2(b2)
    setXform(x.GetPrim(), [5, 5, 5], [45, 0, 0])
    s.GetSolid1primAttr().Set("b1")
    s.GetSolid2primAttr().Set("solid2")
    s.GetSolid3primAttr().Set("s1result")

    s.Update()

    stage.Save()

    return s

