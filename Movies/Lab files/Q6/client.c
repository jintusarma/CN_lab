/*
CL Args: Filename SERVER_IP_ADDR PORTNO
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<ctype.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    if(argc<3){
        fprintf(stderr, "Usage: %s Hostname Port \n", argv[0]);
        exit(1);
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    struct hostent *server;      //hostent structure is used to store info. about a given host; included in <netdb.h>

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd<0)
        error("Error opening socket.");
    
    server = gethostbyname(argv[1]);
    if(server==NULL){
        fprintf(stderr, "No such host");
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    
    //Transferring info. from *server into serv_addr
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    
    serv_addr.sin_port = htons(portno);

//Next try connecting to the server
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
        error("Connection failed");
    
	FILE* f;
	int words=0;
	char c;
	f = fopen("file1.txt", "r");
	
	while((c=getc(f)) != EOF){
	
	fscanf(f, "%s", buffer);
	if(isspace(c) || c =='\t')
	words++;
	}
	
	write(sockfd, &words, sizeof(int));
	rewind(f);
	
	char ch;
	while(ch!= EOF){
	fscanf(f, "%s", buffer);
	write(sockfd, buffer, 255);
	ch = fgetc(f);
	
	}
	
	printf("The file has been successfully sent");	
        bzero(buffer, 255);
        
    
    close(sockfd);
    return 0;
}




