//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//vSolid.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4VSolid,
        TfType::Bases< UsdGeomMesh > >();
    
}

/* virtual */
G4VSolid::~G4VSolid()
{
}

/* static */
G4VSolid
G4VSolid::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4VSolid();
    }
    return G4VSolid(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind G4VSolid::_GetSchemaKind() const
{
    return G4VSolid::schemaKind;
}

/* static */
const TfType &
G4VSolid::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4VSolid>();
    return tfType;
}

/* static */
bool 
G4VSolid::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4VSolid::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4VSolid::GetNameAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->name);
}

UsdAttribute
G4VSolid::CreateNameAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->name,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4VSolid::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4VSolid::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4VSolid::GetLength_unitAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->length_unit);
}

UsdAttribute
G4VSolid::CreateLength_unitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->length_unit,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4VSolid::GetAngle_unitAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->angle_unit);
}

UsdAttribute
G4VSolid::CreateAngle_unitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->angle_unit,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
G4VSolid::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->name,
        G4Tokens->g4type,
        G4Tokens->length_unit,
        G4Tokens->angle_unit,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdGeomMesh::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

#include <iostream>

bool pxr::G4VSolid::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  return true;
}

bool pxr::G4VSolid::IsOutputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {

    return notice.AffectedObject(this->GetPointsAttr()) ||
           notice.AffectedObject(this->GetFaceVertexCountsAttr()) ||
           notice.AffectedObject(this->GetFaceVertexIndicesAttr());
}

