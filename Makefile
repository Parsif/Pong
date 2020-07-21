ifeq ($(OS), Windows_NT)
	LIBRARY_NAMES = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	CLEAN_COMMAND = del ".\build\*.o"
else
	LIBRARY_NAMES = -lSDL2 -lSDL2_image
	CLEAN_COMMAND = rm build/*.o
endif

OBJECTS = src/main.cpp src/Game.cpp src/utils/Logger.cpp src/Field.cpp
LIBRARY_PATHS = 

COMPILER_FLAGS = -g -Wall -std=c++17
INCLUDE_PATHS = -Isrc/utils 
OUTPUT = -o bin/Pong
CC = g++ 

MAIN_O = build/main.o
GAME_O = build/Game.o
LOGGER_O = build/Logger.o
FIELD_O = build/Field.o
PLAYER_O = build/Player.o
HUMAN_PLAYER_O = build/HumanPlayer.o
AI_PLAYER_O = build/AIPlayer.o
BALL_O = build/Ball.o
COLLIDER_O = build/Collider.o


all: build run

build: $(MAIN_O) $(GAME_O) $(LOGGER_O) $(FIELD_O) $(PLAYER_O) $(HUMAN_PLAYER_O) $(AI_PLAYER_O) $(BALL_O) $(COLLIDER_O)
	$(CC) $(MAIN_O) $(GAME_O) $(LOGGER_O) $(FIELD_O) $(PLAYER_O) $(HUMAN_PLAYER_O) $(AI_PLAYER_O) $(BALL_O) $(COLLIDER_O) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LIBRARY_NAMES) $(OUTPUT)

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

$(HUMAN_PLAYER_O): src/HumanPlayer.cpp
	$(CC) $(INCLUDE_PATHS) -c src/HumanPlayer.cpp -o $(HUMAN_PLAYER_O)

$(AI_PLAYER_O): src/AIPlayer.cpp
	$(CC) $(INCLUDE_PATHS) -c src/AIPlayer.cpp -o $(AI_PLAYER_O)

$(BALL_O): src/Ball.cpp
	$(CC) $(INCLUDE_PATHS) -c src/Ball.cpp -o $(BALL_O)

$(COLLIDER_O): src/Collider.cpp
	$(CC) $(INCLUDE_PATHS) -c src/Collider.cpp -o $(COLLIDER_O)

clean:
	$(CLEAN_COMMAND)

run:
	bin/Pong


