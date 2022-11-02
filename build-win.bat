cls
@echo off

if not exist build mkdir build

rem generate cmake files (symbol required to bulid libs as shared lib rather than static lib)
cmake -O . -B ./build -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON

rem copy assets & .dll files to output dir
robocopy "./resource"  "./build/bin/Debug/assets" /E
robocopy "./windows/bin/"  "./build/bin/Debug/" /E

rem compile project
cd build && cmake --build . 

echo compilation finished!

rem checking to see if a build folder exists in root, if not this script creates one
rem It then makes CMake produce all files required for building the projecct
rem Causes all resources etc to be copied to output folder and CMake to use compiler correct for the platform to build
rem CMake (with -B flag) is told where to store all generated files as well