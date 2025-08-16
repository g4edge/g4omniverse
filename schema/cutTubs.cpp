//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//cutTubs.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4CutTubs,
        TfType::Bases< G4Tubs > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("CutTubs")
    // to find TfType<G4CutTubs>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4CutTubs>("CutTubs");
}

/* virtual */
G4CutTubs::~G4CutTubs()
{
}

/* static */
G4CutTubs
G4CutTubs::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4CutTubs();
    }
    return G4CutTubs(stage->GetPrimAtPath(path));
}

/* static */
G4CutTubs
G4CutTubs::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("CutTubs");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4CutTubs();
    }
    return G4CutTubs(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4CutTubs::_GetSchemaKind() const
{
    return G4CutTubs::schemaKind;
}

/* static */
const TfType &
G4CutTubs::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4CutTubs>();
    return tfType;
}

/* static */
bool 
G4CutTubs::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4CutTubs::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4CutTubs::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4CutTubs::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4CutTubs::GetPLowNormAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->pLowNorm);
}

UsdAttribute
G4CutTubs::CreatePLowNormAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->pLowNorm,
                       SdfValueTypeNames->Double3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4CutTubs::GetPHighNormAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->pHighNorm);
}

UsdAttribute
G4CutTubs::CreatePHighNormAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->pHighNorm,
                       SdfValueTypeNames->Double3,
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
G4CutTubs::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->pLowNorm,
        G4Tokens->pHighNorm,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            G4Tubs::GetSchemaAttributeNames(true),
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
