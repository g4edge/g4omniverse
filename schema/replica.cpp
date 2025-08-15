//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//replica.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Replica,
        TfType::Bases< UsdGeomScope > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Replica")
    // to find TfType<G4Replica>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Replica>("Replica");
}

/* virtual */
G4Replica::~G4Replica()
{
}

/* static */
G4Replica
G4Replica::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Replica();
    }
    return G4Replica(stage->GetPrimAtPath(path));
}

/* static */
G4Replica
G4Replica::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Replica");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Replica();
    }
    return G4Replica(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Replica::_GetSchemaKind() const
{
    return G4Replica::schemaKind;
}

/* static */
const TfType &
G4Replica::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Replica>();
    return tfType;
}

/* static */
bool 
G4Replica::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Replica::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Replica::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Replica::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Replica::GetLogicalprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->logicalprim);
}

UsdAttribute
G4Replica::CreateLogicalprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->logicalprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Replica::GetMotherprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->motherprim);
}

UsdAttribute
G4Replica::CreateMotherprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->motherprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Replica::GetAxisAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->axis);
}

UsdAttribute
G4Replica::CreateAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->axis,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Replica::GetNreplicasAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->nreplicas);
}

UsdAttribute
G4Replica::CreateNreplicasAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->nreplicas,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Replica::GetWidthAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->width);
}

UsdAttribute
G4Replica::CreateWidthAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->width,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Replica::GetOffsetAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->offset);
}

UsdAttribute
G4Replica::CreateOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->offset,
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
G4Replica::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->logicalprim,
        G4Tokens->motherprim,
        G4Tokens->axis,
        G4Tokens->nreplicas,
        G4Tokens->width,
        G4Tokens->offset,
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
