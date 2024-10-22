#include "pxr/base/tf/pySafePython.h"
#include "pxr/pxr.h"
#include "pxr/base/tf/pyModule.h"

PXR_NAMESPACE_USING_DIRECTIVE

TF_WRAP_MODULE
{
    TF_WRAP(G4VSolid);  
    TF_WRAP(G4Box);
    TF_WRAP(G4Named);
    TF_WRAP(G4Logical);
    
}
