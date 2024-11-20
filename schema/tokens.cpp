//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

G4TokensType::G4TokensType() :
    angle_unit("angle_unit", TfToken::Immortal),
    daughters("daughters", TfToken::Immortal),
    fieldprim("fieldprim", TfToken::Immortal),
    g4type("g4type", TfToken::Immortal),
    length_unit("length_unit", TfToken::Immortal),
    limitsprim("limitsprim", TfToken::Immortal),
    logicalprim("logicalprim", TfToken::Immortal),
    materialprim("materialprim", TfToken::Immortal),
    name("name", TfToken::Immortal),
    r1("r1", TfToken::Immortal),
    r2("r2", TfToken::Immortal),
    rotations("rotations", TfToken::Immortal),
    sensitiveprim("sensitiveprim", TfToken::Immortal),
    solid1prim("solid1prim", TfToken::Immortal),
    solid2prim("solid2prim", TfToken::Immortal),
    solid3prim("solid3prim", TfToken::Immortal),
    solidprim("solidprim", TfToken::Immortal),
    solidprims("solidprims", TfToken::Immortal),
    translations("translations", TfToken::Immortal),
    x("x", TfToken::Immortal),
    y("y", TfToken::Immortal),
    z("z", TfToken::Immortal),
    BooleanSolid("BooleanSolid", TfToken::Immortal),
    Box("Box", TfToken::Immortal),
    DisplacedSolid("DisplacedSolid", TfToken::Immortal),
    Intersection("Intersection", TfToken::Immortal),
    Logical("Logical", TfToken::Immortal),
    MultiUnion("MultiUnion", TfToken::Immortal),
    Physical("Physical", TfToken::Immortal),
    Subtraction("Subtraction", TfToken::Immortal),
    Tubs("Tubs", TfToken::Immortal),
    Union("Union", TfToken::Immortal),
    VSolid("VSolid", TfToken::Immortal),
    allTokens({
        angle_unit,
        daughters,
        fieldprim,
        g4type,
        length_unit,
        limitsprim,
        logicalprim,
        materialprim,
        name,
        r1,
        r2,
        rotations,
        sensitiveprim,
        solid1prim,
        solid2prim,
        solid3prim,
        solidprim,
        solidprims,
        translations,
        x,
        y,
        z,
        BooleanSolid,
        Box,
        DisplacedSolid,
        Intersection,
        Logical,
        MultiUnion,
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
