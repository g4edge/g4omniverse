//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//vSolid.h"
#include "pxr/usd/usd/schemaBase.h"

#include "pxr/usd/sdf/primSpec.h"

#include "pxr/usd/usd/pyConversions.h"
#include "pxr/base/tf/pyContainerConversions.h"
#include "pxr/base/tf/pyResultConversions.h"
#include "pxr/base/tf/pyUtils.h"
#include "pxr/base/tf/wrapTypeHelpers.h"

#include "pxr/external/boost/python.hpp"

#include <string>

PXR_NAMESPACE_USING_DIRECTIVE

using namespace pxr_boost::python;

namespace {

#define WRAP_CUSTOM                                                     \
    template <class Cls> static void _CustomWrapCode(Cls &_class)

// fwd decl.
WRAP_CUSTOM;

        
static UsdAttribute
_CreateNameAttr(G4VSolid &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateNameAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}
        
static UsdAttribute
_CreateG4typeAttr(G4VSolid &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateG4typeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}
        
static UsdAttribute
_CreateLength_unitAttr(G4VSolid &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLength_unitAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}
        
static UsdAttribute
_CreateAngle_unitAttr(G4VSolid &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateAngle_unitAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}

static std::string
_Repr(const G4VSolid &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "G4.VSolid(%s)",
        primRepr.c_str());
}

} // anonymous namespace

void wrapG4VSolid()
{
    typedef G4VSolid This;

    class_<This, bases<UsdGeomMesh> >
        cls("VSolid");

    cls
        .def(init<UsdPrim>(arg("prim")))
        .def(init<UsdSchemaBase const&>(arg("schemaObj")))
        .def(TfTypePythonClass())

        .def("Get", &This::Get, (arg("stage"), arg("path")))
        .staticmethod("Get")

        .def("GetSchemaAttributeNames",
             &This::GetSchemaAttributeNames,
             arg("includeInherited")=true,
             return_value_policy<TfPySequenceToList>())
        .staticmethod("GetSchemaAttributeNames")

        .def("_GetStaticTfType", (TfType const &(*)()) TfType::Find<This>,
             return_value_policy<return_by_value>())
        .staticmethod("_GetStaticTfType")

        .def(!self)

        
        .def("GetNameAttr",
             &This::GetNameAttr)
        .def("CreateNameAttr",
             &_CreateNameAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetG4typeAttr",
             &This::GetG4typeAttr)
        .def("CreateG4typeAttr",
             &_CreateG4typeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLength_unitAttr",
             &This::GetLength_unitAttr)
        .def("CreateLength_unitAttr",
             &_CreateLength_unitAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetAngle_unitAttr",
             &This::GetAngle_unitAttr)
        .def("CreateAngle_unitAttr",
             &_CreateAngle_unitAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))

        .def("__repr__", ::_Repr)
    ;

    _CustomWrapCode(cls);
}

// ===================================================================== //
// Feel free to add custom code below this line, it will be preserved by 
// the code generator.  The entry point for your custom code should look
// minimally like the following:
//
// WRAP_CUSTOM {
//     _class
//         .def("MyCustomMethod", ...)
//     ;
// }
//
// Of course any other ancillary or support code may be provided.
// 
// Just remember to wrap code in the appropriate delimiters:
// 'namespace {', '}'.
//
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

namespace {

WRAP_CUSTOM {
//  _class
//      .def("IsOutputAffected",&G4VSolid::IsOutputAffected);
}

}
