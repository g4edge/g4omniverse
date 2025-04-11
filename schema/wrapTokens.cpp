//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// GENERATED FILE.  DO NOT EDIT.
#include <boost/python/class.hpp>
#include ".//tokens.h"

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

// Helper to return a static token as a string.  We wrap tokens as Python
// strings and for some reason simply wrapping the token using def_readonly
// bypasses to-Python conversion, leading to the error that there's no
// Python type for the C++ TfToken type.  So we wrap this functor instead.
class _WrapStaticToken {
public:
    _WrapStaticToken(const TfToken* token) : _token(token) { }

    std::string operator()() const
    {
        return _token->GetString();
    }

private:
    const TfToken* _token;
};

template <typename T>
void
_AddToken(T& cls, const char* name, const TfToken& token)
{
    cls.add_static_property(name,
                            boost::python::make_function(
                                _WrapStaticToken(&token),
                                boost::python::return_value_policy<
                                    boost::python::return_by_value>(),
                                boost::mpl::vector1<std::string>()));
}

} // anonymous

void wrapG4Tokens()
{
    boost::python::class_<G4TokensType, boost::noncopyable>
        cls("Tokens", boost::python::no_init);
    _AddToken(cls, "angle_unit", G4Tokens->angle_unit);
    _AddToken(cls, "daughters", G4Tokens->daughters);
    _AddToken(cls, "dPhi", G4Tokens->dPhi);
    _AddToken(cls, "fieldprim", G4Tokens->fieldprim);
    _AddToken(cls, "g4type", G4Tokens->g4type);
    _AddToken(cls, "length_unit", G4Tokens->length_unit);
    _AddToken(cls, "limitsprim", G4Tokens->limitsprim);
    _AddToken(cls, "logicalprim", G4Tokens->logicalprim);
    _AddToken(cls, "materialprim", G4Tokens->materialprim);
    _AddToken(cls, "name", G4Tokens->name);
    _AddToken(cls, "nslice", G4Tokens->nslice);
    _AddToken(cls, "nslicePhi", G4Tokens->nslicePhi);
    _AddToken(cls, "nsliceTheta", G4Tokens->nsliceTheta);
    _AddToken(cls, "rMax", G4Tokens->rMax);
    _AddToken(cls, "rMax1", G4Tokens->rMax1);
    _AddToken(cls, "rMax2", G4Tokens->rMax2);
    _AddToken(cls, "rMin", G4Tokens->rMin);
    _AddToken(cls, "rMin1", G4Tokens->rMin1);
    _AddToken(cls, "rMin2", G4Tokens->rMin2);
    _AddToken(cls, "rotation", G4Tokens->rotation);
    _AddToken(cls, "sensitiveprim", G4Tokens->sensitiveprim);
    _AddToken(cls, "solid1prim", G4Tokens->solid1prim);
    _AddToken(cls, "solid2prim", G4Tokens->solid2prim);
    _AddToken(cls, "solid3prim", G4Tokens->solid3prim);
    _AddToken(cls, "solidprim", G4Tokens->solidprim);
    _AddToken(cls, "solidprims", G4Tokens->solidprims);
    _AddToken(cls, "sPhi", G4Tokens->sPhi);
    _AddToken(cls, "translation", G4Tokens->translation);
    _AddToken(cls, "x", G4Tokens->x);
    _AddToken(cls, "y", G4Tokens->y);
    _AddToken(cls, "z", G4Tokens->z);
    _AddToken(cls, "BooleanSolid", G4Tokens->BooleanSolid);
    _AddToken(cls, "Box", G4Tokens->Box);
    _AddToken(cls, "Cons", G4Tokens->Cons);
    _AddToken(cls, "DisplacedSolid", G4Tokens->DisplacedSolid);
    _AddToken(cls, "Intersection", G4Tokens->Intersection);
    _AddToken(cls, "Logical", G4Tokens->Logical);
    _AddToken(cls, "MultiUnion", G4Tokens->MultiUnion);
    _AddToken(cls, "Orb", G4Tokens->Orb);
    _AddToken(cls, "Placement", G4Tokens->Placement);
    _AddToken(cls, "Subtraction", G4Tokens->Subtraction);
    _AddToken(cls, "Tubs", G4Tokens->Tubs);
    _AddToken(cls, "Union", G4Tokens->Union);
    _AddToken(cls, "VSolid", G4Tokens->VSolid);
}
