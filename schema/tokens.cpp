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
    x("x", TfToken::Immortal),
    y("y", TfToken::Immortal),
    z("z", TfToken::Immortal),
    Box("Box", TfToken::Immortal),
    Intersection("Intersection", TfToken::Immortal),
    Logical("Logical", TfToken::Immortal),
    Named("Named", TfToken::Immortal),
    Subtraction("Subtraction", TfToken::Immortal),
    Union("Union", TfToken::Immortal),
    VSolid("VSolid", TfToken::Immortal),
    allTokens({
        name,
        x,
        y,
        z,
        Box,
        Intersection,
        Logical,
        Named,
        Subtraction,
        Union,
        VSolid
    })
{
}

TfStaticData<G4TokensType> G4Tokens;

PXR_NAMESPACE_CLOSE_SCOPE
