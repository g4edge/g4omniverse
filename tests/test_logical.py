from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setDefaultBox(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(5)
    box.GetYAttr().Set(5)
    box.GetZAttr().Set(5)

def test_logcial(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_logical.usda")

    l = G4.Logical.Define(stage, "/det_log")

    b1 = G4.Box.Define(stage,"/det_log/det_box")
    setDefaultBox(b1)
    l.GetPrim().GetAttribute("solidprim").Set("det_box")

    return l