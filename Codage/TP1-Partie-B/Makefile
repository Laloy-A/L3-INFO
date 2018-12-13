CC = gcc
CFLAGS = -W -Wall -g
LDFLAGS =

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = main

all : $(AOUT)

main : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lm
main.o : main.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	@rm *.o
cleaner : clean
	@rm -lm $(AOUT)
