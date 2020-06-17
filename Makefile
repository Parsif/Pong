OBJECTS = src/main.cpp src/Game.cpp src/utils/Logger.cpp src/Field.cpp
INCLUDE_PATHS = -IDependencies/SDL2/include
LIBRARY_PATHS = -LDependencies/SDL2/lib

COMPILER_FLAGS = -g -Wall
INCLUDE_PATHS = -Isrc/utils
OUTPUT = -o bin/Pong 


ifeq ($(OS), Windows_NT)
	LIBRARY_NAMES = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
else
	LIBRARY_NAMES = -lSDL2 -lSDL2_image
endif

build: $(OBJECTS)
	g++ $(OBJECTS) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LIBRARY_NAMES) $(OUTPUT)

run:
	bin/Pong


