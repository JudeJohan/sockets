#include <iostream>
#include "testlib.h"

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

void error(const string msg){
	perror(msg.c_str());
	exit(1);
}

int main(int narg, char* varg[])
{
	if(narg == 1){
		cout << "Usage: (/server) [...]" << endl;
		return -1;
	}
	for(int i = 0; i < narg; i++)
	{
		cout << "Arg #" << i << ": " << *(varg+i) << endl;
	}

	using namespace std::chrono;
	cout << duration_cast< hours >( high_resolution_clock::now().time_since_epoch() ).count() << endl;

	//if(narg < 2) error("Usage: [server/client] [port number] [server adress (if client)]");

	string in = *(varg+1);
	bool isClient = false;
	if(in == "client") isClient = true;

	if(narg > 1)
		print_hello(*(varg+1));

	cout << isClient << endl;

	int sockfd, portno;
	//int newsockfd;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	//int n;

	//CHANGE THIS TO APPROPRIATE PORT NO, available: 25560-25569
	portno = 25569;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0) error("Socket creation failed");
	cout << "Socket handle = " << sockfd << endl;

	bzero((char*) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;

	if(!isClient)
		serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	else if(inet_aton(SRV_IP, &serv_addr.sin_addr) == 0)
		error("inet_aton error");

	serv_addr.sin_port = htons(portno);

	if (!isClient){
		if (bind(sockfd, (sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
			error("Socket binding failed. Is it already in use?");
	}
	//listen(sockfd,5);
	clilen = sizeof(cli_addr);
	//newsockfd = accept(sockfd, (sockaddr *) &cli_addr, &clilen);
	//if(newsockfd < 0) error("Error: No accept");

	bzero(buffer, 256);
	//n = read(newsockfd, buffer, 255);
	//if(n < 0) error("Error: reading from socket");

	if(isClient == true){
		sprintf(buffer, "This is packet %d\n", 1337);
		if(sendto(sockfd, buffer, 255, 0, (sockaddr *) &serv_addr, clilen) < 0) error("Could not send datagram");
	}
	else {
		if (recvfrom(sockfd, buffer, 255, 0, (sockaddr *) &cli_addr, &clilen) < 0)
			error("No datagram received");
		cout << "Received datagram from " << inet_ntoa(cli_addr.sin_addr) << ":" << ntohs(cli_addr.sin_port) << " containing:" << endl << buffer << endl;
		if (recvfrom(sockfd, buffer, 255, 0, (sockaddr *) &cli_addr, &clilen) < 0)
            error("No datagram received");
        cout << "Received datagram from " << inet_ntoa(cli_addr.sin_addr) << ":" << ntohs(cli_addr.sin_port) << " containing:" << endl << buffer << endl;
	}
	//printf("Here is the message: %s\n",buffer);
	//n = write(newsockfd,"I got your message",18);
	//if (n < 0) error("ERROR writing to socket");

	//close(newsockfd);
	close(sockfd);

	return 0;
}
