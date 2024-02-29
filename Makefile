CC = gcc
CFLAGS = -Wall -Wextra -std=c11

program: main.o
    $(CC) $(CFLAGS) -o program main.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c

clean:
    rm -f program main.o

