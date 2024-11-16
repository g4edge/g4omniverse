//
// Created by Boogert Stewart on 13/11/2024.
//

#include "cgal_boolean.h"

#include "pxr/pxr.h"
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/stage.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/vec3d.h"
#include "pxr/usd/usdGeom/xformable.h"
#include "pxr/base/gf/matrix4d.h"

Surface_mesh_3* usdmesh_to_cgal(pxr::VtVec3fArray &points,
                                pxr::VtIntArray &faceVertexCounts,
                                pxr::VtIntArray &faceVertexIndices) {

  // create CGAL surface mesh
  Surface_mesh_3 *sm = new Surface_mesh_3();

  // loop over points for transfer to SM
  for(size_t i = 0; i < points.size(); ++i) {
    Point_3 p(CGAL::to_double(points[i][0]),
              CGAL::to_double(points[i][1]),
              CGAL::to_double(points[i][2]));
    sm->add_vertex(p);
  }

  // loop over faces
  int vtxCounter = 0;
  for (size_t i = 0; i < faceVertexCounts.size(); ++i) {
    sm->add_face(Surface_mesh_3::Vertex_index(faceVertexIndices[vtxCounter]),
                 Surface_mesh_3::Vertex_index(faceVertexIndices[vtxCounter+1]),
                 Surface_mesh_3::Vertex_index(faceVertexIndices[vtxCounter+2]));
    vtxCounter += faceVertexCounts[i];
  }

  // return surface mesh
  return sm;
}

void cgal_to_usdmesh(pxr::VtVec3fArray &points,
                     pxr::VtIntArray &faceVertexCounts,
                     pxr::VtIntArray &faceVertexIndices,
                     Surface_mesh_3 *sm) {
  // loop over points
  for(int i=0;i<sm->number_of_vertices();++i) {
    pxr::GfVec3f pxr_p;
    Surface_mesh_3::Vertex_index vi = Surface_mesh_3::Vertex_index(i);
    Surface_mesh_3::Point p = sm->point(vi);
    pxr_p[0] = CGAL::to_double(p.x());
    pxr_p[1] = CGAL::to_double(p.y());
    pxr_p[2] = CGAL::to_double(p.z());

    points.push_back(pxr_p);
  }

  // loop over faces
  for(int i=0;i<sm->number_of_faces();++i) {

    // assume triangular
    faceVertexCounts.push_back(3);

    // vertices for face
    Surface_mesh_3::Face_index fd = Surface_mesh_3::Face_index(i);
    for (Surface_mesh_3::Halfedge_index hd : CGAL::halfedges_around_face(sm->halfedge(fd), *sm)) {
      faceVertexIndices.push_back(sm->source(hd));
    }
  }
}

PXR_NAMESPACE_OPEN_SCOPE
void g4prim_to_meshdata(UsdPrim const& prim,
                        VtVec3fArray &points,
                        VtIntArray &faceVertexCounts,
                        VtIntArray &faceVertexIndices) {

  std::string g4type;
  prim.GetAttribute(TfToken("g4type")).Get(&g4type);

  if(g4type == "Subtraction" || g4type == "Union" || g4type == "Intersection") {
    std::string resultName;
    prim.GetAttribute(pxr::TfToken("solid3prim")).Get(&resultName);
    prim.GetChild(TfToken(resultName)).GetAttribute(TfToken("points")).Get(&points);
    prim.GetChild(TfToken(resultName)).GetAttribute(TfToken("faceVertexCounts")).Get(&faceVertexCounts);
    prim.GetChild(TfToken(resultName)).GetAttribute(TfToken("faceVertexIndices")).Get(&faceVertexIndices);
  }
  else if(g4type== "DisplacedSolid") {
    prim.GetChildren().begin()->GetAttribute(TfToken("points")).Get(&points);
    prim.GetChildren().begin()->GetAttribute(TfToken("faceVertexCounts")).Get(&faceVertexCounts);
    prim.GetChildren().begin()->GetAttribute(TfToken("faceVertexIndices")).Get(&faceVertexIndices);
  }
  else {
    prim.GetAttribute(TfToken("points")).Get(&points);
    prim.GetAttribute(TfToken("faceVertexCounts")).Get(&faceVertexCounts);
    prim.GetAttribute(TfToken("faceVertexIndices")).Get(&faceVertexIndices);
  }
}

void g4usdboolean(UsdPrim const& prim, g4usdbooleanOperation op) {

  std::cout << "g4usdboolean" << std::endl;

  // get solid names
  std::string solid1Name;
  std::string solid2Name;
  std::string solid3Name;
  std::cout << "getting solid names" << std::endl;
  prim.GetAttribute(pxr::TfToken("solid1prim")).Get(&solid1Name);
  prim.GetAttribute(pxr::TfToken("solid2prim")).Get(&solid2Name);
  prim.GetAttribute(pxr::TfToken("solid3prim")).Get(&solid3Name);
  std::cout << "got solid names" << " "
            << solid1Name << " "
            << solid2Name << " "
            << solid3Name << " " << std::endl;

  // get solid prims
  std::cout << "getting solid prims"  << std::endl;
  auto solid1 = prim.GetChild(pxr::TfToken(solid1Name));
  auto solid2 = prim.GetChild(pxr::TfToken(solid2Name));
  auto solid3 = prim.GetChild(pxr::TfToken(solid3Name));
  std::cout << "got solid prims"  << std::endl;

  VtArray<GfVec3f> points;
  VtArray<int> vc;
  VtArray<int> vi;

  std::cout << "getting solid1 data" << std::endl;
  solid1.GetAttribute(pxr::TfToken("points")).Get(&points);
  solid1.GetAttribute(pxr::TfToken("faceVertexCounts")).Get(&vc);
  solid1.GetAttribute(pxr::TfToken("faceVertexIndices")).Get(&vi);
  std::cout << "got solid1 data" << std::endl;
  auto sm1 = usdmesh_to_cgal(points,vc,vi);

  solid2.GetChildren().begin()->GetAttribute(pxr::TfToken("points")).Get(&points);
  solid2.GetChildren().begin()->GetAttribute(pxr::TfToken("faceVertexCounts")).Get(&vc);
  solid2.GetChildren().begin()->GetAttribute(pxr::TfToken("faceVertexIndices")).Get(&vi);
  std::cout << "got solid2 data" << std::endl;
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

  Surface_mesh_3 *sm3;
  if(op == SUBTRACTION) {
    sm3 = cgal_subtraction(sm1, sm2);
  }
  else if(op == UNION) {
    sm3 = cgal_union(sm1, sm2);
  }
  else if(op == INTERSECTION) {
    sm3 = cgal_intersection(sm1, sm2);
  }

  // Convert CGAL mesh back to pxr mesh
  points.clear();
  vc.clear();
  vi.clear();
  cgal_to_usdmesh(points,vc,vi,sm3);

  solid3.GetAttribute(pxr::TfToken("points")).Set(points);
  solid3.GetAttribute(pxr::TfToken("faceVertexCounts")).Set(vc);
  solid3.GetAttribute(pxr::TfToken("faceVertexIndices")).Set(vi);
  std::cout << "set solid3 data" << std::endl;

  delete sm1;
  delete sm2;
  delete sm3;
}
PXR_NAMESPACE_CLOSE_SCOPE

Surface_mesh_3* cgal_subtraction(Surface_mesh_3 *sm1, Surface_mesh_3 *sm2) {

  // create CGAL surface mesh
  Surface_mesh_3 *sm = new Surface_mesh_3();

  // union
  CGAL::Polygon_mesh_processing::corefine_and_compute_difference(*sm1, *sm2, *sm);

  return sm;
}

Surface_mesh_3* cgal_union(Surface_mesh_3 *sm1, Surface_mesh_3 *sm2) {
  // create CGAL surface mesh
  Surface_mesh_3 *sm = new Surface_mesh_3();

  // union
  CGAL::Polygon_mesh_processing::corefine_and_compute_union(*sm1, *sm2, *sm);

  return sm;
}

Surface_mesh_3* cgal_intersection(Surface_mesh_3 *sm1, Surface_mesh_3 *sm2) {
  // create CGAL surface mesh
  Surface_mesh_3 *sm = new Surface_mesh_3();

  // union
  CGAL::Polygon_mesh_processing::corefine_and_compute_intersection(*sm1, *sm2, *sm);

  return sm;
}