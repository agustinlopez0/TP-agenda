# gcc -c sockets.c
# gcc -o main main.c sockets.o
# ./main

all: program

program: main.c slist.c slist.h slist.o
	gcc -o main main.c slist.o

slist.o:
	gcc -c slist.c

clean:
	rm *.o main