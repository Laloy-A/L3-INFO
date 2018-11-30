CC = gcc
CFLAGS = -W -Wall -g
LDFLAGS =

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = hdbn

all : $(AOUT)

hdbn : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lm
hdbn.o : hdbn.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	@rm *.o
cleaner : clean
	@rm -lm $(AOUT)
