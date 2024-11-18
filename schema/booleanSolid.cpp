//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//booleanSolid.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4BooleanSolid,
        TfType::Bases< UsdGeomScope > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("BooleanSolid")
    // to find TfType<G4BooleanSolid>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4BooleanSolid>("BooleanSolid");
}

/* virtual */
G4BooleanSolid::~G4BooleanSolid()
{
}

/* static */
G4BooleanSolid
G4BooleanSolid::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4BooleanSolid();
    }
    return G4BooleanSolid(stage->GetPrimAtPath(path));
}

/* static */
G4BooleanSolid
G4BooleanSolid::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("BooleanSolid");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4BooleanSolid();
    }
    return G4BooleanSolid(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4BooleanSolid::_GetSchemaKind() const
{
    return G4BooleanSolid::schemaKind;
}

/* static */
const TfType &
G4BooleanSolid::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4BooleanSolid>();
    return tfType;
}

/* static */
bool 
G4BooleanSolid::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4BooleanSolid::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4BooleanSolid::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4BooleanSolid::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4BooleanSolid::GetSolid1primAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solid1prim);
}

UsdAttribute
G4BooleanSolid::CreateSolid1primAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solid1prim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4BooleanSolid::GetSolid2primAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solid2prim);
}

UsdAttribute
G4BooleanSolid::CreateSolid2primAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solid2prim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4BooleanSolid::GetSolid3primAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solid3prim);
}

UsdAttribute
G4BooleanSolid::CreateSolid3primAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solid3prim,
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
G4BooleanSolid::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->solid1prim,
        G4Tokens->solid2prim,
        G4Tokens->solid3prim,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdGeomScope::GetSchemaAttributeNames(true),
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
