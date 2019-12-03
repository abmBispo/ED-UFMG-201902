CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
EXEC=./tp3

.PHONY: all build test clean
all: build test clean

build:
	$(CC) $(CFLAGS) -c src/node.cpp -o node.o
	$(CC) $(CFLAGS) -c src/linked_list.cpp -o linked_list.o
	$(CC) $(CFLAGS) -c src/hash.cpp -o hash.o
	$(CC) $(CFLAGS) src/main.cpp node.o linked_list.o hash.o -o $(EXEC)

test: ${EXEC}
	@bash run_tests.sh ${EXEC}

clean:
	@rm -rf *.o ${EXEC}
