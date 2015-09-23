CC=g++
STANDARD=-std=c++11
SWITCHES=-pedantic -Wall -Wextra
CFLAGS=$(STANDARD) $(SWITCHES)
SOURCES=test.cc testlib.cc
EXECUTABLE=debug.out


.PHONY: test
test:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

# g++ -std=c++11 -pedantic -Wall -Wextra test.cc testlib.cc

all:
	@echo Use make test och make dev

dev:
	@echo Placeholder for dev stuff
