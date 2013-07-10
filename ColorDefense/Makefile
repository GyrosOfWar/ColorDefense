CC = g++
CPPFLAGS = -Wall -std=c++11 -g

default: all

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Logger.o: Logger.cpp Logger.hpp
	$(CC) $(CPPFLAGS) -c Logger.cpp

stdafx.o: stdafx.cpp stdafx.h
	$(CC) $(CPPFLAGS) -c stdafx.cpp

all: main.o Logger.o stdafx.o
	$(CC) main.o stdafx.o Logger.o -o ColorDefense -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	rm -f *.o ColorDefense