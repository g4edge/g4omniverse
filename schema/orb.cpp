//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//orb.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Orb,
        TfType::Bases< G4VSolid > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Orb")
    // to find TfType<G4Orb>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Orb>("Orb");
}

/* virtual */
G4Orb::~G4Orb()
{
}

/* static */
G4Orb
G4Orb::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Orb();
    }
    return G4Orb(stage->GetPrimAtPath(path));
}

/* static */
G4Orb
G4Orb::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Orb");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Orb();
    }
    return G4Orb(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Orb::_GetSchemaKind() const
{
    return G4Orb::schemaKind;
}

/* static */
const TfType &
G4Orb::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Orb>();
    return tfType;
}

/* static */
bool 
G4Orb::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Orb::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Orb::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Orb::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Orb::GetRMaxAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->rMax);
}

UsdAttribute
G4Orb::CreateRMaxAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rMax,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Orb::GetNslicePhiAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->nslicePhi);
}

UsdAttribute
G4Orb::CreateNslicePhiAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->nslicePhi,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Orb::GetNsliceThetaAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->nsliceTheta);
}

UsdAttribute
G4Orb::CreateNsliceThetaAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->nsliceTheta,
                       SdfValueTypeNames->Int,
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
G4Orb::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->rMax,
        G4Tokens->nslicePhi,
        G4Tokens->nsliceTheta,
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
#include "SurfaceMesh.h"

namespace PMP = CGAL::Polygon_mesh_processing;
class OrbChangeListener : public pxr::TfWeakBase {
public:
  OrbChangeListener(pxr::G4Orb orb) : _orb(orb) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<OrbChangeListener>(this),
                            &OrbChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
    if (_orb.IsInputAffected(notice)) {
      _orb.Update();
    }
  }

private:
  pxr::G4Orb _orb;
};


void pxr::G4Orb::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<OrbChangeListener>(new OrbChangeListener(*this)),
                          &OrbChangeListener::Update);
}

void pxr::G4Orb::Update() {
  double rMax;
  int nslicePhi;
  int nsliceTheta;
  GetRMaxAttr().Get(&rMax);
  GetNslicePhiAttr().Get(&nslicePhi);
  GetNsliceThetaAttr().Get(&nsliceTheta);
    float rMaxf = float(rMax);
  int nslicePhii = int(nslicePhi);
  int nsliceThetai = int(nsliceTheta);

  auto p = GetPointsAttr();
  auto vc = GetFaceVertexCountsAttr();
  auto vi = GetFaceVertexIndicesAttr();
  VtArray<GfVec3f> pArray;

  VtIntArray vcArray;
  VtIntArray viArray;
  float pDPhi = 2.0*M_PI / nslicePhii;
  float pDTheta = M_PI/nsliceThetai;
  for (int i = 0; i < nsliceThetai; ++i) {
    float theta1 = i * pDTheta;
    float theta2 = (i + 1) * pDTheta;

    float z1 = rMaxf * std::cos(theta1);
    float z2 = rMaxf * std::cos(theta2);

    for (int j = 0; j <= nslicePhii - 1; ++j) {
      float phi1 = j * pDPhi;
      float phi2 = (j + 1) * pDPhi;

      float x11 = rMaxf * std::sin(theta1) * std::cos(phi1);
      float y11 = rMaxf * std::sin(theta1) * std::sin(phi1);


      float x12 = rMaxf * std::sin(theta1) * std::cos(phi2);
      float y12 = rMaxf * std::sin(theta1) * std::sin(phi2);

      float x21 = rMaxf * std::sin(theta2) * std::cos(phi1);
      float y21 = rMaxf * std::sin(theta2) * std::sin(phi1);

      float x22 = rMaxf * std::sin(theta2) * std::cos(phi2);
      float y22 = rMaxf * std::sin(theta2) * std::sin(phi2);

      if (i == 0) {
        pArray.push_back(GfVec3f(0, 0, rMaxf));
        pArray.push_back(GfVec3f(x21, y21, z2));
        pArray.push_back(GfVec3f(x22, y22, z2));
        viArray.push_back(pArray.size() - 3);
        viArray.push_back(pArray.size() - 2);
        viArray.push_back(pArray.size() - 1);
        vcArray.push_back(3);
      } else if (i == (nsliceThetai - 1)) {
        pArray.push_back(GfVec3f(0, 0, -rMaxf));
        pArray.push_back(GfVec3f(x11, y11, z1));
        pArray.push_back(GfVec3f(x12, y12, z1));
        viArray.push_back(pArray.size() - 3);
        viArray.push_back(pArray.size() - 1);
        viArray.push_back(pArray.size() - 2);
        vcArray.push_back(3);
      } else {
        pArray.push_back(GfVec3f(x11, y11, z1));
        pArray.push_back(GfVec3f(x21, y21, z2));
        pArray.push_back(GfVec3f(x12, y12, z1));
        pArray.push_back(GfVec3f(x22, y22, z2));
        viArray.push_back(pArray.size() - 4);
        viArray.push_back(pArray.size() - 3);
        viArray.push_back(pArray.size() - 1);
        vcArray.push_back(3);
        viArray.push_back(pArray.size() - 4);
        viArray.push_back(pArray.size() - 1);
        viArray.push_back(pArray.size() - 2);
        vcArray.push_back(3);
      }
    }
  }
  VtArray<GfVec3f> pArrayUpdate;
  VtIntArray viArrayUpdate;
  ReplaceDuplicateVertices(pArray,viArray,pArrayUpdate,viArrayUpdate);
  p.Set(pArrayUpdate);
  vc.Set(vcArray);
  vi.Set(viArrayUpdate);
  // update parents
  auto parent = GetPrim().GetParent();
}


//// update these
bool pxr::G4Orb::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
    return notice.AffectedObject(this->GetRMaxAttr()) ||
           notice.AffectedObject(this->GetNslicePhiAttr()) ||
           notice.AffectedObject(this->GetNsliceThetaAttr());
}

