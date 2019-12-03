CC=g++
CFLAGS=-Wall -Wextra
EXEC=./tp1
TMPOUT=tp1.testresult

.PHONY: all build test clean

all: build test clean

build:
	$(CC) $(CFLAGS) -c src/node.cpp -o node.o
	$(CC) $(CFLAGS) -c src/list.cpp -o list.o
	$(CC) $(CFLAGS) src/main.cpp node.o list.o -o $(EXEC)

mem:
	valgrind $(EXEC)

test: $(build)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf list.o node.o
