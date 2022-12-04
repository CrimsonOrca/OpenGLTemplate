@echo off
mkdir Build
cd Build
cmake .. -G "MinGW Makefiles"
cmake --build .
cd ..
