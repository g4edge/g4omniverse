//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//placement.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Placement,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Placement")
    // to find TfType<G4Placement>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Placement>("Placement");
}

/* virtual */
G4Placement::~G4Placement()
{
}

/* static */
G4Placement
G4Placement::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Placement();
    }
    return G4Placement(stage->GetPrimAtPath(path));
}

/* static */
G4Placement
G4Placement::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Placement");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Placement();
    }
    return G4Placement(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Placement::_GetSchemaKind() const
{
    return G4Placement::schemaKind;
}

/* static */
const TfType &
G4Placement::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Placement>();
    return tfType;
}

/* static */
bool 
G4Placement::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Placement::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Placement::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Placement::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Placement::GetLogicalprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->logicalprim);
}

UsdAttribute
G4Placement::CreateLogicalprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->logicalprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Placement::GetTranslationAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->translation);
}

UsdAttribute
G4Placement::CreateTranslationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->translation,
                       SdfValueTypeNames->Double3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Placement::GetRotationAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->rotation);
}

UsdAttribute
G4Placement::CreateRotationAttr(VtValue const &defaultValue, bool writeSparsely) const
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
G4Placement::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->logicalprim,
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

class PlacementChangeListener : public pxr::TfWeakBase {
public:
  PlacementChangeListener(pxr::G4Placement placement) : _placement(placement) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<PlacementChangeListener>(this),
                            &PlacementChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {

    if (notice.AffectedObject(_placement.GetTranslationAttr()) ||
        notice.AffectedObject(_placement.GetRotationAttr()) ) {
      _placement.Update();
    }
  }

private:
  pxr::G4Placement _placement;
};

void pxr::G4Placement::Update() {

  // Get Placement position and rotation attributes
  pxr::GfVec3d translation;
  pxr::GfVec3d rotation;
  this->GetTranslationAttr().Get(&translation);
  this->GetRotationAttr().Get(&rotation);

  // Convert to float
  pxr::GfVec3f translation_float = GfVec3f(float(translation[0]), float(translation[1]), float(translation[2]));
  pxr::GfVec3f rotation_float = GfVec3f(-float(rotation[0]),-float(rotation[1]), -float(rotation[2]));

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

void pxr::G4Placement::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<PlacementChangeListener>(new PlacementChangeListener(*this)),
                          &PlacementChangeListener::Update,
                          this->GetPrim().GetStage());
}

bool pxr::G4Placement::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  return notice.AffectedObject(this->GetTranslationAttr()) ||
         notice.AffectedObject(this->GetRotationAttr());
}
