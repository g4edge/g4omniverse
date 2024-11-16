from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setDefaultBox(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(10)
    box.GetYAttr().Set(10)
    box.GetZAttr().Set(10)

def setDefaultBox2(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(2.5)
    box.GetYAttr().Set(2.5)
    box.GetZAttr().Set(11)

def setXform(prim, pos = [0,0,0], rot = [0,0,0]) :
    # Transformation
    xform = UsdGeom.Xformable(prim)
    # Translation
    xform.AddTranslateOp().Set(Gf.Vec3d(*pos))
    # Rotate
    xform.AddRotateZYXOp().Set(Gf.Vec3d(*rot))



def test_booleantree(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_booleantree.usda")

    s1 = G4.Subtraction.Define(stage,"/s1")
    s1_solid2 = G4.DisplacedSolid.Define(stage,"/s1/solid2")
    s2 = G4.Subtraction.Define(stage,"/s1/solid2/s2")
    s2_solid2_= G4.DisplacedSolid.Define(stage,"/s1/solid2/s2/solid2")

    s2_solid1 = G4.Box.Define(stage, "/s1/solid2/s2/solid1")
    setDefaultBox(s2_solid1)

    s2_solid2_s = G4.Box.Define(stage, "/s1/solid2/s2/solid2/solid")
    setDefaultBox2(s2_solid2_s)

    s2_result = UsdGeom.Mesh.Define(stage,"/s1/solid2/s2/result")

    s2.GetSolid1primAttr().Set("solid1")
    s2.GetSolid2primAttr().Set("solid2")
    s2.GetSolid3primAttr().Set("result")

    s1_solid1 = G4.Box.Define(stage, "/s1/solid1")
    setDefaultBox2(s1_solid1)
    s2_result = UsdGeom.Mesh.Define(stage,"/s1/result")

    setXform(s1_solid2.GetPrim(), [0, 0, 0], [90, 0, 0])

    s1.GetSolid1primAttr().Set("solid1")
    s1.GetSolid2primAttr().Set("s2")
    s1.GetSolid3primAttr().Set("result")

    s2.Update()
    # s1.Update()

    return s1

    #stage.Save()
