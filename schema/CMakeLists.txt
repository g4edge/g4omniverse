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
		orb
		booleanSolid
		subtraction
		displacedSolid
		union
		intersection
		subtraction
		multiUnion
		logical
		assembly
		placement
		replica
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
		wrapCons.cpp
		wrapOrb.cpp
		wrapBooleanSolid.cpp
		wrapDisplacedSolid.cpp
		wrapIntersection.cpp
		wrapUnion.cpp
		wrapSubtraction.cpp
		wrapMultiUnion.cpp
		wrapLogical.cpp
		wrapAssembly.cpp
		wrapPlacement.cpp
		wrapReplica.cpp
		wrapTokens.cpp

	CPPFILES
		surfaceMesh.cpp

		RESOURCE_FILES
		generatedSchema.usda
		plugInfo.json
		g4.usda:g4/schema.usda

)
