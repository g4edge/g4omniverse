//
// Created by Siobhan Alden on 20/03/2025.
//

#include "SurfaceMesh.h"
#include "pxr/usd/usd/typed.h"
#include "pxr/usd/sdf/types.h"

void ReplaceDuplicateVertices(pxr::VtArray<pxr::GfVec3f> &vertices, pxr::VtIntArray &indices,
                                           pxr::VtArray<pxr::GfVec3f> &newVertices, pxr::VtIntArray &newIndices)
{
    std::unordered_map<Vec3Key, int, Vec3KeyHash> vertexMap;

    int count=0;
    pxr::VtArray<pxr::GfVec3f> roundVertices;
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        pxr::GfVec3f v;
        RoundValues(vertices[i], v);
        roundVertices.push_back(v);
        Vec3Key key(v);
        // Check if key exists before inserting
        if (vertexMap.find(key) == vertexMap.end())
        {
            vertexMap[key] = static_cast<int>(count);
            newVertices.push_back(v);
            ++count; // Only increment count for unique keys
        }
    }

    for (size_t i = 0; i < indices.size(); ++i)
    {
        int index=indices[i];
        Vec3Key point(roundVertices[index]);
        int newIndex = vertexMap[point];
        newIndices.push_back(newIndex);
    }
}

void RoundValues(pxr::GfVec3f& vertexIn, pxr::GfVec3f& vertexOut)
{
    static constexpr float Tolerance = 1e4f;  // Scaling factor for precision floating point errors
    static constexpr float RoundtoZeroThreshold = 1e-5f; // Threshold for rounding to zero

    float xOut, yOut, zOut;
    // First, round the values
    xOut = std::round(vertexIn[0] * Tolerance) / Tolerance;
    yOut = std::round(vertexIn[1] * Tolerance) / Tolerance;
    zOut = std::round(vertexIn[2] * Tolerance) / Tolerance;

    // Preserve sign: Only set to zero if the absolute value is below the threshold
    if (std::abs(xOut) < RoundtoZeroThreshold) xOut = 0.0f;
    if (std::abs(yOut) < RoundtoZeroThreshold) yOut = 0.0f;
    if (std::abs(zOut) < RoundtoZeroThreshold) zOut = 0.0f;

    vertexOut = pxr::GfVec3f(xOut, yOut, zOut);
}

std::unordered_set<Edge, EdgeHash> EdgesSet(pxr::VtIntArray &indices)
{
  std::unordered_set<Edge, EdgeHash> edgeSet;

  for (size_t i = 0; i < indices.size(); i += 3)
  {
    edgeSet.insert(Edge(indices[i], indices[i + 1]));
    edgeSet.insert(Edge(indices[i + 1], indices[i + 2]));
    edgeSet.insert(Edge(indices[i + 2], indices[i]));
  }

  return edgeSet;
}

int CountEdges(pxr::VtIntArray &indices)
{
  if (indices.size() % 3 != 0)
  {
    std::cerr << "Error: faces list is not a multiple of 3!" << std::endl;
    return -1;
  }
  std::unordered_set<Edge, EdgeHash> edgeSet;

  for (size_t i = 0; i < indices.size(); i += 3)
  {
    edgeSet.insert(Edge(indices[i], indices[i + 1]));
    edgeSet.insert(Edge(indices[i + 1], indices[i + 2]));
    edgeSet.insert(Edge(indices[i + 2], indices[i]));
  }

  return edgeSet.size();
}



void ConvertToCGALMesh(const pxr::VtArray<pxr::GfVec3f>& vertices, const pxr::VtIntArray& faceCounts, const pxr::VtIntArray& faceIndices, Mesh& mesh) {
    std::vector<Mesh::Vertex_index> vertexHandles;

    // Add vertices to CGAL Mesh
    for (const auto& v : vertices) {
        vertexHandles.push_back(mesh.add_vertex(Point(v[0], v[1], v[2])));
    }

    size_t index = 0;
    for (size_t f = 0; f < faceCounts.size(); ++f) {
        int faceSize = faceCounts[f];  // Number of vertices in this face
        std::vector<Mesh::Vertex_index> faceVertices;

        for (int i = 0; i < faceSize; ++i) {
            faceVertices.push_back(vertexHandles[faceIndices[index++]]);
        }

        if (faceSize == 3 || faceSize == 4) { // Ensure valid faces
            mesh.add_face(faceVertices);
        } else {
            std::cerr << "Warning: Skipping non-tri/quad face with " << faceSize << " vertices\n";
        }
    }
}

std::unordered_map<Edge, int, EdgeHash> CheckEdgesUsedTwice(pxr::VtIntArray &indices)
{
    std::unordered_map<Edge, int, EdgeHash> edgeMap;

    for (size_t i = 0; i < indices.size(); i += 3)
    {
        std::vector<Edge> faceEdges;
        faceEdges.push_back(Edge(indices[i], indices[i + 1]));
        faceEdges.push_back(Edge(indices[i + 1], indices[i + 2]));
        faceEdges.push_back(Edge(indices[i + 2], indices[i]));

        for (const Edge &edge : faceEdges)
        {
            if (edgeMap.find(edge) == edgeMap.end())
            {
                edgeMap[edge] = 1;
            }
            else
            {
                edgeMap[edge] += 1;
            }
        }
    }

    return edgeMap;
}
