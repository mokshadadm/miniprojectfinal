all: project

project: main.o 
	cc main.o -lform -lmenu -lncurses -o project

main.o : main.c functions.h
	cc -c main.c
	
clear :
	rm -rf *.o	

