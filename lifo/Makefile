CC=gcc
FLAGS=-Wall -pedantic -std=c99

NAME=lifo
OBJS= lifo.o      \
	  intLifo.o   \
	  floatLifo.o \
	  charLifo.o

TESTOBJ= test.o      \
         lifo.test.o

lib: $(OBJS)
	$(CC) -shared -o lib$(NAME).so $(OBJS) -lm

lifo.o: srcs/lifo.c headers/lifo.h
	$(CC) $(FLAGS) -c srcs/lifo.c
intLifo.o: srcs/intLifo.c headers/lifo.h
	$(CC) $(FLAGS) -c srcs/intLifo.c
floatLifo.o: srcs/floatLifo.c headers/lifo.h
	$(CC) $(FLAGS) -c srcs/floatLifo.c
charLifo.o: srcs/charLifo.c headers/lifo.h
	$(CC) $(FLAGS) -c srcs/charLifo.c

test: lib
	$(CC) -c lifo-test/lifo.test.c
	$(CC) -c test.c
	$(CC) -L./ -l$(NAME) -o test $(TESTOBJ)

clean: cleanTest
	rm -rf lib$(NAME).so $(OBJS)

cleanTest:
	rm -rf $(TESTOBJ) test
