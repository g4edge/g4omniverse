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
        TfType::Bases< UsdGeomMesh > >();
    
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

/*static*/
const TfTokenVector&
G4Logical::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames;
    static TfTokenVector allNames =
        UsdGeomMesh::GetSchemaAttributeNames(true);

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
