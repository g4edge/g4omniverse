//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

G4TokensType::G4TokensType() :
    name("name", TfToken::Immortal),
    r1("r1", TfToken::Immortal),
    r2("r2", TfToken::Immortal),
    x("x", TfToken::Immortal),
    y("y", TfToken::Immortal),
    z("z", TfToken::Immortal),
    Box("Box", TfToken::Immortal),
    Intersection("Intersection", TfToken::Immortal),
    Logical("Logical", TfToken::Immortal),
    Subtraction("Subtraction", TfToken::Immortal),
    Tubs("Tubs", TfToken::Immortal),
    Union("Union", TfToken::Immortal),
    VSolid("VSolid", TfToken::Immortal),
    allTokens({
        name,
        r1,
        r2,
        x,
        y,
        z,
        Box,
        Intersection,
        Logical,
        Subtraction,
        Tubs,
        Union,
        VSolid
    })
{
}

TfStaticData<G4TokensType> G4Tokens;

PXR_NAMESPACE_CLOSE_SCOPE
