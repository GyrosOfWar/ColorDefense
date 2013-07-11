CC = clang++
CPPFLAGS = -Wall -std=c++11 -g

default: all

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Logger.o: Logger.cpp Logger.hpp
	$(CC) $(CPPFLAGS) -c Logger.cpp

stdafx.o: stdafx.cpp stdafx.h
	$(CC) $(CPPFLAGS) -c stdafx.cpp

enemy.o: enemy.cpp enemy.hpp
	$(CC) $(CPPFLAGS) -c enemy.cpp

wave.o: wave.cpp wave.hpp
	$(CC) $(CPPFLAGS) -c wave.cpp

level.o: level.cpp level.hpp
	$(CC) $(CPPFLAGS) -c level.cpp

tile.o: tile.cpp tile.hpp
	$(CC) $(CPPFLAGS) -c tile.cpp

passable_tile.o: passable_tile.cpp passable_tile.hpp
	$(CC) $(CPPFLAGS) -c passable_tile.cpp

buildable_tile.o: buildable_tile.cpp buildable_tile.hpp
	$(CC) $(CPPFLAGS) -c buildable_tile.cpp

blocked_tile.o: blocked_tile.cpp blocked_tile.hpp
	$(CC) $(CPPFLAGS) -c blocked_tile.cpp

all: main.o Logger.o stdafx.o enemy.o wave.o level.o tile.o passable_tile.o buildable_tile.o blocked_tile.o
	$(CC) main.o stdafx.o Logger.o level.o wave.o enemy.o tile.o passable_tile.o buildable_tile.o blocked_tile.o -o ColorDefense -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	rm -f *.o ColorDefense