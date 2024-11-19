from pxr import Usd, UsdGeom, Gf,Sdf
def run() :
    stage = Usd.Stage.CreateNew("simple_usd_example.usda")

    xform = UsdGeom.Xform.Define(stage,"/transformation")
    cube = UsdGeom.Cube.Define(stage,"/transformation/cube")

    xform = UsdGeom.Xformable(xform)
    xform.AddTranslateOp().Set(Gf.Vec3d(1,2,3))
    xform.AddRotateZYXOp().Set(Gf.Vec3d(0,0,45))

    cube.GetPrim().GetAttribute("size").Set(1)

    stage.Save()