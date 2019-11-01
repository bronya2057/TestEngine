#pragma once

#ifdef ENGINE_WIN
   #ifdef ENGINE_BUILD_DLL
      #define ENGINE_API __declspec(dllexport)
      #else
      #define ENGINE_API __declspec(dllimport)
   #endif
#else
   #error Engine for wind
#endif