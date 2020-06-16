OBJECTS = src/main.cpp src/Game.cpp src/utils/Logger.cpp
INCLUDE_PATHS = -IDependencies/SDL2/include
LIBRARY_PATHS = -LDependencies/SDL2/lib

COMPILER_FLAGS = -g
INCLUDE_PATHS = -Isrc/utils
LIBRARY_NAMES = -lmingw32 -lSDL2main -lSDL2
OUTPUT = -o bin/Pong

all: src/main.cpp
	g++ $(OBJECTS) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LIBRARY_NAMES) $(OUTPUT)
	

