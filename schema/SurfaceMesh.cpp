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

    for (size_t i = 0; i < vertices.size(); ++i)
    {
        Vec3Key key(vertices[i]);
        // Check if key exists before inserting
        if (vertexMap.find(key) == vertexMap.end())
        {
            vertexMap[key] = static_cast<int>(count);
            newVertices.push_back(vertices[i]);
            ++count; // Only increment count for unique keys
        }
    }

    for (size_t i = 0; i < indices.size(); ++i)
    {
        int index=indices[i];
        Vec3Key point = vertices[index];
        int newIndex = vertexMap[point];
        newIndices.push_back(newIndex);
    }
}

