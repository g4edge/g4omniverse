//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//logical.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Logical,
        TfType::Bases< UsdGeomScope > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Logical")
    // to find TfType<G4Logical>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Logical>("Logical");
}

/* virtual */
G4Logical::~G4Logical()
{
}

/* static */
G4Logical
G4Logical::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Logical();
    }
    return G4Logical(stage->GetPrimAtPath(path));
}

/* static */
G4Logical
G4Logical::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Logical");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Logical();
    }
    return G4Logical(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Logical::_GetSchemaKind() const
{
    return G4Logical::schemaKind;
}

/* static */
const TfType &
G4Logical::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Logical>();
    return tfType;
}

/* static */
bool 
G4Logical::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Logical::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Logical::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Logical::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Logical::GetSolidprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solidprim);
}

UsdAttribute
G4Logical::CreateSolidprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solidprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Logical::GetMaterialprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->materialprim);
}

UsdAttribute
G4Logical::CreateMaterialprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->materialprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Logical::GetFieldprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->fieldprim);
}

UsdAttribute
G4Logical::CreateFieldprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->fieldprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Logical::GetSensitiveprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->sensitiveprim);
}

UsdAttribute
G4Logical::CreateSensitiveprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->sensitiveprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Logical::GetLimitsprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->limitsprim);
}

UsdAttribute
G4Logical::CreateLimitsprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->limitsprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Logical::GetDaughtersAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->daughters);
}

UsdAttribute
G4Logical::CreateDaughtersAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->daughters,
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
G4Logical::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->solidprim,
        G4Tokens->materialprim,
        G4Tokens->fieldprim,
        G4Tokens->sensitiveprim,
        G4Tokens->limitsprim,
        G4Tokens->daughters,
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
