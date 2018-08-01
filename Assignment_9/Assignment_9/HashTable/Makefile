CC = g++
CFLAGS = -Wall

all: main

main: testHash.o
	$(CC) $(CFLAGS) -o main testHash.cpp

testHash.o: testHash.cpp
	$(CC) $(CFLAGS) -c testHash.cpp

clean:
	rm -f *.o
