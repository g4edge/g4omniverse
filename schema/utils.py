from pxr import G4

def add_listeners(stage) :
    for x in stage.Traverse() :
        print(x.GetName(),x.GetTypeName())
        if x.GetTypeName() == "MultiUnion" :
            G4.MultiUnion(x).InstallUpdateListener()
        elif x.GetTypeName() == "DisplacedSolid" :
            G4.DisplacedSolid(x).InstallUpdateListener()
        elif x.GetTypeName() == "Box" :
            G4.Box(x).InstallUpdateListener()
        elif x.GetTypeName() == "Union"  :
            G4.Union(x).InstallUpdateListener()
        elif x.GetTypeName() == "Subtraction" :
            G4.Subtraction(x).InstallUpdateListener()
        elif x.GetTypeName() == "Intersection" :
            G4.Intersection(x).InstallUpdateListener()
        else :
            print("Not found", x.GetName(), x.GetTypeName())


