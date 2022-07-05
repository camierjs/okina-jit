// Copyright (c) 2010-2022, Lawrence Livermore National Security, LLC. Produced
// at the Lawrence Livermore National Laboratory. All Rights reserved. See files
// LICENSE and NOTICE for details. LLNL-CODE-806117.
//
// This file is part of the MFEM library. For more information and source code
// availability visit https://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the BSD-3 license. We welcome feedback and contributions, see file
// CONTRIBUTING.md for details.

#include <string>
#include <cassert>
#include <iostream>

int main()
{
   const char *cxx = NULL;
#if defined(__ibmxl__)
   cxx = "XLC";
#elif defined(__NVCC__)
   cxx = "NVCC";
#elif defined(__clang_version__)
   const std::string ROC("RadeonOpenCompute");
   const std::string clang_version(__clang_version__);
   if (clang_version.find(ROC) != std::string::npos) { cxx = "ROCM"; }
   else { cxx = "CLANG"; }
#elif defined(__GNUC__)
   cxx = "GNU";
#else
   cxx = "UNKNOWN";
#endif
   assert(cxx && "Unknown compiler in config/get_jit_version.cpp");
   std::cout << cxx << std::endl;
   return 0;
}