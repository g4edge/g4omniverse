//
// Created by Boogert Stewart on 13/11/2024.
//

#ifndef GEANT4OMNIVERSE_CGAL_BOOLEAN_H
#define GEANT4OMNIVERSE_CGAL_BOOLEAN_H

#include <CGAL/Exact_rational.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Extended_cartesian.h>

#include <CGAL/Polyhedron_3.h>
#include <CGAL/Polyhedron_incremental_builder_3.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Nef_polyhedron_3.h>
#include <CGAL/IO/Nef_polyhedron_iostream_3.h>

#include "CGAL/Aff_transformation_3.h"

#include "CGAL/Polygon_mesh_processing/corefinement.h"
#include "CGAL/Polygon_mesh_processing/orientation.h"
#include "CGAL/Polygon_mesh_processing/repair.h"
#include "CGAL/Polygon_mesh_processing/transform.h"
#include "CGAL/Polygon_mesh_processing/triangulate_faces.h"

typedef CGAL::Exact_predicates_exact_constructions_kernel EPECK;
typedef EPECK::Point_3 Point_3_EPECK;
typedef EPECK::Vector_3 Vector_3_EPECK;
typedef CGAL::Surface_mesh<EPECK::Point_3> Surface_mesh_3_EPECK;
typedef CGAL::Aff_transformation_3<EPECK> Aff_transformation_3_EPECK;

typedef Surface_mesh_3_EPECK Surface_mesh_3;
typedef Vector_3_EPECK Vector_3;
typedef Aff_transformation_3_EPECK Aff_transformation_3;
typedef Point_3_EPECK Point_3;
typedef boost::graph_traits<Surface_mesh_3>::vertex_descriptor vertex_descriptor;

#include "pxr/usd/usd/prim.h"

#include "pxr/base/vt/array.h"

enum g4usdbooleanOperation {SUBTRACTION, UNION, INTERSECTION};

Surface_mesh_3* usdmesh_to_cgal(pxr::VtVec3fArray &points,
                                pxr::VtIntArray &faceVertexCounts,
                                pxr::VtIntArray &faceVertexIndices);
void cgal_to_usdmesh(pxr::VtVec3fArray &points,
                     pxr::VtIntArray &faceVertexCounts,
                     pxr::VtIntArray &faceVertexIndices,
                     Surface_mesh_3 *sm);
PXR_NAMESPACE_OPEN_SCOPE
void g4prim_to_meshdata(UsdPrim const& prim,
                        VtVec3fArray &points,
                        VtIntArray &faceVertexCounts,
                        VtIntArray &faceVertexIndices);
void g4usdboolean(UsdPrim const &p, g4usdbooleanOperation op);
void g4usdboolean_multiunion(UsdPrim const& prim);
PXR_NAMESPACE_CLOSE_SCOPE

Surface_mesh_3* cgal_subtraction(Surface_mesh_3 *sm1, Surface_mesh_3 *sm2);
Surface_mesh_3* cgal_union(Surface_mesh_3 *sm1, Surface_mesh_3 *sm2 );
Surface_mesh_3* cgal_intersection(Surface_mesh_3 *sm1, Surface_mesh_3 *sm2 );


#endif //GEANT4OMNIVERSE_CGAL_BOOLEAN_H
