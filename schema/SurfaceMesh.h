//
// Created by Siobhan Alden on 20/03/2025.
//

#ifndef SURFACEMESH_H
#define SURFACEMESH_H
#include <iostream>
#include "pxr/usd/usd/typed.h"
#include "pxr/usd/sdf/types.h"

struct Vec3Key {
    static constexpr float Tolerance = 1e6f;  // Scaling factor for precision
    static constexpr float RoundtoZeroThreshold = 1e-11f; // Threshold for rounding to zero
    int64_t x, y, z; // Integer representation of scaled coordinates

    // Constructor that converts GfVec3f to integer-scaled values
    Vec3Key(const pxr::GfVec3f& v) {
        x = static_cast<int64_t>(std::round((std::abs(v[0]) < RoundtoZeroThreshold ? 0.0f : v[0]) * Tolerance));
        y = static_cast<int64_t>(std::round((std::abs(v[1]) < RoundtoZeroThreshold ? 0.0f : v[1]) * Tolerance));
        z = static_cast<int64_t>(std::round((std::abs(v[2]) < RoundtoZeroThreshold ? 0.0f : v[2]) * Tolerance));
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

void ReplaceDuplicateVertices(pxr::VtArray<pxr::GfVec3f> &vertices, pxr::VtIntArray &indices, pxr::VtArray<pxr::GfVec3f> &newVertices, pxr::VtIntArray &newIndices);


#endif //SURFACEMESH_H
