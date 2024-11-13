set(PXR_PACKAGE g4)

pxr_plugin(${PXR_PACKAGE}
    LIBRARIES
        tf
        sdf
        usd
	usdGeom
        vt
	usdImaging

    INCLUDE_DIRS
        ${Boost_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}

    PUBLIC_HEADERS
        api.h

    PUBLIC_CLASSES
	vSolid
	box
	tubs
	booleanSolid
	subtraction
	union
	intersection
	subtraction
	logical
	physical
    tokens
	VSolidAdapter

    PYTHON_CPPFILES
        moduleDeps.cpp    

    PYMODULE_FILES
        __init__.py

    PYMODULE_CPPFILES
        module.cpp
        wrapVSolid.cpp	
        wrapBox.cpp
	wrapTubs.cpp
		wrapBooleanSolid.cpp
	wrapIntersection.cpp
	wrapUnion.cpp
	wrapSubtraction.cpp
	wrapLogical.cpp
	wrapPhysical.cpp
        wrapTokens.cpp        

    RESOURCE_FILES
        generatedSchema.usda
        plugInfo.json
        g4.usda:g4/schema.usda
)
