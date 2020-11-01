ifeq ($(OS),Windows_NT)
        uname_S := Windows
        WinBuild = 1
        BFLAGS= -DWinBuild
else
        uname_S := $(shell uname -s)
        BFLAGS=
endif


# Variable declaration
CC = gcc
CC_FLAGS = -w -g

OBJECTS = $(wildcard *.o libcalc test client server)

all: libcalc test client server



servermain.o: servermain.cpp protocol.h
	$(CC) -Wall -c servermain.cpp -I.

clientmain.o: clientmain.cpp protocol.h
	$(CC) -Wall -c clientmain.cpp -I.

main.o: main.cpp protocol.h
	$(CC) -Wall -c main.cpp -I.


test: main.o calcLib.o
	$(CC) -L./ -Wall -o test main.o #-lcalc

client: client.o calcLib.o
	$(CC) -L./ -Wall -o client client.o #-lcalc

server: server.o calcLib.o
	$(CC) -L./ -Wall -o server server.o #-lcalc




calcLib.o: calcLib.c calcLib.h
	gcc -Wall -fPIC -c calcLib.c

libcalc: calcLib.o
	ar -rc libcalc.a -o calcLib.o

clean:
	rm *.o *.a test server client
