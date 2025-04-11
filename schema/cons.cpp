//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//cons.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Cons,
        TfType::Bases< G4VSolid > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Cons")
    // to find TfType<G4Cons>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Cons>("Cons");
}

/* virtual */
G4Cons::~G4Cons()
{
}

/* static */
G4Cons
G4Cons::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Cons();
    }
    return G4Cons(stage->GetPrimAtPath(path));
}

/* static */
G4Cons
G4Cons::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Cons");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Cons();
    }
    return G4Cons(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Cons::_GetSchemaKind() const
{
    return G4Cons::schemaKind;
}

/* static */
const TfType &
G4Cons::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Cons>();
    return tfType;
}

/* static */
bool 
G4Cons::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Cons::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Cons::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Cons::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetRMin1Attr() const
{
    return GetPrim().GetAttribute(G4Tokens->rMin1);
}

UsdAttribute
G4Cons::CreateRMin1Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rMin1,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetRMax1Attr() const
{
    return GetPrim().GetAttribute(G4Tokens->rMax1);
}

UsdAttribute
G4Cons::CreateRMax1Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rMax1,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetRMin2Attr() const
{
    return GetPrim().GetAttribute(G4Tokens->rMin2);
}

UsdAttribute
G4Cons::CreateRMin2Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rMin2,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetRMax2Attr() const
{
    return GetPrim().GetAttribute(G4Tokens->rMax2);
}

UsdAttribute
G4Cons::CreateRMax2Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->rMax2,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetZAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->z);
}

UsdAttribute
G4Cons::CreateZAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->z,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetSPhiAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->sPhi);
}

UsdAttribute
G4Cons::CreateSPhiAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->sPhi,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetDPhiAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->dPhi);
}

UsdAttribute
G4Cons::CreateDPhiAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->dPhi,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
G4Cons::GetNsliceAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->nslice);
}

UsdAttribute
G4Cons::CreateNsliceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->nslice,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
G4Cons::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
        G4Tokens->rMin1,
        G4Tokens->rMax1,
        G4Tokens->rMin2,
        G4Tokens->rMax2,
        G4Tokens->z,
        G4Tokens->sPhi,
        G4Tokens->dPhi,
        G4Tokens->nslice,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            G4VSolid::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--
#include <iostream>
#include "pxr/usd/usd/notice.h"
#include "SurfaceMesh.h"

class ConsChangeListener : public pxr::TfWeakBase {
public:
    ConsChangeListener(pxr::G4Cons cons) : _cons(cons) {
        // Register the listener for object changes
        pxr::TfNotice::Register(pxr::TfCreateWeakPtr<ConsChangeListener>(this),
                                &ConsChangeListener::Update);
    }

    void Update(const pxr::UsdNotice::ObjectsChanged& notice) {
        if (_cons.IsInputAffected(notice)) {
            _cons.Update();
        }
    }

private:
    pxr::G4Cons _cons;
};

void pxr::G4Cons::InstallUpdateListener() {
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<ConsChangeListener>(new ConsChangeListener(*this)),
                            &ConsChangeListener::Update);
}

void pxr::G4Cons::Update() {
  double rMin1;
  double rMax1;
  double rMin2;
  double rMax2;
  double z;
  double sPhi;
  double dPhi;
  int nslice;
  GetRMin1Attr().Get(&rMin1);
  GetRMax1Attr().Get(&rMax1);
  GetRMin2Attr().Get(&rMin2);
  GetRMax2Attr().Get(&rMax2);
  GetZAttr().Get(&z);
  GetSPhiAttr().Get(&sPhi);
  GetDPhiAttr().Get(&dPhi);
  GetNsliceAttr().Get(&nslice);

  float rMin1f = float(rMin1);
  float rMax1f = float(rMax1);
  float rMin2f = float(rMin2);
  float rMax2f = float(rMax2);
  float zf = float(z);
  float sPhif = float(sPhi);
  float dPhif = float(dPhi);
  int nslicei = int(nslice);
  float tolerance = 1e4;
  float dPhifRounded = std::round(dPhif*tolerance);
  float twoPiRounded = std::round(2.0*M_PI*tolerance);
  auto p = GetPointsAttr();
  auto vc = GetFaceVertexCountsAttr();
  auto vi = GetFaceVertexIndicesAttr();

  bool b_r1min = rMin1f > 0;
  bool b_r1max = rMax1f > 0;
  bool b_r2min = rMin2f > 0;
  bool b_r2max = rMax2f > 0;
  VtArray<GfVec3f> pArray;

  VtIntArray vcArray;
  VtIntArray viArray;

  float pDPhi = dPhif / nslicei;

  for (int i = 0; i <= nslicei-1; ++i)
  {
    float phi1 = sPhif + i * pDPhi;
    float phi2 = sPhif + (i + 1) * pDPhi;
    //first radius
    float xR1Min1 = rMin1f*std::cos(phi1);
    float yR1Min1 = rMin1f*std::sin(phi1);

    float xR1Min2 = rMin1f*std::cos(phi2);
    float yR1Min2 = rMin1f*std::sin(phi2);

    float xR2Min1 = rMin2f*std::cos(phi1);
    float yR2Min1 = rMin2f*std::sin(phi1);

    float xR2Min2 = rMin2f*std::cos(phi2);
    float yR2Min2 = rMin2f*std::sin(phi2);

    float xR1Max1 = rMax1f*std::cos(phi1);
    float yR1Max1 = rMax1f*std::sin(phi1);

    float xR1Max2 = rMax1f*std::cos(phi2);
    float yR1Max2 = rMax1f*std::sin(phi2);

    float xR2Max1 = rMax2f*std::cos(phi1);
    float yR2Max1 = rMax2f*std::sin(phi1);

    float xR2Max2 = rMax2f*std::cos(phi2);
    float yR2Max2 = rMax2f*std::sin(phi2);



  	if (!b_r1min && !b_r1max && !b_r2min &&  b_r2max)
    {
  		// Case: [0,0,0,1]
  		// 0001
  		std::cout << "0001" << std::endl;
  		pArray.push_back(GfVec3f(0,0,-zf));//3
  		pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//2
  		pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//1

  		//cone side face
  		viArray.push_back(pArray.size()-3);
  		viArray.push_back(pArray.size()-1);
  		viArray.push_back(pArray.size()-2);
  		vcArray.push_back(3);

  		pArray.push_back(GfVec3f(0,0,zf));//3
  		//cone flat face
  		viArray.push_back(pArray.size()-3);
  		viArray.push_back(pArray.size()-2);
  		viArray.push_back(pArray.size()-1);
  		vcArray.push_back(3);

  		if (dPhifRounded != twoPiRounded)
  		{
  			if (i==0)
  			{
  				pArray.push_back(GfVec3f(0,0,-zf));//3
  				pArray.push_back(GfVec3f(0,0,zf));//2
  				pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//1

  				viArray.push_back(pArray.size()-1);
  				viArray.push_back(pArray.size()-2);
  				viArray.push_back(pArray.size()-3);
  				vcArray.push_back(3);

  			}
  		}

  		if (dPhifRounded != twoPiRounded)
  		{
  			if (i==nslicei-1)
  			{
  				pArray.push_back(GfVec3f(0,0,-zf));//3
  				pArray.push_back(GfVec3f(0,0,zf));//3
  				pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//1

  				viArray.push_back(pArray.size()-1);
  				viArray.push_back(pArray.size()-2);
  				viArray.push_back(pArray.size()-3);
  				vcArray.push_back(3);
  			}
  		}
  	}
  	else if (!b_r1min && !b_r1max &&  b_r2min &&  b_r2max)
    {
  		// Case: [0,0,1,1]
        // 0011
        	std::cout << "0011" << std::endl;
        	pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//-5
        	pArray.push_back(GfVec3f(xR2Min1, yR2Min1, zf));//-4
        	pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//-3
        	pArray.push_back(GfVec3f(xR2Min2, yR2Min2, zf));//-2
        	pArray.push_back(GfVec3f(0,0,-zf));//-1

            // flat cone at R2
        	viArray.push_back(pArray.size()-5);
        	viArray.push_back(pArray.size()-2);
        	viArray.push_back(pArray.size()-4);
        	vcArray.push_back(3);
        	viArray.push_back(pArray.size()-5);
        	viArray.push_back(pArray.size()-3);
        	viArray.push_back(pArray.size()-2);
        	vcArray.push_back(3);

             //outer edges
        	viArray.push_back(pArray.size()-3);
        	viArray.push_back(pArray.size()-5);
        	viArray.push_back(pArray.size()-1);
        	vcArray.push_back(3);

            //inner edges
        	viArray.push_back(pArray.size()-2);
        	viArray.push_back(pArray.size()-1);
        	viArray.push_back(pArray.size()-4);
        	vcArray.push_back(3);

            if (dPhifRounded != twoPiRounded)
            {
                if (i==0)
                {
                    pArray.push_back(GfVec3f(0,0,-zf));//3
                    pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//2
                    pArray.push_back(GfVec3f(xR2Min1, yR2Min1, zf));//1
                    viArray.push_back(pArray.size()-2);
                    viArray.push_back(pArray.size()-1);
                    viArray.push_back(pArray.size()-3);
                    vcArray.push_back(3);
                }
            }
            if (dPhifRounded != twoPiRounded)
            {
                if (i==nslicei-1)
                {
                    pArray.push_back(GfVec3f(0,0,-zf));//3
                    pArray.push_back(GfVec3f(xR2Min2, yR2Min2, zf));//2
                    pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//1
                    viArray.push_back(pArray.size()-2);
                    viArray.push_back(pArray.size()-1);
                    viArray.push_back(pArray.size()-3);
                    vcArray.push_back(3);
                }
            }

        }

  	else if (!b_r1min &&  b_r1max &&  b_r2min &&  b_r2max)
    {
  		// Case: [0,1,1,1]
        std::cout << "0111" << std::endl;

        // 0111
        pArray.push_back(GfVec3f(xR2Min1,yR2Min1,zf));//-7
        pArray.push_back(GfVec3f(xR2Max1,yR2Max1,zf));//-6
        pArray.push_back(GfVec3f(xR2Min2,yR2Min2,zf));//-5
        pArray.push_back(GfVec3f(xR2Max2,yR2Max2,zf));//-4
        pArray.push_back(GfVec3f(xR1Max1,yR1Max1,-zf));//-3
        pArray.push_back(GfVec3f(xR1Max2,yR1Max2,-zf));//-2
        pArray.push_back(GfVec3f(0,0,-zf));//-1
        //Flat side at R2
        viArray.push_back(pArray.size()-6);
        viArray.push_back(pArray.size()-4);
        viArray.push_back(pArray.size()-5);
        vcArray.push_back(3);

        viArray.push_back(pArray.size()-6);
        viArray.push_back(pArray.size()-5);
        viArray.push_back(pArray.size()-7);
        vcArray.push_back(3);

        //Flat side at R1
        viArray.push_back(pArray.size()-2);
        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-1);
        vcArray.push_back(3);

        //outer sides
        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-2);
        viArray.push_back(pArray.size()-4);
        vcArray.push_back(3);

        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-4);
        viArray.push_back(pArray.size()-6);
        vcArray.push_back(3);

        //inner face
        viArray.push_back(pArray.size()-1);
        viArray.push_back(pArray.size()-7);
        viArray.push_back(pArray.size()-5);
        vcArray.push_back(3);

        if (dPhifRounded != twoPiRounded)
        {
	        if (i==0)
	        {
    		  pArray.push_back(GfVec3f(0,0,-zf));//-4
    		  pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//-3
    		  pArray.push_back(GfVec3f(xR2Min1, yR2Min1, zf));//-2
    		  pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//-1
    		  viArray.push_back(pArray.size()-4);
    		  viArray.push_back(pArray.size()-3);
    		  viArray.push_back(pArray.size()-1);
    		  vcArray.push_back(3);
    		  viArray.push_back(pArray.size()-4);
    		  viArray.push_back(pArray.size()-1);
    		  viArray.push_back(pArray.size()-2);
    		  vcArray.push_back(3);
	    }
    	    }
        if (dPhifRounded != twoPiRounded)
        {
	        if (i==nslicei-1)
	        {
    		  pArray.push_back(GfVec3f(0,0,-zf));//-4
    		  pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//-3
    	  	  pArray.push_back(GfVec3f(xR2Min2, yR2Min2, zf));//-2
    		  pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//-1
    		  viArray.push_back(pArray.size()-1);
    		  viArray.push_back(pArray.size()-4);
    		  viArray.push_back(pArray.size()-2);
    		  vcArray.push_back(3);
    		  viArray.push_back(pArray.size()-1);
    		  viArray.push_back(pArray.size()-3);
    		  viArray.push_back(pArray.size()-4);
    		  vcArray.push_back(3);
            }
    	}
  	}
  	else if (!b_r1min &&  b_r1max && !b_r2min && !b_r2max)
    {
  		// Case: [0,1,0,0]
  		// 0100
  		std::cout << "0100" << std::endl;

  		pArray.push_back(GfVec3f(0,0,zf));//-3
  		pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//-2
  		pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//-1

  		viArray.push_back(pArray.size()-3);
  		viArray.push_back(pArray.size()-2);
  		viArray.push_back(pArray.size()-1);
  		vcArray.push_back(3);

  		pArray.push_back(GfVec3f(0,0, -zf));

  		//cone flat face
  		viArray.push_back(pArray.size()-3);
  		viArray.push_back(pArray.size()-1);
  		viArray.push_back(pArray.size()-2);
  		vcArray.push_back(3);

  		if (dPhifRounded != twoPiRounded)
  		{
  			if (i==0)
  			{
  				pArray.push_back(GfVec3f(0,0,-zf));//3
  				pArray.push_back(GfVec3f(0,0,zf));//2
  				pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//1

  				viArray.push_back(pArray.size()-2);
  				viArray.push_back(pArray.size()-3);
  				viArray.push_back(pArray.size()-1);
  				vcArray.push_back(3);
  			}
  		}
  		if (dPhifRounded != twoPiRounded)
  		{
  			if (i==nslicei-1)
  			{
  				pArray.push_back(GfVec3f(0,0,-zf));//3
  				pArray.push_back(GfVec3f(0,0,zf));//2
  				pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//1

  				viArray.push_back(pArray.size()-3);
  				viArray.push_back(pArray.size()-2);
  				viArray.push_back(pArray.size()-1);
  				vcArray.push_back(3);
  			}
  		}
  	}
  	else if ( b_r1min &&  b_r1max && !b_r2min && !b_r2max)
    {
  		// Case: [1,1,0,0]
        //1100
        std::cout << "1100" << std::endl;

        pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//5
        pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//4
        pArray.push_back(GfVec3f(xR1Min1, yR1Min1, -zf));//3
        pArray.push_back(GfVec3f(xR1Min2, yR1Min2, -zf));//2
        pArray.push_back(GfVec3f(0,0,zf));//1


        //cone side face
        viArray.push_back(pArray.size()-1);
        viArray.push_back(pArray.size()-5);
        viArray.push_back(pArray.size()-4);
        vcArray.push_back(3);


        //cone inside face
        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-1);
        viArray.push_back(pArray.size()-2);
        vcArray.push_back(3);

        //cone flat faces
        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-4);
        viArray.push_back(pArray.size()-5);
        vcArray.push_back(3);

        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-2);
        viArray.push_back(pArray.size()-4);
        vcArray.push_back(3);

        if (dPhifRounded != twoPiRounded)
        {
            if (i==0)
            {
                pArray.push_back(GfVec3f(0,0,zf));//3
                pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//2
                pArray.push_back(GfVec3f(xR1Min1, yR1Min1, -zf));//1

                viArray.push_back(pArray.size()-3);
                viArray.push_back(pArray.size()-1);
                viArray.push_back(pArray.size()-2);
                vcArray.push_back(3);
            }
        }
        if (dPhifRounded != twoPiRounded)
        {
            if (i==nslicei-1)
            {
                pArray.push_back(GfVec3f(0,0,zf));//4
                pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//2
                pArray.push_back(GfVec3f(xR1Min2, yR1Min2, -zf));//1

                viArray.push_back(pArray.size()-3);
                viArray.push_back(pArray.size()-2);
                viArray.push_back(pArray.size()-1);
                vcArray.push_back(3);
            }
        }

  	}
  	else if ( b_r1min &&  b_r1max && !b_r2min &&  b_r2max)
    {
  		// Case: [1,1,0,1]
        std::cout << "1101" << std::endl;
        // 1101
        pArray.push_back(GfVec3f(xR1Min1, yR1Min1, -zf));//-7
        pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//-6
        pArray.push_back(GfVec3f(xR1Min2, yR1Min2, -zf));//-5
        pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//-4
      	pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//-3
      	pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//-2
        pArray.push_back(GfVec3f(0,0,zf));//-1

        //r2 flat face
      	viArray.push_back(pArray.size()-1);
      	viArray.push_back(pArray.size()-3);
      	viArray.push_back(pArray.size()-2);
      	vcArray.push_back(3);

        //outer edge
      	viArray.push_back(pArray.size()-6);
      	viArray.push_back(pArray.size()-2);
      	viArray.push_back(pArray.size()-3);
      	vcArray.push_back(3);

      	viArray.push_back(pArray.size()-6);
      	viArray.push_back(pArray.size()-4);
      	viArray.push_back(pArray.size()-2);
      	vcArray.push_back(3);

        //R1 flat edge
      	viArray.push_back(pArray.size()-7);
      	viArray.push_back(pArray.size()-4);
      	viArray.push_back(pArray.size()-6);
      	vcArray.push_back(3);

      	viArray.push_back(pArray.size()-7);
      	viArray.push_back(pArray.size()-4);
      	viArray.push_back(pArray.size()-5);
      	vcArray.push_back(3);

		// inner face
      	viArray.push_back(pArray.size()-5);
      	viArray.push_back(pArray.size()-7);
      	viArray.push_back(pArray.size()-1);
      	vcArray.push_back(3);

		if (dPhifRounded != twoPiRounded)
		{
			if (i==0)
			{
      			pArray.push_back(GfVec3f(0,0,zf));//-4
      			pArray.push_back(GfVec3f(xR2Max1, yR2Max1, -zf));//-3
      			pArray.push_back(GfVec3f(xR1Min1, yR1Min1, -zf));//-2
      			pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//-1
      			viArray.push_back(pArray.size()-4);
      			viArray.push_back(pArray.size()-2);
      			viArray.push_back(pArray.size()-1);
      			vcArray.push_back(3);

      			viArray.push_back(pArray.size()-4);
      			viArray.push_back(pArray.size()-1);
      			viArray.push_back(pArray.size()-3);
      			vcArray.push_back(3);
			}

      	}
		if (dPhifRounded != twoPiRounded)
		{
			if (i==nslicei-1)
			{
      			pArray.push_back(GfVec3f(0,0,zf));//-4
      			pArray.push_back(GfVec3f(xR2Max2, yR2Max2, -zf));//-3
      			pArray.push_back(GfVec3f(xR1Min2, yR1Min2, -zf));//-2
      			pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//-1
      			viArray.push_back(pArray.size()-1);
      			viArray.push_back(pArray.size()-4);
      			viArray.push_back(pArray.size()-3);
      			vcArray.push_back(3);

      			viArray.push_back(pArray.size()-1);
      			viArray.push_back(pArray.size()-2);
      			viArray.push_back(pArray.size()-4);
      			vcArray.push_back(3);
      		}
      	}
  	}
  	else if ( b_r1min &&  b_r1max &&  b_r2min &&  b_r2max)
    {
  		// Case: [1,1,1,1]
		std::cout << "1111" << std::endl;
        //1111
        pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//8
      	pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//7
        pArray.push_back(GfVec3f(xR1Min1, yR1Min1, -zf));//6
        pArray.push_back(GfVec3f(xR1Min2, yR1Min2, -zf));//5
        pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//4
        pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//3
        pArray.push_back(GfVec3f(xR2Min1, yR2Min1, zf));//2
        pArray.push_back(GfVec3f(xR2Min2, yR2Min2, zf));//1

        //bottom faces
        viArray.push_back(pArray.size()-6);
        viArray.push_back(pArray.size()-5);
        viArray.push_back(pArray.size()-8);
 		vcArray.push_back(3);

        viArray.push_back(pArray.size()-5);
        viArray.push_back(pArray.size()-7);
        viArray.push_back(pArray.size()-8);
	    vcArray.push_back(3);

        //top faces
        viArray.push_back(pArray.size()-4);
        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-2);
		vcArray.push_back(3);

        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-1);
        viArray.push_back(pArray.size()-2);
	    vcArray.push_back(3);

        //outer edges
        viArray.push_back(pArray.size()-8);
        viArray.push_back(pArray.size()-7);
        viArray.push_back(pArray.size()-4);
	    vcArray.push_back(3);

        viArray.push_back(pArray.size()-7);
        viArray.push_back(pArray.size()-3);
        viArray.push_back(pArray.size()-4);
	    vcArray.push_back(3);

        //inner edges
        viArray.push_back(pArray.size()-2);
        viArray.push_back(pArray.size()-1);
        viArray.push_back(pArray.size()-6);
	    vcArray.push_back(3);

        viArray.push_back(pArray.size()-1);
        viArray.push_back(pArray.size()-5);
        viArray.push_back(pArray.size()-6);
	    vcArray.push_back(3);

		if (dPhifRounded != twoPiRounded)
		{
			if (i==0)
			{
				pArray.push_back(GfVec3f(xR1Min1, yR1Min1, -zf));//4
	            pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//3
				pArray.push_back(GfVec3f(xR2Min1, yR2Min1, zf));//2
	            pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//1
	            viArray.push_back(pArray.size()-4);
	            viArray.push_back(pArray.size()-1);
	            viArray.push_back(pArray.size()-2);
       			vcArray.push_back(3);
	            viArray.push_back(pArray.size()-4);
	            viArray.push_back(pArray.size()-3);
	            viArray.push_back(pArray.size()-1);
      			vcArray.push_back(3);
      		}
	    }
		if (dPhifRounded != twoPiRounded)
		{
			if (i==nslicei-1)
			{
				pArray.push_back(GfVec3f(xR1Min2, yR1Min2, -zf));//4
  				pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//3
				pArray.push_back(GfVec3f(xR2Min2, yR2Min2, zf));//2
        		pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//1
       			viArray.push_back(pArray.size()-4);
        		viArray.push_back(pArray.size()-2);
        		viArray.push_back(pArray.size()-1);
  				vcArray.push_back(3);
        		viArray.push_back(pArray.size()-4);
        		viArray.push_back(pArray.size()-1);
        		viArray.push_back(pArray.size()-3);
  				vcArray.push_back(3);
          	}
      	}
  	}
  	else if (!b_r1min &&  b_r1max && !b_r2min &&  b_r2max)
    {
  		// Case: [0,1,0,1]
        std::cout << "0101" << std::endl;
          //0101
  		pArray.push_back(GfVec3f(0, 0, -zf));//6
		pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//5
		pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//4
		pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//3
		pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//2
  		pArray.push_back(GfVec3f(0, 0, zf));//1

		// R1 flat
		viArray.push_back(pArray.size()-5);
		viArray.push_back(pArray.size()-6);
		viArray.push_back(pArray.size()-4);
		vcArray.push_back(3);

        //sides
		viArray.push_back(pArray.size()-5);
		viArray.push_back(pArray.size()-4);
		viArray.push_back(pArray.size()-3);
		vcArray.push_back(3);
		viArray.push_back(pArray.size()-4);
		viArray.push_back(pArray.size()-2);
		viArray.push_back(pArray.size()-3);
		vcArray.push_back(3);

        //R2 flat
		viArray.push_back(pArray.size()-1);
		viArray.push_back(pArray.size()-3);
		viArray.push_back(pArray.size()-2);
		vcArray.push_back(3);


		if (dPhifRounded != twoPiRounded)
		{
			if (i==0)
			{
				  pArray.push_back(GfVec3f(xR1Max1, yR1Max1, -zf));//3
				  pArray.push_back(GfVec3f(0, 0, zf));//2
				  pArray.push_back(GfVec3f(xR2Max1, yR2Max1, zf));//1
				  viArray.push_back(pArray.size()-4);
				  viArray.push_back(pArray.size()-2);
				  viArray.push_back(pArray.size()-1);
				  vcArray.push_back(3);
				  viArray.push_back(pArray.size()-4);
				  viArray.push_back(pArray.size()-3);
				  viArray.push_back(pArray.size()-1);
				  vcArray.push_back(3);
			    }
		    }
		if (dPhifRounded != twoPiRounded)
		{
			if (i==nslicei-1)
			{
				pArray.push_back(GfVec3f(0, 0, -zf));//4
				pArray.push_back(GfVec3f(xR1Max2, yR1Max2, -zf));//3
				pArray.push_back(GfVec3f(0, 0, zf));//2
				pArray.push_back(GfVec3f(xR2Max2, yR2Max2, zf));//1
				viArray.push_back(pArray.size()-4);
				viArray.push_back(pArray.size()-2);
				viArray.push_back(pArray.size()-1);
				vcArray.push_back(3);
				viArray.push_back(pArray.size()-4);
				viArray.push_back(pArray.size()-1);
				viArray.push_back(pArray.size()-3);
				vcArray.push_back(3);
		    }
		}
  	}
  }

  VtArray<GfVec3f> pArrayUpdate;
  VtIntArray viArrayUpdate;

  ReplaceDuplicateVertices(pArray,viArray,pArrayUpdate,viArrayUpdate);
  int edges = CountEdges(viArrayUpdate);
  std::cout <<"v = " << pArrayUpdate.size() << std::endl;
  std::cout <<"f = " << vcArray.size() << std::endl;
  std::cout <<"e = " << edges << std::endl;
  std::cout << "euler characteristic = " << pArrayUpdate.size()-edges+vcArray.size() << std::endl;
  Mesh cgalMesh;
  ConvertToCGALMesh(pArrayUpdate, vcArray, viArrayUpdate, cgalMesh);
  bool test =CGAL::is_closed(cgalMesh);
  if (test){std::cout << "true" << std::endl;}
  if (!test){std::cout << "false" << std::endl;}
  std::cout << "points " << pArrayUpdate << std::endl;
  std::cout << "vi " << viArrayUpdate << std::endl;
  p.Set(pArrayUpdate);
  vc.Set(vcArray);
  vi.Set(viArrayUpdate);
  // update parents
  auto parent = GetPrim().GetParent();
}

bool pxr::G4Cons::IsInputAffected(const pxr::UsdNotice::ObjectsChanged& notice) {
    return notice.AffectedObject(this->GetRMin1Attr()) ||
           notice.AffectedObject(this->GetRMax1Attr()) ||
           notice.AffectedObject(this->GetRMin2Attr()) ||
           notice.AffectedObject(this->GetRMax2Attr()) ||
           notice.AffectedObject(this->GetZAttr())    ||
           notice.AffectedObject(this->GetSPhiAttr()) ||
           notice.AffectedObject(this->GetDPhiAttr());
}

