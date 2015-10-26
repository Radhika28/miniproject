project: main.o minipro.o 
	cc main.o minipro.o -o project
main.o: main.c pro.h
	cc -Wall -c main.c
minipro.o: minipro.c pro.h 
	cc -Wall -c minipro.c 

