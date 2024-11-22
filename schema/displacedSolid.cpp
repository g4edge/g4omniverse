//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//displacedSolid.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4DisplacedSolid,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("DisplacedSolid")
    // to find TfType<G4DisplacedSolid>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4DisplacedSolid>("DisplacedSolid");
}

/* virtual */
G4DisplacedSolid::~G4DisplacedSolid()
{
}

/* static */
G4DisplacedSolid
G4DisplacedSolid::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4DisplacedSolid();
    }
    return G4DisplacedSolid(stage->GetPrimAtPath(path));
}

/* static */
G4DisplacedSolid
G4DisplacedSolid::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("DisplacedSolid");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4DisplacedSolid();
    }
    return G4DisplacedSolid(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4DisplacedSolid::_GetSchemaKind() const
{
    return G4DisplacedSolid::schemaKind;
}

/* static */
const TfType &
G4DisplacedSolid::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4DisplacedSolid>();
    return tfType;
}

/* static */
bool 
G4DisplacedSolid::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4DisplacedSolid::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4DisplacedSolid::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4DisplacedSolid::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4DisplacedSolid::GetTranslationAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->translation);
}

UsdAttribute
G4DisplacedSolid::CreateTranslationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->translation,
                       SdfValueTypeNames->Double3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4DisplacedSolid::GetRotationAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->rotation);
}

UsdAttribute
G4DisplacedSolid::CreateRotationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rotation,
                       SdfValueTypeNames->Double3,
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
G4DisplacedSolid::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->translation,
        G4Tokens->rotation,
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
#include "vSolid.h"
#include "union.h"
#include "intersection.h"
#include "subtraction.h"

class DisplacedSolidChangeListener : public pxr::TfWeakBase {
public:
  DisplacedSolidChangeListener(pxr::G4DisplacedSolid displaced) : _displaced(displaced) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<DisplacedSolidChangeListener>(this),
                            &DisplacedSolidChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
    std::cout << "DisplacedSolidChangeListener::Update()" << std::endl;
    if (_displaced.IsInputAffected(notice)) {
      _displaced.Update();
    }
  }

private:
  pxr::G4DisplacedSolid _displaced;
};

void pxr::G4DisplacedSolid::Update() {
  std::cout << "G4DisplacedSolid::Update() " << this->GetPrim().GetPath() << std::endl;

  // Get DisplacedSolid position and rotation attributes
  pxr::GfVec3d translation;
  pxr::GfVec3d rotation;
  this->GetTranslationAttr().Get(&translation);
  this->GetRotationAttr().Get(&rotation);

  // Convert to float
  pxr::GfVec3f translation_float = GfVec3f(float(translation[0]), float(translation[1]), float(translation[2]));
  pxr::GfVec3f rotation_float = GfVec3f(float(rotation[0]), float(rotation[1]), float(rotation[2]));

  // Add or update xform operators
  pxr::UsdGeomXform xformable(*this);

  bool resetsXformStack = false;
  if (xformable.GetOrderedXformOps(&resetsXformStack).size() == 0) {
    xformable.AddTranslateOp().Set(translation);
    xformable.AddRotateZYXOp().Set(rotation_float);
  }
  else {
    this->GetPrim().GetAttribute(pxr::TfToken("xformOp:rotateZYX")).Set(rotation_float);
    this->GetPrim().GetAttribute(pxr::TfToken("xformOp:translate")).Set(translation);
  }
}

void pxr::G4DisplacedSolid::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<DisplacedSolidChangeListener>(new DisplacedSolidChangeListener(*this)),
                          &DisplacedSolidChangeListener::Update,
                          this->GetPrim().GetStage());
}

bool pxr::G4DisplacedSolid::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  std::cout << "G4DisplacedSolid::IsInputAffected> " ;
  for(auto path : notice.GetChangedInfoOnlyPaths()) {
    std::cout << path << " ";
  }
  std::cout << std::endl;

  auto solidprim = *this->GetPrim().GetChildren().begin();

  bool solidbool = false;
  if(solidprim.GetTypeName() == "Subtraction") solidbool = G4Subtraction(solidprim).IsOutputAffected(notice);
  else if(solidprim.GetTypeName() == "Union")  solidbool = G4Union(solidprim).IsOutputAffected(notice);
  else if(solidprim.GetTypeName() == "Intersection") solidbool = G4Subtraction(solidprim).IsOutputAffected(notice);
  else solidbool = G4VSolid(solidprim).IsOutputAffected(notice);

  return notice.AffectedObject(this->GetTranslationAttr()) ||
         notice.AffectedObject(this->GetRotationAttr()) ||
         solidbool;
}

bool pxr::G4DisplacedSolid::IsOutputAffected(const UsdNotice::ObjectsChanged& notice) {
  std::cout << "G4DisplacedSolid::IsOutputAffected> ";
  for(auto path : notice.GetChangedInfoOnlyPaths()) {
    std::cout << path << " " ;
  }
  std::cout << std::endl;

  return notice.AffectedObject(this->GetPrim().GetAttribute(pxr::TfToken("xformOp:rotateZYX"))) ||
         notice.AffectedObject(this->GetPrim().GetAttribute(pxr::TfToken("xformOp:translate"))) ||
         this->IsInputAffected(notice);
}