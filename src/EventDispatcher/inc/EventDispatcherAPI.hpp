#pragma once

#ifdef ENGINE_WIN
   #ifdef ENGINE_BUILD_DLL
      #define EVENT_DISPATCHER_API __declspec(dllexport)
      #else
      #define EVENT_DISPATCHER_API __declspec(dllimport)
   #endif
#else
   #error Engine for wind
#endif

#define BIT(x) (1 << x)