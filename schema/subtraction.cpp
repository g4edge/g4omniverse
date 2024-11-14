//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//subtraction.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Subtraction,
        TfType::Bases< G4BooleanSolid > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Subtraction")
    // to find TfType<G4Subtraction>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Subtraction>("Subtraction");
}

/* virtual */
G4Subtraction::~G4Subtraction()
{
}

/* static */
G4Subtraction
G4Subtraction::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Subtraction();
    }
    return G4Subtraction(stage->GetPrimAtPath(path));
}

/* static */
G4Subtraction
G4Subtraction::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Subtraction");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Subtraction();
    }
    return G4Subtraction(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Subtraction::_GetSchemaKind() const
{
    return G4Subtraction::schemaKind;
}

/* static */
const TfType &
G4Subtraction::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Subtraction>();
    return tfType;
}

/* static */
bool 
G4Subtraction::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Subtraction::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Subtraction::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Subtraction::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
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
G4Subtraction::GetSchemaAttributeNames(bool includeInherited)
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

#include "cgal_boolean.h"
#include "pxr/usd/usdGeom/xformable.h"
#include "pxr/base/gf/matrix4d.h"

void pxr::G4Subtraction::Update() {

  std::cout << "pxr::G4Subtraction::Update()" << std::endl;

  // get solid names
  std::string solid1Name;
  std::string solid2Name;
  std::string solid3Name;
  this->GetSolid1primAttr().Get(&solid1Name);
  this->GetSolid2primAttr().Get(&solid2Name);
  this->GetSolid3primAttr().Get(&solid3Name);

  // get solid prims
  auto solid1 = this->GetPrim().GetChild(pxr::TfToken(solid1Name));
  auto solid2 = this->GetPrim().GetChild(pxr::TfToken(solid2Name));
  auto solid3 = this->GetPrim().GetChild(pxr::TfToken(solid3Name));

  VtArray<GfVec3f> points;
  VtArray<int> vc;
  VtArray<int> vi;

  solid1.GetAttribute(pxr::TfToken("points")).Get(&points);
  solid1.GetAttribute(pxr::TfToken("faceVertexCounts")).Get(&vc);
  solid1.GetAttribute(pxr::TfToken("faceVertexIndices")).Get(&vi);
  auto sm1 = usdmesh_to_cgal(points,vc,vi);

  solid2.GetChildren().begin()->GetAttribute(pxr::TfToken("points")).Get(&points);
  solid2.GetChildren().begin()->GetAttribute(pxr::TfToken("faceVertexCounts")).Get(&vc);
  solid2.GetChildren().begin()->GetAttribute(pxr::TfToken("faceVertexIndices")).Get(&vi);
  auto sm2 = usdmesh_to_cgal(points,vc,vi);

  // Transform sm2
  pxr::UsdGeomXformable xformable(solid2);
  GfMatrix4d trans;
  bool resetsXformStack = false;
  xformable.GetLocalTransformation(&trans, &resetsXformStack);

  auto rotn = Aff_transformation_3(trans[0][0],trans[1][0],trans[2][0],
                                   trans[0][1],trans[1][1],trans[2][1],
                                   trans[0][2],trans[1][2],trans[2][2],1);
  CGAL::Polygon_mesh_processing::transform(rotn,*sm2);


  auto tr3 = Vector_3(trans[3][0],trans[3][1],trans[3][2]);
  auto at3 = Aff_transformation_3(CGAL::TRANSLATION, tr3);
  CGAL::Polygon_mesh_processing::transform(at3,*sm2);

  // Compute subtraction
  auto sm3 = cgal_subtraction(sm1,sm2);

  // Convert CGAL mesh back to pxr mesh
  points.clear();
  vc.clear();
  vi.clear();
  cgal_to_usdmesh(points,vc,vi,sm3);

  solid3.GetAttribute(pxr::TfToken("points")).Set(points);
  solid3.GetAttribute(pxr::TfToken("faceVertexCounts")).Set(vc);
  solid3.GetAttribute(pxr::TfToken("faceVertexIndices")).Set(vi);

  delete sm1;
  delete sm2;
  delete sm3;
}

#include "pxr/usd/usd/notice.h"

class SubtractionChangeListener : public pxr::TfWeakBase {
public:
  SubtractionChangeListener(pxr::G4Subtraction sub) : _sub(sub) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<SubtractionChangeListener>(this),
                            &SubtractionChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
    // std::cout << "updated" << " " << std::endl;
    _sub.Update();
  }

private:
  pxr::G4Subtraction _sub;
};

void pxr::G4Subtraction::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<SubtractionChangeListener>(new SubtractionChangeListener(*this)),
                          &SubtractionChangeListener::Update);
}
