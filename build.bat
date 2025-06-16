@ECHO OFF
SET SDL_CFLAGS=-IC:/msys64/ucrt64/include/SDL2 -Dmain=SDL_main
SET SDL_LIBS=-LC:/msys64/ucrt64/lib -lmingw32 -mwindows -lSDL2main -lSDL2 -llib\funcs.o
SET CFLAGS=-Wall -Wextra
@ECHO ON

gcc -c .\lib\funcs.c -o .\lib\funcs.o
gcc .\src\main.c -o .\out\snake.exe %SDL_CFLAGS% %SDL_LIBS%