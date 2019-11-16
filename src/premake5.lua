workspace "TestEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
 
   startproject "Sandbox"

   flags{ "MultiProcessorCompile" }
   location "premake"
   outputdir="../premake/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
   
IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"

include "Engine/vendor/GLFW"

project "Engine"
   kind "SharedLib"
   language "C++"
   location "premake/Engine"
   
   targetdir ("../bin/premake/" .. outputdir .. "/%{prj.name}")
   objdir ("../build/premake/" .. outputdir .. "/%{prj.name}")

   files
   {
   "%{prj.name}/inc/**.hpp",
   "%{prj.name}/private/**.cpp"
   }
   
   includedirs
   {
    "%{prj.name}/vendor/spdlog/include",
    "%{prj.name}/inc",
    "%{IncludeDir.GLFW}"
   }
   
   links
   {
      "GLFW",
      "opengl32.lib"
   }
   
   filter "system:windows"
      cppdialect "C++11"
      systemversion "latest"
      
   defines
   {
     "ENGINE_WIN",
     "ENGINE_BUILD_DLL"
   }
   
   filter "configurations:Debug"
   defines "ENGINE_DEBUG"
   symbols "On"

   filter "configurations:Release"
   defines "ENGINE_RELEASE"
   optimize "On"

   filter "configurations:Dist"
   defines "ENGINE_DIST"
   optimize "On"
   
project "Sandbox"
   location "premake/Sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir ("../bin/premake/" .. outputdir .. "/%{prj.name}")
   objdir ("../build/premake/" .. outputdir .. "/%{prj.name}")

   files
   {
   "%{prj.name}/**.hpp",
   "%{prj.name}/**.cpp"
   }

   includedirs
   {
   "Engine/vendor/spdlog/include",
   "Engine/inc"
   }

   links
   {
   "Engine",
   }

   filter "system:windows"
   cppdialect "C++11"
   systemversion "latest"

   defines
   {
   "ENGINE_WIN"
   }

   filter "configurations:Debug"
   defines "ENGINE_DEBUG"
   symbols "On"

   filter "configurations:Release"
   defines "ENGINE_RELEASE"
   optimize "On"

   filter "configurations:Dist"
   defines "ENGINE_DIST"
   optimize "On"