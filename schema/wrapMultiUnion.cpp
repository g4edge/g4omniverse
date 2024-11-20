//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//multiUnion.h"
#include "pxr/usd/usd/schemaBase.h"

#include "pxr/usd/sdf/primSpec.h"

#include "pxr/usd/usd/pyConversions.h"
#include "pxr/base/tf/pyContainerConversions.h"
#include "pxr/base/tf/pyResultConversions.h"
#include "pxr/base/tf/pyUtils.h"
#include "pxr/base/tf/wrapTypeHelpers.h"

#include <boost/python.hpp>

#include <string>

using namespace boost::python;

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

#define WRAP_CUSTOM                                                     \
    template <class Cls> static void _CustomWrapCode(Cls &_class)

// fwd decl.
WRAP_CUSTOM;

        
static UsdAttribute
_CreateG4typeAttr(G4MultiUnion &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateG4typeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}
        
static UsdAttribute
_CreateSolidprimsAttr(G4MultiUnion &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSolidprimsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->StringArray), writeSparsely);
}
        
static UsdAttribute
_CreateTranslationsAttr(G4MultiUnion &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateTranslationsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double3Array), writeSparsely);
}
        
static UsdAttribute
_CreateRotationsAttr(G4MultiUnion &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRotationsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Double3Array), writeSparsely);
}
        
static UsdAttribute
_CreateSolid3primAttr(G4MultiUnion &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSolid3primAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}

static std::string
_Repr(const G4MultiUnion &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "G4.MultiUnion(%s)",
        primRepr.c_str());
}

} // anonymous namespace

void wrapG4MultiUnion()
{
    typedef G4MultiUnion This;

    class_<This, bases<UsdGeomScope> >
        cls("MultiUnion");

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
        
        .def("GetSolidprimsAttr",
             &This::GetSolidprimsAttr)
        .def("CreateSolidprimsAttr",
             &_CreateSolidprimsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetTranslationsAttr",
             &This::GetTranslationsAttr)
        .def("CreateTranslationsAttr",
             &_CreateTranslationsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRotationsAttr",
             &This::GetRotationsAttr)
        .def("CreateRotationsAttr",
             &_CreateRotationsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSolid3primAttr",
             &This::GetSolid3primAttr)
        .def("CreateSolid3primAttr",
             &_CreateSolid3primAttr,
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
}

}
