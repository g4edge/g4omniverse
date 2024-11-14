//
// Created by Boogert Stewart on 13/11/2024.
//

#include "cgal_boolean.h"

#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/vec3d.h"

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

Surface_mesh_3* cgal_subtraction(Surface_mesh_3 *sm1, Surface_mesh_3 *sm2) {

  // create CGAL surface mesh
  Surface_mesh_3 *sm = new Surface_mesh_3();
  CGAL::Polygon_mesh_processing::corefine_and_compute_difference(*sm1, *sm2, *sm);

  return sm;
}

void cgal_union() {}
void cgal_intersection() {}