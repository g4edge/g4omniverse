//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

G4TokensType::G4TokensType() :
    g4type("g4type", TfToken::Immortal),
    name("name", TfToken::Immortal),
    r1("r1", TfToken::Immortal),
    r2("r2", TfToken::Immortal),
    solid1prim("solid1prim", TfToken::Immortal),
    solid2prim("solid2prim", TfToken::Immortal),
    x("x", TfToken::Immortal),
    y("y", TfToken::Immortal),
    z("z", TfToken::Immortal),
    BooleanSolid("BooleanSolid", TfToken::Immortal),
    Box("Box", TfToken::Immortal),
    Intersection("Intersection", TfToken::Immortal),
    Logical("Logical", TfToken::Immortal),
    Physical("Physical", TfToken::Immortal),
    Subtraction("Subtraction", TfToken::Immortal),
    Tubs("Tubs", TfToken::Immortal),
    Union("Union", TfToken::Immortal),
    VSolid("VSolid", TfToken::Immortal),
    allTokens({
        g4type,
        name,
        r1,
        r2,
        solid1prim,
        solid2prim,
        x,
        y,
        z,
        BooleanSolid,
        Box,
        Intersection,
        Logical,
        Physical,
        Subtraction,
        Tubs,
        Union,
        VSolid
    })
{
}

TfStaticData<G4TokensType> G4Tokens;

PXR_NAMESPACE_CLOSE_SCOPE
