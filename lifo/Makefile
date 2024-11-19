CC=gcc
FLAGS=-Wall -pedantic -std=c99

NAME=lifo
OBJS= lifo.o    \
	  intLifo.o

lib: $(OBJS)
	$(CC) -shared -o lib$(NAME).so $(OBJS) -lm

lifo.o: srcs/lifo.c headers/lifo.h
	$(CC) $(FLAGS) -c srcs/lifo.c
intLifo.o: srcs/intLifo.c headers/lifo.h
	$(CC) $(FLAGS) -c srcs/intLifo.c

test: lib
	$(CC) test.c -L./ -l$(NAME) -o test

clean:
	rm -rf lib$(NAME).so $(OBJS)
