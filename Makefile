CC = g++
CFLAGS = --std=c++11 -Wall
LDFLAGS = -lncurses
LDLIBS = -lncurses

SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
AOUT = main
 
all : $(AOUT) 
 
main : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	@rm *.o
mrproper : clean
	@rm $(AOUT)
