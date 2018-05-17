#-------------------------------------------
# Author: James Anthony Ortiz
# File: makefile
# Purpose: Makefile for project #3
#--------------------------------------------

LIB = /home/courses/cop3330p/LIB

CC = g++ -std=c++11 -I. -I$(LIB)/cpp -Wall -Wextra

all: fbitvect.x fprime.x prime_below.x

fprime.x: prime.o bitvect.o fprime.o
	$(CC) -o fprime.x prime.o bitvect.o fprime.o

fbitvect.x: prime.o bitvect.o fprime.o
	$(CC) -o fbitvect.x prime.o bitvect.o fprime.o

prime_below.x: prime_below.o bitvect.o prime.o
	$(CC) prime_below.o bitvect.o prime.o -o prime_below.x

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm *.o
	rm fprime.x
	rm fbitvect.x
	rm prime_below.x
