all: bdlist

bdlist.o: listbd.c listbd.h
	gcc -c listbd.c
main.o: main.c
	gcc -c main.c

bdlist: bdlist.o main.o
	gcc listbd.o main.o -o bdlist
	


