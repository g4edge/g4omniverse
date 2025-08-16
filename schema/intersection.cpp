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
        TfType::Bases< G4BooleanSolid > >();
    
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

UsdAttribute
G4Intersection::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Intersection::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
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
G4Intersection::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            G4BooleanSolid::GetSchemaAttributeNames(true),
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
#include <iostream>
#include "cgal_boolean.h"
#include "pxr/usd/usd/notice.h"

class IntersectionChangeListener : public pxr::TfWeakBase {
public:
    IntersectionChangeListener(pxr::G4Intersection intersection) : _intersection(intersection) {
        // Register the listener for object changes
        pxr::TfNotice::Register(pxr::TfCreateWeakPtr<IntersectionChangeListener>(this),
                                &IntersectionChangeListener::Update);
    }

    void Update(const pxr::UsdNotice::ObjectsChanged &notice) {
        if (_intersection.IsInputAffected(notice))
            _intersection.Update();
    }

private:
    pxr::G4Intersection _intersection;
};

void pxr::G4Intersection::Update() {
    g4usdboolean(this->GetPrim(), INTERSECTION);
}

void pxr::G4Intersection::InstallUpdateListener() {
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<IntersectionChangeListener>(new IntersectionChangeListener(*this)),
                            &IntersectionChangeListener::Update);
}
