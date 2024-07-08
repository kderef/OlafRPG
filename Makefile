CC = gcc
CFLAGS = -Iext/raylib/src -Iext/raygui/src -Iext/raylib-cpp/include -Iext/incbin -Lext/raylib/src -lraylib
RELEASE_FLAGS = -O3 -s -DDEBUG=0
DEBUG_FLAGS = -O0 -DDEBUG=1 -g

MAIN = ./src/main.c
BIN = ./bin/OlafRPG

# --- Detect OS
ifeq ($(OS), Windows_NT)
	CFLAGS += -lwinmm -lgdi32 -lopengl32
	RELEASE_FLAGS += --static -mwindows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CFLAGS_RELEASE += --static
	endif
	ifeq ($(UNAME_S),Darwin)
		CFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
	endif
endif

debug: ext/raylib/src/libraylib.a
	$(CC) $(MAIN) -o $(BIN) $(CFLAGS) $(DEBUG_FLAGS)

release: ext/raylib/src/libraylib.a
	$(CC) $(MAIN) -o $(BIN) $(CFLAGS) $(RELEASE_FLAGS)