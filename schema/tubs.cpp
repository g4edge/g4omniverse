//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//tubs.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Tubs,
        TfType::Bases< G4VSolid > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Tubs")
    // to find TfType<G4Tubs>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Tubs>("Tubs");
}

/* virtual */
G4Tubs::~G4Tubs()
{
}

/* static */
G4Tubs
G4Tubs::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Tubs();
    }
    return G4Tubs(stage->GetPrimAtPath(path));
}

/* static */
G4Tubs
G4Tubs::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Tubs");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Tubs();
    }
    return G4Tubs(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Tubs::_GetSchemaKind() const
{
    return G4Tubs::schemaKind;
}

/* static */
const TfType &
G4Tubs::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Tubs>();
    return tfType;
}

/* static */
bool 
G4Tubs::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Tubs::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Tubs::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Tubs::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Tubs::GetRMinAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->rMin);
}

UsdAttribute
G4Tubs::CreateRMinAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rMin,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Tubs::GetRMaxAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->rMax);
}

UsdAttribute
G4Tubs::CreateRMaxAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rMax,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Tubs::GetZAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->z);
}

UsdAttribute
G4Tubs::CreateZAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->z,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Tubs::GetSPhiAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->sPhi);
}

UsdAttribute
G4Tubs::CreateSPhiAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->sPhi,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Tubs::GetDPhiAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->dPhi);
}

UsdAttribute
G4Tubs::CreateDPhiAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->dPhi,
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
G4Tubs::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->rMin,
        G4Tokens->rMax,
        G4Tokens->z,
        G4Tokens->sPhi,
        G4Tokens->dPhi,
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

class TubsChangeListener : public pxr::TfWeakBase {
public:
  TubsChangeListener(pxr::G4Tubs tubs) : _tubs(tubs) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<TubsChangeListener>(this),
                            &TubsChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
    if (_tubs.IsInputAffected(notice)) {
      _tubs.Update();
    }
  }

private:
  pxr::G4Tubs _tubs;
};


void pxr::G4Tubs::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<TubsChangeListener>(new TubsChangeListener(*this)),
                          &TubsChangeListener::Update);
}

void pxr::G4Tubs::Update() {
  double rMin;
  double rMax;
  double z;
  double sPhi;
  double dPhi;
  GetRMinAttr().Get(&rMin);
  GetRMaxAttr().Get(&rMax);
  GetZAttr().Get(&z);
  GetSPhiAttr().Get(&sPhi);
  GetDPhiAttr().Get(&dPhi);

  float rMinf = float(rMin);
  float rMaxf = float(rMax);
  float zf = float(z);
  float sPhif = float(sPhi);
  float dPhif = float(dPhi);

  auto p = GetPointsAttr();
  auto vc = GetFaceVertexCountsAttr();
  auto vi = GetFaceVertexIndicesAttr();

  VtArray<GfVec3f> pArray;
  VtIntArray vcArray;
  VtIntArray viArray;
  float nslice = 314;// this needs to be thought about more

  float pDPhi = dPhif / nslice;

  for (int i = 0; i < nslice; ++i)
  {
    float phi1 = sPhif + i * pDPhi;
    float phi2 = sPhif + (i + 1) * pDPhi;

    float xRMin1 = rMinf * std::cos(phi1);
    float yRMin1 = rMinf * std::sin(phi1);
    float xRMin2 = rMinf * std::cos(phi2);
    float yRMin2 = rMinf * std::sin(phi2);

    float xRMax1 = rMaxf * std::cos(phi1);
    float yRMax1 = rMaxf * std::sin(phi1);
    float xRMax2 = rMaxf * std::cos(phi2);
    float yRMax2 = rMaxf * std::sin(phi2);

    // wedge ends
    if (dPhif != 2.0*M_PI && i==0)
      {
      //polulate vertices for the 4 corners of the wedge end
      pArray.push_back(GfVec3f(xRMin1, yRMin1, -zf));
      pArray.push_back(GfVec3f(xRMin1, yRMin1, zf));
      pArray.push_back(GfVec3f(xRMax1, yRMax1, zf));
      pArray.push_back(GfVec3f(xRMax1, yRMax1, -zf));

      // push back the 3 vertices to describe first polygon on wedge end
      viArray.push_back(pArray.size() - 1);
      viArray.push_back(pArray.size() - 2);
      viArray.push_back(pArray.size() - 3);
      //add polygon number of vertices
      vcArray.push_back(3);

      // push back the 3 vertices to describe 2nd polygon on wedge end
      viArray.push_back(pArray.size() - 2);
      viArray.push_back(pArray.size() - 3);
      viArray.push_back(pArray.size() - 4);
      //add polygon number of vertices
      vcArray.push_back(3);

      }
    if (dPhif != 2.0*M_PI && i==nslice-1)
      {
       pArray.push_back(GfVec3f(xRMin2, yRMin2, -zf));
       pArray.push_back(GfVec3f(xRMax2, yRMax2, -zf));
       pArray.push_back(GfVec3f(xRMax2, yRMax2, zf));
       pArray.push_back(GfVec3f(xRMin2, yRMin2, zf));

        viArray.push_back(pArray.size() - 1);
        viArray.push_back(pArray.size() - 2);
        viArray.push_back(pArray.size() - 3);
        vcArray.push_back(3);

        viArray.push_back(pArray.size() - 2);
        viArray.push_back(pArray.size() - 3);
        viArray.push_back(pArray.size() - 4);
        vcArray.push_back(3);
      }

    //tube ends
    if (rMinf ==0)
      {
      //top and bottom without inner radius

       pArray.push_back(GfVec3f(0, 0, -zf));
       pArray.push_back(GfVec3f(xRMax2, yRMax2, -zf));
       pArray.push_back(GfVec3f(xRMax1, yRMax1, -zf));
       viArray.push_back(pArray.size() - 1);
       viArray.push_back(pArray.size() - 2);
       viArray.push_back(pArray.size() - 3);
       vcArray.push_back(3);

       pArray.push_back(GfVec3f(0, 0, zf));
       pArray.push_back(GfVec3f(xRMax1, yRMax1, zf));
       pArray.push_back(GfVec3f(xRMax2, yRMax2, zf));
       viArray.push_back(pArray.size() - 1);
       viArray.push_back(pArray.size() - 2);
       viArray.push_back(pArray.size() - 3);
       vcArray.push_back(3);

       }
      else
      {
       //top and bottom with inner radius

       pArray.push_back(GfVec3f(xRMin1, yRMin1, -zf));
       pArray.push_back(GfVec3f(xRMin2, yRMin2, -zf));
       pArray.push_back(GfVec3f(xRMax1, yRMax1, -zf));
       pArray.push_back(GfVec3f(xRMax2, yRMax2, -zf));
       viArray.push_back(pArray.size() - 1);
       viArray.push_back(pArray.size() - 2);
       viArray.push_back(pArray.size() - 3);
       vcArray.push_back(3);

       viArray.push_back(pArray.size() - 2);
       viArray.push_back(pArray.size() - 3);
       viArray.push_back(pArray.size() - 4);
       vcArray.push_back(3);

       pArray.push_back(GfVec3f(xRMin1, yRMin1, zf));
       pArray.push_back(GfVec3f(xRMin2, yRMin2, zf));
       pArray.push_back(GfVec3f(xRMax1, yRMax1, zf));
       pArray.push_back(GfVec3f(xRMax2, yRMax2, zf));
       viArray.push_back(pArray.size() - 1);
       viArray.push_back(pArray.size() - 2);
       viArray.push_back(pArray.size() - 3);
       vcArray.push_back(3);

       viArray.push_back(pArray.size() - 2);
       viArray.push_back(pArray.size() - 3);
       viArray.push_back(pArray.size() - 4);
       vcArray.push_back(3);
      }

      //curved faces
      //inner face
      pArray.push_back(GfVec3f(xRMin1, yRMin1, -zf));
      pArray.push_back(GfVec3f(xRMin1, yRMin1, zf));
      pArray.push_back(GfVec3f(xRMin2, yRMin2, -zf));
      pArray.push_back(GfVec3f(xRMin2, yRMin2, zf));
      viArray.push_back(pArray.size() - 1);
      viArray.push_back(pArray.size() - 2);
      viArray.push_back(pArray.size() - 3);
      vcArray.push_back(3);

      viArray.push_back(pArray.size() - 2);
      viArray.push_back(pArray.size() - 3);
      viArray.push_back(pArray.size() - 4);
      vcArray.push_back(3);

      //outer face

      pArray.push_back(GfVec3f(xRMax1, yRMax1, -zf));
      pArray.push_back(GfVec3f(xRMax1, yRMax1, zf));
      pArray.push_back(GfVec3f(xRMax2, yRMax2, -zf));
      pArray.push_back(GfVec3f(xRMax2, yRMax2, zf));
      viArray.push_back(pArray.size() - 1);
      viArray.push_back(pArray.size() - 2);
      viArray.push_back(pArray.size() - 3);
      vcArray.push_back(3);

      viArray.push_back(pArray.size() - 2);
      viArray.push_back(pArray.size() - 3);
      viArray.push_back(pArray.size() - 4);
      vcArray.push_back(3);
    }

  VtArray<GfVec3f> pArrayUpdate;
  ReplaceDuplicateVertices(pArray,viArray,pArrayUpdate);

  p.Set(pArrayUpdate);
  vc.Set(vcArray);
  vi.Set(viArray);
  // update parents
  auto parent = GetPrim().GetParent();
}
//// update these
bool pxr::G4Tubs::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
  return notice.AffectedObject(this->GetRMinAttr()) ||
         notice.AffectedObject(this->GetRMaxAttr()) ||
         notice.AffectedObject(this->GetZAttr())    ||
         notice.AffectedObject(this->GetSPhiAttr()) ||
         notice.AffectedObject(this->GetDPhiAttr());
}

void pxr::G4Tubs::ReplaceDuplicateVertices(VtArray<GfVec3f> &vertices, VtIntArray &indices, VtArray<GfVec3f> &newVertices)
{
  std::unordered_map<std::string, int> hashMap;
  for (auto it = vertices.begin(); it != vertices.end(); ++it)
    {
      int count = 0;
      std::string key1 = std::to_string(it[0][0]);
      std::string key2 = std::to_string(it[1][0]);
      std::string key3 = std::to_string(it[2][0]);

      std::string key = key1 + key2 + key3;
      if (hashMap.find(key) == hashMap.end())
      {
        hashMap[key] = count;
        newVertices.push_back(GfVec3f(it[0][0], it[0][1], it[0][2]));
      }
      else
      {
        std::replace(indices.begin(), indices.end(), count, hashMap[key]);
      }
      count++;


    }

}
