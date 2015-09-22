#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PROTTYPE 0x01
#define UDP 0x00
#define TCP 0x01

using namespace std;

void print_hello(string s);

class Server {
public:
	Server(int port, int mode);
	Server() = delete;
	Server(const Server&) = delete;

	Server& operator=(const Server&) = delete;

private:
	char ctl;
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
};

class Client {
public:

private:

};

#endif
