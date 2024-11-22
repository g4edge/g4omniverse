//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//booleanSolid.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4BooleanSolid,
        TfType::Bases< UsdGeomScope > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("BooleanSolid")
    // to find TfType<G4BooleanSolid>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4BooleanSolid>("BooleanSolid");
}

/* virtual */
G4BooleanSolid::~G4BooleanSolid()
{
}

/* static */
G4BooleanSolid
G4BooleanSolid::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4BooleanSolid();
    }
    return G4BooleanSolid(stage->GetPrimAtPath(path));
}

/* static */
G4BooleanSolid
G4BooleanSolid::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("BooleanSolid");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4BooleanSolid();
    }
    return G4BooleanSolid(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4BooleanSolid::_GetSchemaKind() const
{
    return G4BooleanSolid::schemaKind;
}

/* static */
const TfType &
G4BooleanSolid::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4BooleanSolid>();
    return tfType;
}

/* static */
bool 
G4BooleanSolid::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4BooleanSolid::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4BooleanSolid::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4BooleanSolid::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4BooleanSolid::GetSolid1primAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solid1prim);
}

UsdAttribute
G4BooleanSolid::CreateSolid1primAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solid1prim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4BooleanSolid::GetSolid2primAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solid2prim);
}

UsdAttribute
G4BooleanSolid::CreateSolid2primAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->solid2prim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4BooleanSolid::GetSolid3primAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->solid3prim);
}

UsdAttribute
G4BooleanSolid::CreateSolid3primAttr(VtValue const &defaultValue, bool writeSparsely) const
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
G4BooleanSolid::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->solid1prim,
        G4Tokens->solid2prim,
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
#include "vSolid.h"
#include "displacedSolid.h"
#include "union.h"
#include "intersection.h"
#include "subtraction.h"

bool pxr::G4BooleanSolid::IsOutputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  std::cout << "G4BooleanSolid::IsOutputAffected> " << std::endl;
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

bool pxr::G4BooleanSolid::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  std::cout << "G4BooleanSolid::IsInputAffected> ";
  for(auto path : notice.GetChangedInfoOnlyPaths()) {
    std::cout << path << " " ;
  }
  std::cout << std::endl;

  std::string solid1name;
  std::string solid2name;

  this->GetSolid1primAttr().Get(&solid1name);
  this->GetSolid2primAttr().Get(&solid2name);

  auto solid1prim = this->GetPrim().GetChild(pxr::TfToken(solid1name));
  auto solid2prim = this->GetPrim().GetChild(pxr::TfToken(solid2name));

  bool solid1bool = false;

  std::cout << "G4BooleanSolid::IsInputAffected> objects " << solid1prim.GetTypeName() << " " << solid2prim.GetTypeName() << std::endl;

  if(solid1prim.GetTypeName() == "DisplacedSolid") solid1bool = G4DisplacedSolid(solid1prim).IsOutputAffected(notice);
  else if(solid1prim.GetTypeName() == "Subtraction") solid1bool = G4Subtraction(solid1prim).IsOutputAffected(notice);
  else if(solid1prim.GetTypeName() == "Union")  solid1bool = G4Union(solid1prim).IsOutputAffected(notice);
  else if(solid1prim.GetTypeName() == "Intersection") solid1bool = G4Subtraction(solid1prim).IsOutputAffected(notice);
  else solid1bool = G4VSolid(solid1prim).IsOutputAffected(notice);

  bool solid2bool = false;
  if(solid2prim.GetTypeName() == "DisplacedSolid") solid2bool = G4DisplacedSolid(solid2prim).IsOutputAffected(notice);
  else if(solid2prim.GetTypeName() == "Subtraction") solid2bool = G4Subtraction(solid2prim).IsOutputAffected(notice);
  else if(solid2prim.GetTypeName() == "Union")  solid2bool = G4Union(solid2prim).IsOutputAffected(notice);
  else if(solid2prim.GetTypeName() == "Intersection") solid2bool = G4Subtraction(solid2prim).IsOutputAffected(notice);
  else solid2bool = G4VSolid(solid2prim).IsOutputAffected(notice);

  return solid1bool || solid2bool;
}
