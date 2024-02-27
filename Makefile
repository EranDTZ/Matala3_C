List = StrList.o
Main = main.o
CC = gcc
AR = ar -rcs
FLAGS = -Wall -g


Lists: libList.a
libList.a: $(List)
	$(AR) -o libList.a $(List) 

StrList: libList.a $(Main)
	$(CC) $(FLAGS) -o StrList libList.a $(Main)

main.o: main.c StrList.h
	$(CC) $(FLAGS) -c main.c 

all: Lists StrList main.o


.PHONY: clean all

clean:
	rm -f *.o *.a Lists StrList Main.o