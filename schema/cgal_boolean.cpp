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

void cgal_to_usdmesh() {}
void cgal_subtraction() {}
void cgal_union() {}
void cgal_intersection() {}