#include <iostream>
#include "jjsockets.h"

//inet stuffs

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


//#include <netdb.h> //cln

#include <chrono>

#define SRV_IP "127.0.0.1"

using namespace std;

void error(const string msg, const int code)
{
    perror(msg.c_str());
    exit(code);
}

int main(int narg, char* varg[])
{
#ifdef __WIN32__
    WORD versionWanted = MAKEWORD(1, 1);
    WSADATA wsaData;
    WSAStartup(versionWanted, &wsaData);
#endif
    (void)narg;
    (void)varg[0];

    int sockfd, portno;
    //int newsockfd;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    //int n;

    //CHANGE THIS TO APPROPRIATE PORT NO, available: 25560-25569
    portno = 25569;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) error("Socket creation failed", -1);
    cout << "Socket handle = " << sockfd << endl;

    memset((char*) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    return 0;
}
