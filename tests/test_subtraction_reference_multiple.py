from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setBox(box, x = 5, y = 5, z =5 ) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(x)
    box.GetYAttr().Set(y)
    box.GetZAttr().Set(z)

def test_subtraction_reference_multiple(stage = None) :
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
    solid2d.InstallUpdateListener()
    solid2d.GetTranslationAttr().Set((10,10,10))
    solid2d.GetRotationAttr().Set((45,0,0))
    sub1.GetSolid1primAttr().Set("solid1")
    sub1.GetSolid2primAttr().Set("solid2")
    sub1.GetSolid3primAttr().Set("result")

    sub1.Update()

    uni1         = G4.Union.Define(stage,          "/uni1")
    uni1_solid1  = G4.Box.Define(stage,            "/uni1/solid1")
    uni1_solid1.GetPrim().GetReferences().AddInternalReference(solid1.GetPrim().GetPath())
    uni1_solid2  = G4.DisplacedSolid.Define(stage, "/uni1/solid2")
    uni1_solid2s = G4.Box.Define(stage,            "/uni1/solid2/box")
    uni1_solid2s.GetPrim().GetReferences().AddInternalReference(solid1.GetPrim().GetPath())

    result  = UsdGeom.Mesh.Define(stage,      "/uni1/result")

    uni1_solid2.InstallUpdateListener()
    uni1_solid2.GetTranslationAttr().Set((10,10,10))
    uni1_solid2.GetRotationAttr().Set((45,45,45))
    uni1.GetSolid1primAttr().Set("solid1")
    uni1.GetSolid2primAttr().Set("solid2")
    uni1.GetSolid3primAttr().Set("result")

    uni1.Update()

    stage.Save()

    return sub1

