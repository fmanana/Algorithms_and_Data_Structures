CC = g++
CFLAGS = -Wall

all: main

main: rbt.o testRBT.o
	$(CC) $(CFLAGS) -o main rbt.cpp testRBT.cpp

rbt.o: rbt.cpp
	$(CC) $(CFLAGS) -c rbt.cpp
	
testRBT.o: testRBT.cpp
	$(CC) $(CFLAGS) -c testRBT.cpp

clean:
	rm -f *.o