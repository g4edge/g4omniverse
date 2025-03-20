set(PXR_PACKAGE g4)

find_package(CGAL)

pxr_plugin(${PXR_PACKAGE}
    LIBRARIES
        tf
        sdf
        usd
	usdGeom
        vt
	usdImaging
		CGAL::CGAL

    INCLUDE_DIRS
        ${Boost_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}

    PUBLIC_HEADERS
        api.h

    PUBLIC_CLASSES
		vSolid
		box
		tubs
		cons
		booleanSolid
		subtraction
		displacedSolid
		union
		intersection
		subtraction
		multiUnion
		logical
		placement
		tokens
		VSolidAdapter
		cgal_boolean

    PYTHON_CPPFILES
		moduleDeps.cpp

    PYMODULE_FILES
		__init__.py
		utils.py

    PYMODULE_CPPFILES
		module.cpp
		wrapVSolid.cpp
		wrapBox.cpp
		wrapTubs.cpp
		wrapBooleanSolid.cpp
		wrapDisplacedSolid.cpp
		wrapIntersection.cpp
		wrapUnion.cpp
		wrapSubtraction.cpp
		wrapMultiUnion.cpp
		wrapLogical.cpp
		wrapPlacement.cpp
		wrapTokens.cpp

	CPPFILES
		surfaceMesh.cpp

		RESOURCE_FILES
		generatedSchema.usda
		plugInfo.json
		g4.usda:g4/schema.usda

)
