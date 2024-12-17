@echo off
setlocal enabledelayedexpansion

REM Create executables directory if it doesn't exist
if not exist executables (
    mkdir executables
)

REM Remove all executables before compilation
del /q executables\*.exe

REM Compile each .cpp file in the src directory
for %%f in (src\*.cpp) do (
    set filename=%%~nf
    g++ -std=c++17 %%f -I"C:\Program Files\SDL\MinGW\sdl2_x86_64-w64-mingw32\include" -L"C:\Program Files\SDL\MinGW\sdl2_x86_64-w64-mingw32\lib" -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o executables\!filename!.exe
)

endlocal
