//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//physical.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Physical,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Physical")
    // to find TfType<G4Physical>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Physical>("Physical");
}

/* virtual */
G4Physical::~G4Physical()
{
}

/* static */
G4Physical
G4Physical::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Physical();
    }
    return G4Physical(stage->GetPrimAtPath(path));
}

/* static */
G4Physical
G4Physical::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Physical");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Physical();
    }
    return G4Physical(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Physical::_GetSchemaKind() const
{
    return G4Physical::schemaKind;
}

/* static */
const TfType &
G4Physical::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Physical>();
    return tfType;
}

/* static */
bool 
G4Physical::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Physical::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Physical::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Physical::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Physical::GetLogicalprimAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->logicalprim);
}

UsdAttribute
G4Physical::CreateLogicalprimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->logicalprim,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Physical::GetTranslationAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->translation);
}

UsdAttribute
G4Physical::CreateTranslationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->translation,
                       SdfValueTypeNames->Double3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Physical::GetRotationAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->rotation);
}

UsdAttribute
G4Physical::CreateRotationAttr(VtValue const &defaultValue, bool writeSparsely) const
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
G4Physical::GetSchemaAttributeNames(bool includeInherited)
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

class PhysicalChangeListener : public pxr::TfWeakBase {
public:
  PhysicalChangeListener(pxr::G4Physical physical) : _physical(physical) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<PhysicalChangeListener>(this),
                            &PhysicalChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {

    if (notice.AffectedObject(_physical.GetTranslationAttr()) ||
        notice.AffectedObject(_physical.GetRotationAttr()) ) {
      _physical.Update();
    }
  }

private:
  pxr::G4Physical _physical;
};

void pxr::G4Physical::Update() {

  // Get physical position and rotation attributes
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

void pxr::G4Physical::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<PhysicalChangeListener>(new PhysicalChangeListener(*this)),
                          &PhysicalChangeListener::Update,
                          this->GetPrim().GetStage());
}

bool pxr::G4Physical::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  return notice.AffectedObject(this->GetTranslationAttr()) ||
         notice.AffectedObject(this->GetRotationAttr());
}
