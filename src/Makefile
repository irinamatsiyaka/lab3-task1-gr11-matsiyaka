main.o: main.c
	gcc -c main.c -o main.o

main: main.o
	gcc main.o -o main

program: main.o
	gcc main.o -o program

all: program

clean:
	rm -f program main.o
