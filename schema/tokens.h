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
///     gprim.GetMyTokenValuedAttr().Set(G4Tokens->name);
/// \endcode
struct G4TokensType {
    G4_API G4TokensType();
    /// \brief "name"
    /// 
    /// G4Named, G4VSolid
    const TfToken name;
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
    /// G4Box
    const TfToken z;
    /// \brief "Box"
    /// 
    /// Schema identifer and family for G4Box
    const TfToken Box;
    /// \brief "Intersection"
    /// 
    /// Schema identifer and family for G4Intersection
    const TfToken Intersection;
    /// \brief "Logical"
    /// 
    /// Schema identifer and family for G4Logical
    const TfToken Logical;
    /// \brief "Named"
    /// 
    /// Schema identifer and family for G4Named
    const TfToken Named;
    /// \brief "Subtraction"
    /// 
    /// Schema identifer and family for G4Subtraction
    const TfToken Subtraction;
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
