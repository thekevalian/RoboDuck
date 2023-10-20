CC = g++
SFML_LIB_PATH = SFML/lib # change to your SFML lib path
SFML_INC_PATH = SFML/include -I imgui # change to your SFML include path
SFML_LINKS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopengl32
C_STATIC_LINKS = -static-libstdc++ -static-libgcc
SRC = $(wildcard src/*.cpp) $(wildcard imgui/*.cpp)
# version of Mingw for my SFML is WinLibs MSVCRT 13.1.0 (64-bit)
PROJECT = motorUI

ifeq ($(OS), Windows_NT)
    PROJECT := $(addsuffix .exe, $(PROJECT))
    OS_NAME := Windows
else ifeq ($(OS), Linux)
    OS_NAME := Linux
else 
    OS_NAME := Unknown
endif

$(PROJECT): $(SRC)
	$(CC) $^ -o $@ -DSFML_STATIC -I $(SFML_INC_PATH) -L $(SFML_LIB_PATH) $(SFML_LINKS) $(C_STATIC_LINKS)

clean-windows:
	del /F /Q $(PROJECT)