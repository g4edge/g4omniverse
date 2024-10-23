//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//intersection.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Intersection,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Intersection")
    // to find TfType<G4Intersection>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Intersection>("Intersection");
}

/* virtual */
G4Intersection::~G4Intersection()
{
}

/* static */
G4Intersection
G4Intersection::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Intersection();
    }
    return G4Intersection(stage->GetPrimAtPath(path));
}

/* static */
G4Intersection
G4Intersection::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Intersection");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Intersection();
    }
    return G4Intersection(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Intersection::_GetSchemaKind() const
{
    return G4Intersection::schemaKind;
}

/* static */
const TfType &
G4Intersection::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Intersection>();
    return tfType;
}

/* static */
bool 
G4Intersection::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Intersection::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
G4Intersection::GetSchemaAttributeNames(bool includeInherited)
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
