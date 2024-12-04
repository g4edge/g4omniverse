//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//multiUnion.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4MultiUnion,
        TfType::Bases< UsdGeomScope > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("MultiUnion")
    // to find TfType<G4MultiUnion>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4MultiUnion>("MultiUnion");
}

/* virtual */
G4MultiUnion::~G4MultiUnion()
{
}

/* static */
G4MultiUnion
G4MultiUnion::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4MultiUnion();
    }
    return G4MultiUnion(stage->GetPrimAtPath(path));
}

/* static */
G4MultiUnion
G4MultiUnion::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("MultiUnion");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4MultiUnion();
    }
    return G4MultiUnion(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4MultiUnion::_GetSchemaKind() const
{
    return G4MultiUnion::schemaKind;
}

/* static */
const TfType &
G4MultiUnion::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4MultiUnion>();
    return tfType;
}

/* static */
bool 
G4MultiUnion::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4MultiUnion::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4MultiUnion::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4MultiUnion::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4MultiUnion::GetSolidprimsAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solidprims);
}

UsdAttribute
G4MultiUnion::CreateSolidprimsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solidprims,
                       SdfValueTypeNames->StringArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4MultiUnion::GetSolid3primAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solid3prim);
}

UsdAttribute
G4MultiUnion::CreateSolid3primAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solid3prim,
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
G4MultiUnion::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->solidprims,
        G4Tokens->solid3prim,
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

#include <iostream>
#include "cgal_boolean.h"
#include "displacedSolid.h"
#include "pxr/usd/usd/notice.h"

class MultiUnionChangeListener : public pxr::TfWeakBase {
public:
  MultiUnionChangeListener(pxr::G4MultiUnion un1on) : _union(un1on) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<MultiUnionChangeListener>(this),
                            &MultiUnionChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
    std::cout << "updated" << " " << std::endl;
    if(_union.IsInputAffected(notice)) {
      _union.Update();
    }
  }

private:
  pxr::G4MultiUnion _union;
};

void pxr::G4MultiUnion::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<MultiUnionChangeListener>(new MultiUnionChangeListener(*this)),
                          &MultiUnionChangeListener::Update);
}

void pxr::G4MultiUnion::Update() {
  std::cout << "pxr::G4MultiUnion::Update()" << std::endl;
  g4usdboolean_multiunion(this->GetPrim());
}

bool pxr::G4MultiUnion::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  std::cout << "G4MultiUnion::IsInputAffected> ";
  for(auto path : notice.GetChangedInfoOnlyPaths()) {
    std::cout << path << " " ;
  }

  bool update = false;
  // check if displaced solids are updated
  for(auto it = this->GetPrim().GetChildren().begin(); it != this->GetPrim().GetChildren().end(); it++) {
    if (it->GetTypeName() == "DisplacedSolid") {
      update = update || G4DisplacedSolid(*it).IsOutputAffected(notice);
    }
  }

  return update;
}

bool pxr::G4MultiUnion::IsOutputAffected(const UsdNotice::ObjectsChanged& notice) {
  std::cout << "G4MultiUnion::IsOutputAffected> ";
  for(auto path : notice.GetChangedInfoOnlyPaths()) {
    std::cout << path << " ";
  }
  std::cout << std::endl;

  std::string solid3name;
  this->GetSolid3primAttr().Get(&solid3name);

  auto solid3prim = this->GetPrim().GetChild(pxr::TfToken(solid3name));

  return notice.AffectedObject(solid3prim.GetAttribute(pxr::TfToken("Points"))) ||
         notice.AffectedObject(solid3prim.GetAttribute(pxr::TfToken("FaceVertexCounts"))) ||
         notice.AffectedObject(solid3prim.GetAttribute(pxr::TfToken("FaceVertexIndices")));
}


