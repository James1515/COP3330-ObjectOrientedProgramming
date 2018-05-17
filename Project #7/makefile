#======================================
# Author: James Anthony Ortiz
# File: makefile
# Purpose: makefile for project #7
#=======================================


CC = g++ -std=c++11
cflags = -I. -Wall -Wextra

AREA51 = /home/courses/cop3330p/LIB/area51

all: fstack.x constTest.x

fstack.x: tstack.h fstack.cpp
	$(CC) -o fstack.x fstack.cpp

fstack_char.x: tstack.h fstack.cpp
	$(CC) -o fstack_char.x fstack.cpp

fstack_int.x: tstack.h fstack.cpp
	$(CC) -o fstack_int.x fstack.cpp

fstack_string.x: tstack.h fstack.cpp
	$(CC) -o fstack_string.x fstack.cpp

fstack_T.x: tstack.h fstack.cpp
	$(CC) -o fstack_T.x fstack.cpp

constTest.x: constTest.o
	$(CC) -o constTest.x constTest.o

#-------------Object Files---------------#

fstack.o: tstack.h fstack.cpp
	$(CC) $(cflags) -c fstack.cpp

fstack_char.o: tstack.h fstack.cpp
	$(CC) $(cflags) -c fstack.cpp

fstack_int.o: tstack.h fstack.cpp
	$(CC) $(cflags) -c fstack.cpp

fstack_string.o: tstack.h fstack.cpp
	$(CC) $(cflags) -c fstack.cpp

fstack_T.o: tstack.h fstack.cpp
	$(CC) $(cflags) -c fstack.ccp

constTest.o: tstack.h constTest.cpp
	$(CC) $(cflags) -c constTest.cpp

#---------------Clean---------------#
clean:
	rm *.o
