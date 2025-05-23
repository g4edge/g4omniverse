//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef G4_TOKENS_H
#define G4_TOKENS_H

/// \file G4/tokens.h

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// 
// This is an automatically generated file (by usdGenSchema.py).
// Do not hand-edit!
// 
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "pxr/pxr.h"
#include ".//api.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/token.h"
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE


/// \class G4TokensType
///
/// \link G4Tokens \endlink provides static, efficient
/// \link TfToken TfTokens\endlink for use in all public USD API.
///
/// These tokens are auto-generated from the module's schema, representing
/// property names, for when you need to fetch an attribute or relationship
/// directly by name, e.g. UsdPrim::GetAttribute(), in the most efficient
/// manner, and allow the compiler to verify that you spelled the name
/// correctly.
///
/// G4Tokens also contains all of the \em allowedTokens values
/// declared for schema builtin attributes of 'token' scene description type.
/// Use G4Tokens like so:
///
/// \code
///     gprim.GetMyTokenValuedAttr().Set(G4Tokens->angle_unit);
/// \endcode
struct G4TokensType {
    G4_API G4TokensType();
    /// \brief "angle_unit"
    /// 
    /// G4VSolid
    const TfToken angle_unit;
    /// \brief "daughters"
    /// 
    /// G4Logical, G4Assembly
    const TfToken daughters;
    /// \brief "dPhi"
    /// 
    /// G4Tubs, G4Cons
    const TfToken dPhi;
    /// \brief "fieldprim"
    /// 
    /// G4Logical
    const TfToken fieldprim;
    /// \brief "g4type"
    /// 
    /// G4VSolid, G4Box, G4Tubs, G4Cons, G4Orb, G4BooleanSolid, G4DisplacedSolid, G4Subtraction, G4Union, G4Intersection, G4MultiUnion, G4Logical, G4Assembly, G4Placement
    const TfToken g4type;
    /// \brief "length_unit"
    /// 
    /// G4VSolid
    const TfToken length_unit;
    /// \brief "limitsprim"
    /// 
    /// G4Logical
    const TfToken limitsprim;
    /// \brief "logicalprim"
    /// 
    /// G4Placement
    const TfToken logicalprim;
    /// \brief "materialprim"
    /// 
    /// G4Logical
    const TfToken materialprim;
    /// \brief "name"
    /// 
    /// G4VSolid
    const TfToken name;
    /// \brief "nslice"
    /// 
    /// G4Tubs, G4Cons
    const TfToken nslice;
    /// \brief "nslicePhi"
    /// 
    /// G4Orb
    const TfToken nslicePhi;
    /// \brief "nsliceTheta"
    /// 
    /// G4Orb
    const TfToken nsliceTheta;
    /// \brief "rMax"
    /// 
    /// G4Tubs, G4Orb
    const TfToken rMax;
    /// \brief "rMax1"
    /// 
    /// G4Cons
    const TfToken rMax1;
    /// \brief "rMax2"
    /// 
    /// G4Cons
    const TfToken rMax2;
    /// \brief "rMin"
    /// 
    /// G4Tubs
    const TfToken rMin;
    /// \brief "rMin1"
    /// 
    /// G4Cons
    const TfToken rMin1;
    /// \brief "rMin2"
    /// 
    /// G4Cons
    const TfToken rMin2;
    /// \brief "rotation"
    /// 
    /// G4DisplacedSolid, G4Placement
    const TfToken rotation;
    /// \brief "sensitiveprim"
    /// 
    /// G4Logical
    const TfToken sensitiveprim;
    /// \brief "solid1prim"
    /// 
    /// G4BooleanSolid
    const TfToken solid1prim;
    /// \brief "solid2prim"
    /// 
    /// G4BooleanSolid
    const TfToken solid2prim;
    /// \brief "solid3prim"
    /// 
    /// G4BooleanSolid, G4MultiUnion
    const TfToken solid3prim;
    /// \brief "solidprim"
    /// 
    /// G4Logical
    const TfToken solidprim;
    /// \brief "solidprims"
    /// 
    /// G4MultiUnion
    const TfToken solidprims;
    /// \brief "sPhi"
    /// 
    /// G4Tubs, G4Cons
    const TfToken sPhi;
    /// \brief "translation"
    /// 
    /// G4DisplacedSolid, G4Placement
    const TfToken translation;
    /// \brief "x"
    /// 
    /// G4Box
    const TfToken x;
    /// \brief "y"
    /// 
    /// G4Box
    const TfToken y;
    /// \brief "z"
    /// 
    /// G4Box, G4Tubs, G4Cons
    const TfToken z;
    /// \brief "Assembly"
    /// 
    /// Schema identifer and family for G4Assembly
    const TfToken Assembly;
    /// \brief "BooleanSolid"
    /// 
    /// Schema identifer and family for G4BooleanSolid
    const TfToken BooleanSolid;
    /// \brief "Box"
    /// 
    /// Schema identifer and family for G4Box
    const TfToken Box;
    /// \brief "Cons"
    /// 
    /// Schema identifer and family for G4Cons
    const TfToken Cons;
    /// \brief "DisplacedSolid"
    /// 
    /// Schema identifer and family for G4DisplacedSolid
    const TfToken DisplacedSolid;
    /// \brief "Intersection"
    /// 
    /// Schema identifer and family for G4Intersection
    const TfToken Intersection;
    /// \brief "Logical"
    /// 
    /// Schema identifer and family for G4Logical
    const TfToken Logical;
    /// \brief "MultiUnion"
    /// 
    /// Schema identifer and family for G4MultiUnion
    const TfToken MultiUnion;
    /// \brief "Orb"
    /// 
    /// Schema identifer and family for G4Orb
    const TfToken Orb;
    /// \brief "Placement"
    /// 
    /// Schema identifer and family for G4Placement
    const TfToken Placement;
    /// \brief "Subtraction"
    /// 
    /// Schema identifer and family for G4Subtraction
    const TfToken Subtraction;
    /// \brief "Tubs"
    /// 
    /// Schema identifer and family for G4Tubs
    const TfToken Tubs;
    /// \brief "Union"
    /// 
    /// Schema identifer and family for G4Union
    const TfToken Union;
    /// \brief "VSolid"
    /// 
    /// Schema identifer and family for G4VSolid
    const TfToken VSolid;
    /// A vector of all of the tokens listed above.
    const std::vector<TfToken> allTokens;
};

/// \var G4Tokens
///
/// A global variable with static, efficient \link TfToken TfTokens\endlink
/// for use in all public USD API.  \sa G4TokensType
extern G4_API TfStaticData<G4TokensType> G4Tokens;

PXR_NAMESPACE_CLOSE_SCOPE

#endif
