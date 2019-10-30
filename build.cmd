cd build
mkdir cmakeBuild
cd cmakeBuild
cmake ../.. -G "Visual Studio 14 2015 Win64"
rem cmake ../..
cmake --build .

pause