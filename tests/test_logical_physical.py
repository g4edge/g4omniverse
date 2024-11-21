from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setDefaultBox(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(10)
    box.GetYAttr().Set(10)
    box.GetZAttr().Set(10)

def setDefaultBox2(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(1)
    box.GetYAttr().Set(1)
    box.GetZAttr().Set(1)

def test_logcial_physical(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_logical_physical.usda")

    l = G4.Logical.Define(stage, "/det_log")

    b1 = G4.Box.Define(stage,"/det_log/det_box")
    setDefaultBox(b1)
    l.GetPrim().GetAttribute("solidprim").Set("det_box")

    p1 = G4.Physical.Define(stage, "/det_log/det_phys1")
    p2 = G4.Physical.Define(stage, "/det_log/det_phys2")
    p3 = G4.Physical.Define(stage, "/det_log/det_phys3")
    l.GetPrim().GetAttribute("daughters").Set(["det_phys1","det_phys2","det_phys3"])
    p1.InstallUpdateListener()
    p2.InstallUpdateListener()
    p3.InstallUpdateListener()

    p1.GetTranslationAttr().Set((-5,0,0,))
    p3.GetTranslationAttr().Set(( 5,0,0,))

    #setXform(p1, [-5,0,0,],[0,0,0])
    #setXform(p3, [ 5,0,0,],[0,0,0])

    l2 = G4.Logical.Define(stage,"/det_log/det_phys1/sub_log")
    l2_solid =  G4.Box.Define(stage,"/det_log/det_phys1/sub_log/sub_box")

    l3 = G4.Logical.Define(stage,"/det_log/det_phys2/sub_log")
    l4 = G4.Logical.Define(stage,"/det_log/det_phys3/sub_log")

    l3.GetPrim().GetReferences().AddReference("", l2.GetPrim().GetPath())
    l4.GetPrim().GetReferences().AddReference("", l2.GetPrim().GetPath())

    setDefaultBox2(l2_solid)

    return l