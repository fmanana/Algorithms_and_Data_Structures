CC = g++
CFLAGS = -Wall

all: main

main: testStack.o
	$(CC) $(CFLAGS)	-o main testStack.o

testStack.o: testStack.cpp
	$(CC) -c testStack.cpp

clean:
	rm -f *.o