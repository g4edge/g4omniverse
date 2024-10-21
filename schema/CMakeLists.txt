pxr_plugin(${PXR_PACKAGE}
    LIBRARIES
        tf
        sdf
        usd
        vt

    INCLUDE_DIRS
        ${Boost_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}

    PUBLIC_HEADERS
        api.h

    PUBLIC_CLASSES
	g4Vsolid
	g4Box
        tokens

    PYTHON_CPPFILES
        moduleDeps.cpp    

    PYMODULE_FILES
        __init__.py

    PYMODULE_CPPFILES
        module.cpp
        wrapg4VSolid.cpp	
        wrapg4Box.cpp
        wrapTokens.cpp        

    RESOURCE_FILES
        generatedSchema.usda
        plugInfo.json
        schema.usda:schema/g4schema.usda
)
