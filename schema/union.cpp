//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//union.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Union,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Union")
    // to find TfType<G4Union>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Union>("Union");
}

/* virtual */
G4Union::~G4Union()
{
}

/* static */
G4Union
G4Union::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Union();
    }
    return G4Union(stage->GetPrimAtPath(path));
}

/* static */
G4Union
G4Union::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Union");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Union();
    }
    return G4Union(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Union::_GetSchemaKind() const
{
    return G4Union::schemaKind;
}

/* static */
const TfType &
G4Union::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Union>();
    return tfType;
}

/* static */
bool 
G4Union::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Union::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
G4Union::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames;
    static TfTokenVector allNames =
        UsdGeomXform::GetSchemaAttributeNames(true);

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
