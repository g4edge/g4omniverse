//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//cons.h"
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
_CreateG4typeAttr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateG4typeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}
        
static UsdAttribute
_CreateRMin1Attr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRMin1Attr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double), writeSparsely);
}
        
static UsdAttribute
_CreateRMax1Attr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRMax1Attr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double), writeSparsely);
}
        
static UsdAttribute
_CreateRMin2Attr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRMin2Attr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double), writeSparsely);
}
        
static UsdAttribute
_CreateRMax2Attr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRMax2Attr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double), writeSparsely);
}
        
static UsdAttribute
_CreateZAttr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateZAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double), writeSparsely);
}
        
static UsdAttribute
_CreateSPhiAttr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSPhiAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double), writeSparsely);
}
        
static UsdAttribute
_CreateDPhiAttr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDPhiAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double), writeSparsely);
}
        
static UsdAttribute
_CreateNsliceAttr(G4Cons &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateNsliceAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}

static std::string
_Repr(const G4Cons &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "G4.Cons(%s)",
        primRepr.c_str());
}

} // anonymous namespace

void wrapG4Cons()
{
    typedef G4Cons This;

    class_<This, bases<G4VSolid> >
        cls("Cons");

    cls
        .def(init<UsdPrim>(arg("prim")))
        .def(init<UsdSchemaBase const&>(arg("schemaObj")))
        .def(TfTypePythonClass())

        .def("Get", &This::Get, (arg("stage"), arg("path")))
        .staticmethod("Get")

        .def("Define", &This::Define, (arg("stage"), arg("path")))
        .staticmethod("Define")

        .def("GetSchemaAttributeNames",
             &This::GetSchemaAttributeNames,
             arg("includeInherited")=true,
             return_value_policy<TfPySequenceToList>())
        .staticmethod("GetSchemaAttributeNames")

        .def("_GetStaticTfType", (TfType const &(*)()) TfType::Find<This>,
             return_value_policy<return_by_value>())
        .staticmethod("_GetStaticTfType")

        .def(!self)

        
        .def("GetG4typeAttr",
             &This::GetG4typeAttr)
        .def("CreateG4typeAttr",
             &_CreateG4typeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRMin1Attr",
             &This::GetRMin1Attr)
        .def("CreateRMin1Attr",
             &_CreateRMin1Attr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRMax1Attr",
             &This::GetRMax1Attr)
        .def("CreateRMax1Attr",
             &_CreateRMax1Attr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRMin2Attr",
             &This::GetRMin2Attr)
        .def("CreateRMin2Attr",
             &_CreateRMin2Attr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRMax2Attr",
             &This::GetRMax2Attr)
        .def("CreateRMax2Attr",
             &_CreateRMax2Attr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetZAttr",
             &This::GetZAttr)
        .def("CreateZAttr",
             &_CreateZAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSPhiAttr",
             &This::GetSPhiAttr)
        .def("CreateSPhiAttr",
             &_CreateSPhiAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetDPhiAttr",
             &This::GetDPhiAttr)
        .def("CreateDPhiAttr",
             &_CreateDPhiAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetNsliceAttr",
             &This::GetNsliceAttr)
        .def("CreateNsliceAttr",
             &_CreateNsliceAttr,
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
     _class
     .def("Update",&G4Cons::Update)
     .def("InstallUpdateListener",&G4Cons::InstallUpdateListener);
}

}
