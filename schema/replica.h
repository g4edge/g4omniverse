//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef G4_GENERATED_REPLICA_H
#define G4_GENERATED_REPLICA_H

/// \file G4/replica.h

#include "pxr/pxr.h"
#include ".//api.h"
#include "pxr/usd/usdGeom/scope.h"
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/stage.h"
#include ".//tokens.h"

#include "pxr/base/vt/value.h"

#include "pxr/base/gf/vec3d.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/matrix4d.h"

#include "pxr/base/tf/token.h"
#include "pxr/base/tf/type.h"

PXR_NAMESPACE_OPEN_SCOPE

class SdfAssetPath;

// -------------------------------------------------------------------------- //
// REPLICA                                                                    //
// -------------------------------------------------------------------------- //

/// \class G4Replica
///
/// For any described attribute \em Fallback \em Value or \em Allowed \em Values below
/// that are text/tokens, the actual token is published and defined in \ref G4Tokens.
/// So to set an attribute to the value "rightHanded", use G4Tokens->rightHanded
/// as the value.
///
class G4Replica : public UsdGeomScope
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::ConcreteTyped;

    /// Construct a G4Replica on UsdPrim \p prim .
    /// Equivalent to G4Replica::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit G4Replica(const UsdPrim& prim=UsdPrim())
        : UsdGeomScope(prim)
    {
    }

    /// Construct a G4Replica on the prim held by \p schemaObj .
    /// Should be preferred over G4Replica(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit G4Replica(const UsdSchemaBase& schemaObj)
        : UsdGeomScope(schemaObj)
    {
    }

    /// Destructor.
    G4_API
    virtual ~G4Replica();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    G4_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a G4Replica holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// G4Replica(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    G4_API
    static G4Replica
    Get(const UsdStagePtr &stage, const SdfPath &path);

    /// Attempt to ensure a \a UsdPrim adhering to this schema at \p path
    /// is defined (according to UsdPrim::IsDefined()) on this stage.
    ///
    /// If a prim adhering to this schema at \p path is already defined on this
    /// stage, return that prim.  Otherwise author an \a SdfPrimSpec with
    /// \a specifier == \a SdfSpecifierDef and this schema's prim type name for
    /// the prim at \p path at the current EditTarget.  Author \a SdfPrimSpec s
    /// with \p specifier == \a SdfSpecifierDef and empty typeName at the
    /// current EditTarget for any nonexistent, or existing but not \a Defined
    /// ancestors.
    ///
    /// The given \a path must be an absolute prim path that does not contain
    /// any variant selections.
    ///
    /// If it is impossible to author any of the necessary PrimSpecs, (for
    /// example, in case \a path cannot map to the current UsdEditTarget's
    /// namespace) issue an error and return an invalid \a UsdPrim.
    ///
    /// Note that this method may return a defined prim whose typeName does not
    /// specify this schema class, in case a stronger typeName opinion overrides
    /// the opinion at the current EditTarget.
    ///
    G4_API
    static G4Replica
    Define(const UsdStagePtr &stage, const SdfPath &path);

protected:
    /// Returns the kind of schema this class belongs to.
    ///
    /// \sa UsdSchemaKind
    G4_API
    UsdSchemaKind _GetSchemaKind() const override;

private:
    // needs to invoke _GetStaticTfType.
    friend class UsdSchemaRegistry;
    G4_API
    static const TfType &_GetStaticTfType();

    static bool _IsTypedSchema();

    // override SchemaBase virtuals.
    G4_API
    const TfType &_GetTfType() const override;

public:
    // --------------------------------------------------------------------- //
    // G4TYPE 
    // --------------------------------------------------------------------- //
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `string g4type = "Replica"` |
    /// | C++ Type | std::string |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->String |
    G4_API
    UsdAttribute GetG4typeAttr() const;

    /// See GetG4typeAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    G4_API
    UsdAttribute CreateG4typeAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // LOGICALPRIM 
    // --------------------------------------------------------------------- //
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `string logicalprim = "none"` |
    /// | C++ Type | std::string |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->String |
    G4_API
    UsdAttribute GetLogicalprimAttr() const;

    /// See GetLogicalprimAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    G4_API
    UsdAttribute CreateLogicalprimAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // MOTHERPRIM 
    // --------------------------------------------------------------------- //
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `string motherprim = "none"` |
    /// | C++ Type | std::string |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->String |
    G4_API
    UsdAttribute GetMotherprimAttr() const;

    /// See GetMotherprimAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    G4_API
    UsdAttribute CreateMotherprimAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // AXIS 
    // --------------------------------------------------------------------- //
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `token axis = "kXAxis"` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    G4_API
    UsdAttribute GetAxisAttr() const;

    /// See GetAxisAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    G4_API
    UsdAttribute CreateAxisAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // NREPLICAS 
    // --------------------------------------------------------------------- //
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int nreplicas` |
    /// | C++ Type | int |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Int |
    G4_API
    UsdAttribute GetNreplicasAttr() const;

    /// See GetNreplicasAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    G4_API
    UsdAttribute CreateNreplicasAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // WIDTH 
    // --------------------------------------------------------------------- //
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double width` |
    /// | C++ Type | double |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double |
    G4_API
    UsdAttribute GetWidthAttr() const;

    /// See GetWidthAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    G4_API
    UsdAttribute CreateWidthAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // OFFSET 
    // --------------------------------------------------------------------- //
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double offset` |
    /// | C++ Type | double |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double |
    G4_API
    UsdAttribute GetOffsetAttr() const;

    /// See GetOffsetAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    G4_API
    UsdAttribute CreateOffsetAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // ===================================================================== //
    // Feel free to add custom code below this line, it will be preserved by 
    // the code generator. 
    //
    // Just remember to: 
    //  - Close the class declaration with }; 
    //  - Close the namespace with PXR_NAMESPACE_CLOSE_SCOPE
    //  - Close the include guard with #endif
    // ===================================================================== //
    // --(BEGIN CUSTOM CODE)--
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
