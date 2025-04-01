//
// Created by Siobhan Alden on 20/03/2025.
//

#ifndef SURFACEMESH_H
#define SURFACEMESH_H
#include <iostream>
#include "pxr/usd/usd/typed.h"
#include "pxr/usd/sdf/types.h"

struct Vec3Key {
    static constexpr float tolerance = 1e6f;  // Scaling factor for precision
    static constexpr float roundtoZeroThreshold = 1e-5f; // Threshold for rounding to zero
    int64_t x, y, z; // Integer representation of scaled coordinates

    // Constructor that converts GfVec3f to integer-scaled values
    // as the rounding function has been added don't need to do the compare for the round to zero
    Vec3Key(const pxr::GfVec3f& v) {
        x = static_cast<int64_t>(std::round((std::abs(v[0]) < roundtoZeroThreshold ? 0.0f : v[0]) * tolerance));
        y = static_cast<int64_t>(std::round((std::abs(v[1]) < roundtoZeroThreshold ? 0.0f : v[1]) * tolerance));
        z = static_cast<int64_t>(std::round((std::abs(v[2]) < roundtoZeroThreshold ? 0.0f : v[2]) * tolerance));
    }

    // Equality operator for unordered_map
    bool operator==(const Vec3Key& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

inline void HashCombine(std::size_t& seed, std::size_t value) {seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);}



// Custom hash function for Vec3Key
struct Vec3KeyHash {
    std::size_t operator()(const Vec3Key& v) const {
        std::size_t seed = 0;
        HashCombine(seed, std::hash<int64_t>{}(v.x));
        HashCombine(seed, std::hash<int64_t>{}(v.y));
        HashCombine(seed, std::hash<int64_t>{}(v.z));
        return seed;
    }
};

struct Edge {
    int v1, v2;

    // Ensure the smaller vertex comes first
    Edge(int a, int b) {
        v1 = std::min(a, b);
        v2 = std::max(a, b);
    }

    // Hash function for unordered_set
    bool operator==(const Edge& other) const {
        return v1 == other.v1 && v2 == other.v2;
    }
};

struct EdgeHash {
    std::size_t operator()(const Edge& e) const {
        return std::hash<int>()(e.v1) ^ std::hash<int>()(e.v2);
    }
};


void ReplaceDuplicateVertices(pxr::VtArray<pxr::GfVec3f> &vertices, pxr::VtIntArray &indices, pxr::VtArray<pxr::GfVec3f> &newVertices, pxr::VtIntArray &newIndices);

void RoundValues(pxr::GfVec3f& vertexIn, pxr::GfVec3f& vertexOut);

int CountEdges(pxr::VtIntArray &indices);

#endif //SURFACEMESH_H
