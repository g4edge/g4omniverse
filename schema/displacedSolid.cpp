//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//displacedSolid.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4DisplacedSolid,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("DisplacedSolid")
    // to find TfType<G4DisplacedSolid>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4DisplacedSolid>("DisplacedSolid");
}

/* virtual */
G4DisplacedSolid::~G4DisplacedSolid()
{
}

/* static */
G4DisplacedSolid
G4DisplacedSolid::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4DisplacedSolid();
    }
    return G4DisplacedSolid(stage->GetPrimAtPath(path));
}

/* static */
G4DisplacedSolid
G4DisplacedSolid::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("DisplacedSolid");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4DisplacedSolid();
    }
    return G4DisplacedSolid(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4DisplacedSolid::_GetSchemaKind() const
{
    return G4DisplacedSolid::schemaKind;
}

/* static */
const TfType &
G4DisplacedSolid::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4DisplacedSolid>();
    return tfType;
}

/* static */
bool 
G4DisplacedSolid::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4DisplacedSolid::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4DisplacedSolid::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4DisplacedSolid::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
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
G4DisplacedSolid::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdGeomXform::GetSchemaAttributeNames(true),
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
