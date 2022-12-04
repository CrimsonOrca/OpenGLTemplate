@echo off

cd Scripts
python Setup.py
cd ..

mkdir Build
cd Build
cmake .. -G "MinGW Makefiles"
cmake --build . 
cd ..

.\Build\Application\Application.exe