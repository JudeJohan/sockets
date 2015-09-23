#ifndef JJSOCKET_H
#define JJSOCKETS_H

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#ifdef __WIN32__
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif



#define PROTTYPE 0x01
#define UDP 0x00
#define TCP 0x01



#endif //ifndef JJSOCKETS_H
