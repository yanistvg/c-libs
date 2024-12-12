CC=gcc
FLAGS=-Wall -pedantic -std=c99

NAME=fifo
OBJS= fifo.o

lib: $(OBJS)
	$(CC) -shared -o lib$(NAME).so $(OBJS) -lm

fifo.o: srcs/fifo.c headers/fifo.h
	$(CC) $(FLAGS) -c srcs/fifo.c

clean:
	rm -rf lib$(NAME).so $(OBJS)
