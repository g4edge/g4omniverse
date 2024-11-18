cmake_minimum_required(VERSION 3.12)
project(G4USD)

# Set paths to your USD installation
set(PXR_ROOT "Physics/coderepos/openusd/openusd-build/")
list(APPEND CMAKE_PREFIX_PATH "${PXR_ROOT}")

find_package(PXR REQUIRED
        COMPONENTS
        usd
        usdGeom  # Include other necessary USD components here
)

set(PXR_PACKAGE g4)

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
        booleanSolid
        subtraction
        displacedSolid
        union
        intersection
        subtraction
        logical
        physical
        tokens
        VSolidAdapter
        cgal_boolean

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
        wrapDisplacedSolid.cpp
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