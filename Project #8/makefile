#===================================
# Author: James Anthony Ortiz
# File: makefile
# Purpose: makefile for Project #8
#===================================


CC = g++ -std=c++11 -Wall -Wextra -I.

all: fstack.x fqueue.x in2post.x

in2post.x: in2post.cpp
        $(CC) -o in2post.x in2post.cpp

fstack.x: tstack.h fstack.cpp
	$(CC) -o fstack.x fstack.cpp

fqueue_char.x: tqueue.h fqueue.cpp
	$(CC) -o fqueue_char.x fqueue.cpp

fqueue_int.x: tqueue.h fqueue.cpp
	$(CC) -o fqueue_int.x fqueue.cpp

fqueue_String.x: tqueue.h fqueue.cpp
	$(CC) -o fqueue_String.x fqueue.cpp

fqueue_T.x: tqueue.h fqueue.cpp
	$(CC) -o fqueue_T.x fqueue.cpp

in2post.x: in2post.cpp
	$(CC) -o in2post.x in2post.cpp


#Object Targets:
fqueue_char.o: tqueue.h fqueue.cpp
	$(CC) -c fqueue.cpp

fqueue_int.o: tqueue.h fqueue.cpp
	$(CC) -c fqueue.cpp

fqueue_string.o: tqueue.h fqueue.cpp
	$(CC) -c fqueue.cpp

fqueue_T.o: tqueue.h fqueue.cpp
	$(CC) -c fqueue.cpp

in2post.o: tstack.h tqueue.h in2post.cpp
	$(CC) -c in2post.cpp

id.o: id.h id.cpp
	$(CC) -c id.cpp

#==========Clean============#

clean:
	rm *.o
