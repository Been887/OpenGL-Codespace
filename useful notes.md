using mingw_w, compile c++ program >
x86_64-w64-mingw32-g++ main.cpp -o main.exe

mingw_w compile command for this project >

x86_64-w64-mingw32-g++ main.cpp ~/winlibs/glad.c -o main.exe \
    -static-libgcc -static-libstdc++ -pthread \
    -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lcomdlg32 -lshell32 -lole32 -luuid -lwinmm


global settings.json for include headers in intellisense >
{
  "C_Cpp.default.includePath": [
    "${workspaceFolder}/include",
    "${env:HOME}/winlibs/include"
  ],
  "C_Cpp.default.compilerPath": "/usr/bin/x86_64-w64-mingw32-g++",
  "C_Cpp.default.intelliSenseMode": "linux-gcc-x64",
  "C_Cpp.default.cppStandard": "c++20",
  "C_Cpp.default.cStandard": "c17"
}