//
// Copyright 2017 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef G4_API_H
#define G4_API_H

#include "pxr/base/arch/export.h"

#if defined(PXR_STATIC)
#   define G4_API
#   define G4_API_TEMPLATE_CLASS(...)
#   define G4_API_TEMPLATE_STRUCT(...)
#   define G4_LOCAL
#else
#   if defined(G4_EXPORTS)
#       define G4_API ARCH_EXPORT
#       define G4_API_TEMPLATE_CLASS(...) ARCH_EXPORT_TEMPLATE(class, __VA_ARGS__)
#       define G4_API_TEMPLATE_STRUCT(...) ARCH_EXPORT_TEMPLATE(struct, __VA_ARGS__)
#   else
#       define G4_API ARCH_IMPORT
#       define G4_API_TEMPLATE_CLASS(...) ARCH_IMPORT_TEMPLATE(class, __VA_ARGS__)
#       define G4_API_TEMPLATE_STRUCT(...) ARCH_IMPORT_TEMPLATE(struct, __VA_ARGS__)
#   endif
#   define G4_LOCAL ARCH_HIDDEN
#endif

#endif
