from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setBox(box, x = 5, y = 5, z =5 ) :
    box.GetXAttr().Set(x)
    box.GetYAttr().Set(y)
    box.GetZAttr().Set(z)

def test_multiunion(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_multiunion.usda")

    mu = G4.MultiUnion.Define(stage, "/mu")

    d1 = G4.DisplacedSolid.Define(stage,"/mu/solid1")
    d2 = G4.DisplacedSolid.Define(stage,"/mu/solid2")
    d3 = G4.DisplacedSolid.Define(stage,"/mu/solid3")
    d4 = G4.DisplacedSolid.Define(stage,"/mu/solid4")

    b1 = G4.Box.Define(stage,"/mu/solid1/b1")
    b2 = G4.Box.Define(stage,"/mu/solid2/b2")
    b3 = G4.Box.Define(stage,"/mu/solid3/b3")
    b4 = G4.Box.Define(stage,"/mu/solid4/b3")

    mur = UsdGeom.Mesh.Define(stage,"/mu/result")

    b1.InstallUpdateListener()
    b2.InstallUpdateListener()
    b3.InstallUpdateListener()
    b4.InstallUpdateListener()

    setBox(b1,10,10, 10)
    setBox(b2,8,8, 8)
    setBox(b3,6,6, 6)
    setBox(b4,4,4, 4)

    d1.InstallUpdateListener()
    d2.InstallUpdateListener()
    d3.InstallUpdateListener()
    d4.InstallUpdateListener()

    d1.GetTranslationAttr().Set((0,0,0))
    d1.GetRotationAttr().Set((0,0,0))

    d2.GetTranslationAttr().Set((10,10,10))
    d2.GetRotationAttr().Set((0,0,0))

    d3.GetTranslationAttr().Set((18,18,18))
    d3.GetRotationAttr().Set((0,0,0))

    d4.GetTranslationAttr().Set((24,24,24))
    d4.GetRotationAttr().Set((0,0,0))

    # mu.InstallUpdateListener()
    mu.GetTranslationsAttr().Set(((0,0,0),
                                  (10,10,10),
                                  (18,18,18),
                                  (24,24,24)))
    mu.GetRotationsAttr().Set(((0,0,0),
                               (0,0,0),
                               (0,0,0),
                               (0,0,0)))
    mu.GetSolidprimsAttr().Set(["solid1","solid2","solid3","solid4"])
    mu.GetSolid3primAttr().Set("result")





