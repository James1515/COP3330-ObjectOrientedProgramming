#
# File: makefile
# Purpose: makefile for function template project #6
#

CC = g++ -std=c++11 -Wall -Wextra -I.

all: charsort.x intsort.x stringsort.x productsort.x
extra: all diffcalc.x

intsort.x: tsort.h intsort.cpp
	$(CC) -o intsort.x intsort.cpp

charsort.x: tsort.h charsort.cpp
	$(CC) -o charsort.x charsort.cpp

stringsort.x: tsort.h stringsort.cpp
	$(CC) -o stringsort.x stringsort.cpp

productsort.x: product.o productsort.o cstringdiff.o
	$(CC) -o productsort.x product.o productsort.o cstringdiff.o

productsort.o: tsort.h product.h productsort.cpp
	$(CC) -c productsort.cpp

cstringdiff.o: cstringdiff.h cstringdiff.cpp
	$(CC) -c cstringdiff.cpp

product.o: product.h product.cpp
	$(CC) -c product.cpp

diffcalc.x: diffcalc.o cstringdiff.o
	$(CC) -o diffcalc.x diffcalc.o cstringdiff.o

diffcalc.o: cstringdiff.h diffcalc.cpp
	$(CC) -c diffcalc.cpp

