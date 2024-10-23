//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//subtraction.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Subtraction,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Subtraction")
    // to find TfType<G4Subtraction>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Subtraction>("Subtraction");
}

/* virtual */
G4Subtraction::~G4Subtraction()
{
}

/* static */
G4Subtraction
G4Subtraction::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Subtraction();
    }
    return G4Subtraction(stage->GetPrimAtPath(path));
}

/* static */
G4Subtraction
G4Subtraction::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Subtraction");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Subtraction();
    }
    return G4Subtraction(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Subtraction::_GetSchemaKind() const
{
    return G4Subtraction::schemaKind;
}

/* static */
const TfType &
G4Subtraction::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Subtraction>();
    return tfType;
}

/* static */
bool 
G4Subtraction::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Subtraction::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
G4Subtraction::GetSchemaAttributeNames(bool includeInherited)
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
