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
    dPhi("dPhi", TfToken::Immortal),
    fieldprim("fieldprim", TfToken::Immortal),
    g4type("g4type", TfToken::Immortal),
    length_unit("length_unit", TfToken::Immortal),
    limitsprim("limitsprim", TfToken::Immortal),
    logicalprim("logicalprim", TfToken::Immortal),
    materialprim("materialprim", TfToken::Immortal),
    name("name", TfToken::Immortal),
    rMax("rMax", TfToken::Immortal),
    rMax1("rMax1", TfToken::Immortal),
    rMax2("rMax2", TfToken::Immortal),
    rMin("rMin", TfToken::Immortal),
    rMin1("rMin1", TfToken::Immortal),
    rMin2("rMin2", TfToken::Immortal),
    rotation("rotation", TfToken::Immortal),
    sensitiveprim("sensitiveprim", TfToken::Immortal),
    solid1prim("solid1prim", TfToken::Immortal),
    solid2prim("solid2prim", TfToken::Immortal),
    solid3prim("solid3prim", TfToken::Immortal),
    solidprim("solidprim", TfToken::Immortal),
    solidprims("solidprims", TfToken::Immortal),
    sPhi("sPhi", TfToken::Immortal),
    translation("translation", TfToken::Immortal),
    x("x", TfToken::Immortal),
    y("y", TfToken::Immortal),
    z("z", TfToken::Immortal),
    BooleanSolid("BooleanSolid", TfToken::Immortal),
    Box("Box", TfToken::Immortal),
    Cons("Cons", TfToken::Immortal),
    DisplacedSolid("DisplacedSolid", TfToken::Immortal),
    Intersection("Intersection", TfToken::Immortal),
    Logical("Logical", TfToken::Immortal),
    MultiUnion("MultiUnion", TfToken::Immortal),
    Orb("Orb", TfToken::Immortal),
    Placement("Placement", TfToken::Immortal),
    Subtraction("Subtraction", TfToken::Immortal),
    Tubs("Tubs", TfToken::Immortal),
    Union("Union", TfToken::Immortal),
    VSolid("VSolid", TfToken::Immortal),
    allTokens({
        angle_unit,
        daughters,
        dPhi,
        fieldprim,
        g4type,
        length_unit,
        limitsprim,
        logicalprim,
        materialprim,
        name,
        rMax,
        rMax1,
        rMax2,
        rMin,
        rMin1,
        rMin2,
        rotation,
        sensitiveprim,
        solid1prim,
        solid2prim,
        solid3prim,
        solidprim,
        solidprims,
        sPhi,
        translation,
        x,
        y,
        z,
        BooleanSolid,
        Box,
        Cons,
        DisplacedSolid,
        Intersection,
        Logical,
        MultiUnion,
        Orb,
        Placement,
        Subtraction,
        Tubs,
        Union,
        VSolid
    })
{
}

TfStaticData<G4TokensType> G4Tokens;

PXR_NAMESPACE_CLOSE_SCOPE
