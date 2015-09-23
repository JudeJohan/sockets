#include <iostream>

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

int main(int narg, char* varg[]) {
    (void)narg;
    (void)varg[0];



    return 0;
}
