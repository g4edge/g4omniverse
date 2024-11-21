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
        stage = Usd.Stage.CreateNew("test_booleantree1.usda")

    sub1 = G4.Subtraction.Define(stage,            "/sub1")
    sub1_solid1 = G4.Subtraction.Define(stage,     "/sub1/solid1")
    sub1_solid2d = G4.DisplacedSolid.Define(stage, "/sub1/solid2")
    sub1_solid2s = G4.Box.Define(stage,            "/sub1/solid2/box")
    sub1_result = UsdGeom.Mesh.Define(stage,       "/sub1/result")

    sub1.GetSolid1primAttr().Set("solid1")
    sub1.GetSolid2primAttr().Set("solid2")
    sub1.GetSolid3primAttr().Set("result")

    setDefaultBox2(sub1_solid2s)
    sub1_solid2d.InstallUpdateListener()
    sub1_solid2d.GetTranslationAttr().Set((0,0,0))
    sub1_solid2d.GetRotationAttr().Set((90,0,0))

    sub2_solid1 = G4.Box.Define(stage,            "/sub1/solid1/solid1")
    sub2_solid2d = G4.DisplacedSolid.Define(stage,"/sub1/solid1/solid2")
    sub2_solid2s = G4.Box.Define(stage,           "/sub1/solid1/solid2/box")
    sub2_result = UsdGeom.Mesh.Define(stage,      "/sub1/solid1/result")

    sub1_solid1.GetSolid1primAttr().Set("solid1")
    sub1_solid1.GetSolid2primAttr().Set("solid2")
    sub1_solid1.GetSolid3primAttr().Set("result")

    setDefaultBox(sub2_solid1)
    setDefaultBox2(sub2_solid2s)
    sub2_solid2d.InstallUpdateListener()
    sub2_solid2d.GetTranslationAttr().Set((0,0,0))
    sub2_solid2d.GetRotationAttr().Set((0,0,0))

    sub1_solid1.Update()
    sub1.Update()
