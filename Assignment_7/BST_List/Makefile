CC = g++
CFLAGS = -Wall

all: main

main: testBST_LL.o
	$(CC) $(CFLAGS) -o main testBST_LL.o

testBST_LL.o: testBST_LL.cpp
	$(CC) -c testBST_LL.cpp

clean:
	rm -f *.o