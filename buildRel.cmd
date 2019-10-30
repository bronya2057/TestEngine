rem call cleanBuild.cmd

rem @call "%VS140COMNTOOLS%VsDevCmd.bat"
cd build
mkdir cmakeBuildRel
cd cmakeBuildRel
cmake ../.. -G "Visual Studio 14 2015 Win64"

rem -DWARN_AS_ERROR=false
rem devenv TestEngine.sln /build "Release|x64"

cmake --build . --config Release


pause