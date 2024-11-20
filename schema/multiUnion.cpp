//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//multiUnion.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4MultiUnion,
        TfType::Bases< UsdGeomScope > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("MultiUnion")
    // to find TfType<G4MultiUnion>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4MultiUnion>("MultiUnion");
}

/* virtual */
G4MultiUnion::~G4MultiUnion()
{
}

/* static */
G4MultiUnion
G4MultiUnion::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4MultiUnion();
    }
    return G4MultiUnion(stage->GetPrimAtPath(path));
}

/* static */
G4MultiUnion
G4MultiUnion::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("MultiUnion");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4MultiUnion();
    }
    return G4MultiUnion(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4MultiUnion::_GetSchemaKind() const
{
    return G4MultiUnion::schemaKind;
}

/* static */
const TfType &
G4MultiUnion::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4MultiUnion>();
    return tfType;
}

/* static */
bool 
G4MultiUnion::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4MultiUnion::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4MultiUnion::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4MultiUnion::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4MultiUnion::GetSolidprimsAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solidprims);
}

UsdAttribute
G4MultiUnion::CreateSolidprimsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solidprims,
                       SdfValueTypeNames->StringArray,
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
G4MultiUnion::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->solidprims,
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
