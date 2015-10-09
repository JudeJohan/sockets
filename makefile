CC=g++
STD=-std=c++11
SWITCHES=-pedantic -Wall -Wextra
CFLAGS=$(STD) $(SWITCHES)
# SOURCES=test.cc testlib.cc

SRC_TEST=test.cc testlib.cc
EXE_TEST=debug.out

SRC_DEV=debmir.cc jjsockets.cc
EXE_DEV=server.out

SRC_CLI=debcli.cc jjsockets.cc
EXE_CLI=client.out


all:
	@echo Use make test or make dev or make cli


.PHONY: test
test:
	@$(CC) $(CFLAGS) $(SRC_TEST) -o $(EXE_TEST)

# g++ -std=c++11 -pedantic -Wall -Wextra test.cc testlib.cc

.PHONY: dev
dev:
	@$(CC) $(CFLAGS) $(SRC_DEV) -o $(EXE_DEV)

.PHONY: cli
cli:
	@$(CC) $(CFLAGS) $(SRC_CLI) -o $(EXE_CLI)

.PHONY: all test dec cli
