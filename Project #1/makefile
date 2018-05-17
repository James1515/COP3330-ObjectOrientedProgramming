# 
# makefile distributed for cstringsort project
#

all:      ssort.x sdiff.x test.x

ssort.x:  main.o cstringsort.o
	g++ -std=c++11 -Wall -Wextra -o ssort.x main.o cstringsort.o

sdiff.x:  sdiff.o cstringsort.o
	g++ -std=c++11 -Wall -Wextra -o sdiff.x sdiff.o cstringsort.o

test.x:   main_i.o cstringsort.o
	g++ -std=c++11 -Wall -Wextra -o test.x main_i.o cstringsort.o

main_i.o: /home/courses/cop3330p/LIB/area51/main_i.o
	cp   /home/courses/cop3330p/LIB/area51/main_i.o main_i.o

main.o:   main.cpp cstringsort.h
	g++ -std=c++11 -Wall -Wextra -c -I. main.cpp

sdiff.o:   sdiff.cpp cstringsort.h
	g++ -std=c++11 -Wall -Wextra -c -I. sdiff.cpp

cstringsort.o:   cstringsort.h cstringsort.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. cstringsort.cpp

