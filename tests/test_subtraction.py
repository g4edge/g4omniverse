from pxr import Usd, UsdGeom, Gf,Sdf, G4


def defaultBox(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(5)
    box.GetYAttr().Set(5)
    box.GetZAttr().Set(5)

def test_subtraction() :
    # make subtraction
    stage = Usd.Stage.CreateNew("test_subtraction.usda")

    s = G4.Subtraction.Define(stage, "/s1")

    b1 = G4.Box.Define(stage, "/s1/b1")
    defaultBox(b1)
    x = UsdGeom.Xform.Define(stage, "/s1/solid2")
    b2 = G4.Box.Define(stage, "/s1/solid2/b2")
    defaultBox(b2)

    stage.Save()

