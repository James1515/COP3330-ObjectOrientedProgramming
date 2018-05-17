#----------------------------------------------
# Author: James Ortiz
# File: makefile for project #2
# Purpose: To build exectbs. producttest1.x &
# producttest2.x
# Files: product.h, producttest1.cpp, producttest2.cpp
# product.cpp
#----------------------------------------------

#Compiler:
CC = g++ -std=c++11

#CFlags:
CFLAGS = -g -Wall -Wextra -c 

#LFLAGS:
LFLAGS = -g -Wall -Wextra 

#OBJS:
OBJS = product.o producttest1.o producttest2.o 


all: producttest1.x producttest2.x

producttest1.x: product.o producttest1.o
	$(CC) $(LFLAGS) -o producttest1.x product.o producttest1.o 

producttest2.x: product.o producttest2.o
	$(CC) $(LFLAGS) -o producttest2.x product.o producttest2.o 

product.o: product.cpp product.h
	$(CC) $(CFLAGS) -I. product.cpp

producttest1.o: producttest1.cpp product.h
	g++ -std=c++11 -Wall -Wextra -c -I. producttest1.cpp

producttest2.o: producttest2.cpp product.h
	g++ -std=c++11 -Wall -Wextra -c -I. producttest2.cpp

clean:
	rm *.o

 
