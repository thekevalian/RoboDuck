CC = g++
SFML_LIB_PATH = SFML/lib # change to your SFML lib path
SFML_INC_PATH = SFML/include # change to your SFML include path
SFML_LINKS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
C_STATIC_LINKS = -static-libstdc++ -static-libgcc
SRC = $(wildcard src/*.cpp)
# version of Mingw for my SFML is WinLibs MSVCRT 13.1.0 (64-bit)
PROJECT = TEMPLATE


ifeq ($(OS), Windows_NT)
    PROJECT := $(addsuffix .exe, $(PROJECT))
    OS_NAME := Windows
    BUILD_CMD := build_windows
    CLEAN_CMD := clean_windows
else ifeq ($(OS), Linux)
    OS_NAME := Linux
    BUILD_CMD := build_linux
    CLEAN_CMD := clean_linux
else
    OS_NAME := Unknown
    BUILD_CMD := unsupported
    CLEAN_CMD := unsupported
endif

.PHONY: build clean

build:
    @echo "Building for $(OS_NAME)"
    $(MAKE) $(BUILD_CMD)

clean:
    @echo "Cleaning for $(OS_NAME)"
    $(MAKE) $(CLEAN_CMD)

build_windows:
    @echo "Build for Windows here"

build_linux:
    @echo "Build for Linux here"

clean_windows:
    @echo "Clean for Windows here"

clean_linux:
    @echo "Clean for Linux here"

unsupported:
    @echo "Unsupported OS: $(OS_NAME)"


test: 
    @echo "Project: $(PROJECT)"
    @echo "OS: $(OS_NAME)"



$(PROJECT): $(SRC)
	$(CC) $^ -o $@ -DSFML_STATIC -I $(SFML_INC_PATH) -L $(SFML_LIB_PATH) $(SFML_LINKS) $(C_STATIC_LINKS)

clean:
	rm -rf $(PROJECT).exe

