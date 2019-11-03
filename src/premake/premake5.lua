workspace "TestEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   
outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "EventsDispatcher"
   kind "SharedLib"
   language "C++"
   location "EventsDispatcher"
   
   targetdir ("bin/premake/" .. outputdir .. "/%{prj.name}")
   objdir ("build/premake/" .. outputdir .. "/%{prj.name}")

   files
   {
   "%{prj.name}/**.h",
   "%{prj.name}/**.cpp"
   }
      
   defines
   {
     "ENGINE_WIN",
     "ENGINE_BUILD_DLL"
   }
   
   postbuildcommands
   {
   ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/EventDispatcher")
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
   
project "Logger"
   kind "SharedLib"
   language "C++"
   location "Logger"
   
   targetdir ("bin/premake/" .. outputdir .. "/%{prj.name}")
   objdir ("build/premake/" .. outputdir .. "/%{prj.name}")

   files
   {
   "%{prj.name}/**.h",
   "%{prj.name}/**.cpp"
   }
   
   includedirs
   {
    "vendor/spdlog/include"
   }
      
   defines
   {
     "ENGINE_WIN",
     "ENGINE_BUILD_DLL"
   }
   
   postbuildcommands
   {
   ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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
   
project "Engine"
   kind "SharedLib"
   language "C++"
   location "Engine"
   
   targetdir ("bin/premake/" .. outputdir .. "/%{prj.name}")
   objdir ("build/premake/" .. outputdir .. "/%{prj.name}")

   files
   {
   "%{prj.name}/**.h",
   "%{prj.name}/**.cpp"
   }
   
   includedirs
   {
    "%{prj.name}/../Logger/vendor/spdlog/include"
   }
   
   links
   {
      "Logger"
   }
   
   filter "system:windows"
      cppdialect "C++11"
      systemversion "latest"
      
   defines
   {
     "ENGINE_WIN",
     "ENGINE_BUILD_DLL"
   }
   
   postbuildcommands
   {
   ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/premake/" .. outputdir .. "/%{prj.name}")
   objdir ("build/premake/" .. outputdir .. "/%{prj.name}")

   files
   {
   "%{prj.name}/**.h",
   "%{prj.name}/**.cpp"
   }

   includedirs
   {
   "Logger/vendor/spdlog/include",
   "Engine/inc"
   }

   links
   {
   "Engine",
   "Logger"
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