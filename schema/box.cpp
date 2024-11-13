//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//box.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Box,
        TfType::Bases< G4VSolid > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Box")
    // to find TfType<G4Box>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Box>("Box");
}

/* virtual */
G4Box::~G4Box()
{
}

/* static */
G4Box
G4Box::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Box();
    }
    return G4Box(stage->GetPrimAtPath(path));
}

/* static */
G4Box
G4Box::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Box");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Box();
    }
    return G4Box(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Box::_GetSchemaKind() const
{
    return G4Box::schemaKind;
}

/* static */
const TfType &
G4Box::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Box>();
    return tfType;
}

/* static */
bool 
G4Box::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Box::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Box::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Box::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Box::GetXAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->x);
}

UsdAttribute
G4Box::CreateXAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->x,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Box::GetYAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->y);
}

UsdAttribute
G4Box::CreateYAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->y,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Box::GetZAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->z);
}

UsdAttribute
G4Box::CreateZAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->z,
                       SdfValueTypeNames->Double,
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
G4Box::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->x,
        G4Tokens->y,
        G4Tokens->z,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            G4VSolid::GetSchemaAttributeNames(true),
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

class BoxChangeListener : public pxr::TfWeakBase {
public:
  BoxChangeListener(pxr::G4Box box) : _box(box) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<BoxChangeListener>(this),
                            &BoxChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
    // std::cout << "updated" << " " << std::endl;
    _box.Update();
  }

private:
  pxr::G4Box _box;
};

void pxr::G4Box::Update() {
  // std::cout << "pxr::G4Box::Update()" << std::endl;

  double x;
  double y;
  double z;
  GetXAttr().Get(&x);
  GetYAttr().Get(&y);
  GetZAttr().Get(&z);

  float xf = (float)x;
  float yf = (float)y;
  float zf = (float)z;

  auto p = GetPrim().GetAttribute(TfToken("points"));
  auto vc = GetPrim().GetAttribute(TfToken("faceVertexCounts"));
  auto vi = GetPrim().GetAttribute(TfToken("faceVertexIndices"));

  VtArray<GfVec3f> pArray = {GfVec3f(-xf, -yf, -zf),
                             GfVec3f(-xf,  yf, -zf),
                             GfVec3f( xf,  yf, -zf)};

  //VtIntArray vcArray = {3,3,3,3,3,3,3,3,3,3,3,3};
  VtIntArray vcArray = {3};
  VtIntArray viArray = {0,1,2};

  p.Set(pArray);
  vc.Set(vcArray);
  vi.Set(viArray);

  // update parents
  auto parent = GetPrim().GetParent();
  // std::cout << "parent path=" << " " << parent.GetPath() << " type='" << parent.GetTypeName() << "'" << std::endl;


}

void pxr::G4Box::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<BoxChangeListener>(new BoxChangeListener(*this)),
                          &BoxChangeListener::Update);
}
