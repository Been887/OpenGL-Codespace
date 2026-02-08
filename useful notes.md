using mingw_w, compile c++ program >
x86_64-w64-mingw32-g++ main.cpp -o main.exe

mingw_w compile command for this project >

x86_64-w64-mingw32-g++ main.cpp ~/winlibs/glad.c -o main.exe \
    -static-libgcc -static-libstdc++ -pthread \
    -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lcomdlg32 -lshell32 -lole32 -luuid -lwinmm
