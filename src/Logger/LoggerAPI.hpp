#pragma once

#ifdef ENGINE_WIN
   #ifdef ENGINE_BUILD_DLL
      #define LOGGER_API __declspec(dllexport)
      #else
      #define LOGGER_API __declspec(dllimport)
   #endif
#else
   #error Engine for wind
#endif