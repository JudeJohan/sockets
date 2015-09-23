#include <iostream>
#include "jjsockets.h"

//inet stuffs

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    return 0;
}
