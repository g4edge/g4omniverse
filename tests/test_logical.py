from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setDefaultBox(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(5)
    box.GetYAttr().Set(5)
    box.GetZAttr().Set(5)


def setXform(prim, pos = [0,0,0], rot = [0,0,0]) :
    # Transformation
    xform = UsdGeom.Xformable(prim)
    # Translation
    xform.AddTranslateOp().Set(Gf.Vec3d(*pos))
    # Rotate
    xform.AddRotateZYXOp().Set(Gf.Vec3d(*rot))



def test_logcial(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_logical.usda")

    l = G4.Logical.Define(stage, "/det_log")

    b1 = G4.Box.Define(stage,"/det_log/det_box")
    setDefaultBox(b1)
    l.GetPrim().GetAttribute("solidprim").Set("det_box")

    return l