CC=g++
STANDARD=-std=c++11
SWITCHES=-pedantic -Wall -Wextra
CFLAGS=$(STANDARD) $(SWITCHES)
SOURCES=test.cc testlib.cc
EXECUTABLE=debug.out

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

# g++ -std=c++11 -pedantic -Wall -Wextra test.cc testlib.cc
