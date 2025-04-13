#include "pxr/base/tf/pySafePython.h"
#include "pxr/pxr.h"
#include "pxr/base/tf/pyModule.h"

PXR_NAMESPACE_USING_DIRECTIVE

TF_WRAP_MODULE
{
    TF_WRAP(G4VSolid);  
    TF_WRAP(G4Box);
    TF_WRAP(G4Tubs);
    TF_WRAP(G4Cons);
    TF_WRAP(G4Orb);
    TF_WRAP(G4BooleanSolid);
    TF_WRAP(G4DisplacedSolid);
    TF_WRAP(G4Union);
    TF_WRAP(G4Intersection);
    TF_WRAP(G4Subtraction);
    TF_WRAP(G4MultiUnion);
    TF_WRAP(G4Logical);
    TF_WRAP(G4Placement);
    TF_WRAP(G4Assembly);
}
