# Copyright (c) 2010-2021, Lawrence Livermore National Security, LLC. Produced
# at the Lawrence Livermore National Laboratory. All Rights reserved. See files
# LICENSE and NOTICE for details. LLNL-CODE-806117.
#
# This file is part of the MFEM library. For more information and source code
# availability visit https://mfem.org.
#
# MFEM is free software; you can redistribute it and/or modify it under the
# terms of the BSD-3 license. We welcome feedback and contributions, see file
# CONTRIBUTING.md for details.

# Save and restore the module path so we can use the CMake-provided FindHDF5.cmake
set(_module_path ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH)
enable_language(C) # FindHDF5.cmake uses the C compiler
find_package(HDF5 COMPONENTS HL C) # netcdf requires HL - this matches defaults.mk
# hdf5_hl depends on base hdf5 library
list(INSERT HDF5_LIBRARIES 0 ${HDF5_HL_LIBRARIES})
set(CMAKE_MODULE_PATH ${_module_path})
