//
// Created by Boogert Stewart on 13/11/2024.
//

#include "cgal_boolean.h"

void usdmesh_to_cgal(pxr::VtVec3fArray &points,
                     pxr::VtIntArray &faceVertexCounts,
                     pxr::VtIntArray &faceVertexIndices) {

  // create CGAL surface mesh

  // loop over points for transfer to SM


  // loop over faces
  int vtxCounter = 0;
  for (size_t i = 0; i < faceVertexCounts.size(); ++i) {
    std::cout << "Face " << i << " has " << faceVertexCounts[i] << " vertices." << std::endl;
    for(size_t j=vtxCounter; j < faceVertexCounts[i]; j++) {

    }
    vtxCounter += faceVertexCounts[i];
  }

  // return surface mesh
}

void cgal_to_usdmesh() {}
void cgal_subtraction() {}
void cgal_union() {}
void cgal_intersection() {}