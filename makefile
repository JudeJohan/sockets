CC=g++
CFLAGS= -std=c++11 -pedantic -Wall -Wextra
SOURCES=test.cc testlib.cc
EXECUTABLE=debug.out

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

# g++ -std=c++11 -pedantic -Wall -Wextra test.cc testlib.cc
