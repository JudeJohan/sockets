CC=g++
STD=-std=c++11
SWITCHES=-pedantic -Wall -Wextra
CFLAGS=$(STD) $(SWITCHES)
# SOURCES=test.cc testlib.cc

SRC_TEST=test.cc testlib.cc
EXE_TEST=debug.out

SRC_DEV=debmir.cc
EXE_DEV=server.out


.PHONY: test
test:
	$(CC) $(CFLAGS) $(SRC_TEST) -o $(EXE_TEST)

# g++ -std=c++11 -pedantic -Wall -Wextra test.cc testlib.cc

all:
	@echo Use make test och make dev

dev:
	$(CC) $(CFLAGS) $(SRC_DEV) -o $(EXE_DEV)
