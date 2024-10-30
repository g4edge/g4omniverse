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

UsdAttribute
G4Union::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Union::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
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
G4Union::GetSchemaAttributeNames(bool includeInherited)
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

#include <iostream>
#include "pxr/usd/usd/notice.h"

class UnionChangeListener : public pxr::TfWeakBase {
public:
  UnionChangeListener(pxr::G4Union un1on) : _union(un1on) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<UnionChangeListener>(this),
                            &UnionChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
    std::cout << "updated" << " " << std::endl;
    _union.Update();
  }

private:
  pxr::G4Union _union;
};

void pxr::G4Union::Update() {
  std::cout << "pxr::G4Union::Update()" << std::endl;

  // get children (solid1 and solid2)

  // convert mesh to cgal meshes

  // execute transformation on second mesh

  // perform union

  // convert mesh back to usd mesh

  // update parents


}

void pxr::G4Union::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<UnionChangeListener>(new UnionChangeListener(*this)),
                          &UnionChangeListener::Update);
}
