//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//tubs.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Tubs,
        TfType::Bases< UsdGeomMesh > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Tubs")
    // to find TfType<G4Tubs>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Tubs>("Tubs");
}

/* virtual */
G4Tubs::~G4Tubs()
{
}

/* static */
G4Tubs
G4Tubs::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Tubs();
    }
    return G4Tubs(stage->GetPrimAtPath(path));
}

/* static */
G4Tubs
G4Tubs::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Tubs");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Tubs();
    }
    return G4Tubs(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Tubs::_GetSchemaKind() const
{
    return G4Tubs::schemaKind;
}

/* static */
const TfType &
G4Tubs::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Tubs>();
    return tfType;
}

/* static */
bool 
G4Tubs::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Tubs::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Tubs::GetR1Attr() const
{
    return GetPrim().GetAttribute(G4Tokens->r1);
}

UsdAttribute
G4Tubs::CreateR1Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->r1,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Tubs::GetR2Attr() const
{
    return GetPrim().GetAttribute(G4Tokens->r2);
}

UsdAttribute
G4Tubs::CreateR2Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->r2,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Tubs::GetZAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->z);
}

UsdAttribute
G4Tubs::CreateZAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->z,
                       SdfValueTypeNames->Double,
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
G4Tubs::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->r1,
        G4Tokens->r2,
        G4Tokens->z,
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
