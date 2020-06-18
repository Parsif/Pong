ifeq ($(OS), Windows_NT)
	LIBRARY_NAMES = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
else
	LIBRARY_NAMES = -lSDL2 -lSDL2_image
endif

OBJECTS = src/main.cpp src/Game.cpp src/utils/Logger.cpp src/Field.cpp
INCLUDE_PATHS = -IDependencies/SDL2/include
LIBRARY_PATHS = -LDependencies/SDL2/lib

COMPILER_FLAGS = -g -Wall
INCLUDE_PATHS = -Isrc/utils
OUTPUT = -o bin/Pong
CC = g++ 

MAIN_O = build/main.o
GAME_O = build/Game.o
LOGGER_O = build/Logger.o
FIELD_O = build/Field.o
PLAYER_O = build/Player.o

all: build run

build: $(MAIN_O) $(GAME_O) $(LOGGER_O) $(FIELD_O) $(PLAYER_O)
	$(CC) $(MAIN_O) $(GAME_O) $(LOGGER_O) $(FIELD_O) $(PLAYER_O) $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LIBRARY_NAMES) $(OUTPUT)

$(MAIN_O): src/main.cpp
	$(CC) $(INCLUDE_PATHS) -c src/main.cpp -o $(MAIN_O)

$(GAME_O): src/Game.cpp
	$(CC) $(INCLUDE_PATHS) -c src/Game.cpp -o $(GAME_O)

$(LOGGER_O): src/utils/Logger.cpp
	$(CC) -c src/utils/Logger.cpp -o $(LOGGER_O)

$(FIELD_O): src/Field.cpp
	$(CC) $(INCLUDE_PATHS) -c src/Field.cpp -o $(FIELD_O)

$(PLAYER_O): src/Player.cpp
	$(CC) $(INCLUDE_PATHS) -c src/Player.cpp -o $(PLAYER_O)



clean:
	del ".\build\*.o"

run:
	bin/Pong


