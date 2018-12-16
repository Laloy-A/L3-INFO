CC = gcc
CFLAGS = -W -Wall -g
LDFLAGS =

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = prog

all : $(AOUT)

prog : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lm
clean :
	@rm *.o
cleaner : clean
	@rm -lm $(AOUT)
