CC=g++
CFLAGS=-Wall -Wextra
EXEC=./tp2
TMPOUT=tp2.testresult
.PHONY: all build test clean
all: build test clean
build:
	$(CC) $(CFLAGS) -c src/utils.cpp -o utils.o
	$(CC) $(CFLAGS) -c src/planet.cpp -o planet.o
	$(CC) $(CFLAGS) -c src/agenda.cpp -o agenda.o
	$(CC) $(CFLAGS) -c src/month_bucket.cpp -o month_bucket.o
	$(CC) $(CFLAGS) -c src/node.cpp -o node.o
	$(CC) $(CFLAGS) -c src/queue.cpp -o queue.o
	$(CC) $(CFLAGS) src/main.cpp utils.o planet.o agenda.o month_bucket.o node.o queue.o -o $(EXEC)
mem:
	valgrind $(EXEC)
test: $(build)
	@bash run_tests.sh $(EXEC) $(TMPOUT)
clean:
	rm -rf planet.o utils.o agenda.o month_bucket.o node.o queue.o
