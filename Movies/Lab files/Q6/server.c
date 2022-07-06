#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    if(argc<2){
        fprintf(stderr, "Port no. not provided. Program terminated\n");
        exit(1);
    }

    int sockfd, newsockfd, portno, n;
    char buffer[255];

    // sockaddr_in gives us the internet address, it is included in the file <netinet/in.h>
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;      			//socklen_t is a datatype in socket.h 

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0){
        error("Error opening socket.");
    }

    //bzero clears any data or text into whatever it is referenced to
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);    //htons = host to network short


//we need to typecast sockaddr_in into sockaddr
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
        error("Binding failed.");
    }


// Next step is Listening
    listen(sockfd, 5);					// 5 gives the max. limit of clients
    clilen = sizeof(cli_addr); 

    // Next, whenever we accept a connection, we get a new file descriptor
    // again we need to typecast sockaddr_in into sockaddr
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if(newsockfd<0){
        error("Error on accept!");
    }

    FILE *fp;
    char ch=0;
    fp = fopen("received_file.txt", "w");
    int words;
    
    read(newsockfd, &words, sizeof(int));
    while(ch!=words){
    	read(newsockfd, buffer, 255);
    	fprintf(fp, "%s ", buffer);
    	ch++;
    }
    
    printf("The file has been received successfully. It is saved by the name 'received_file.txt'");
    
        close(newsockfd);
        close(sockfd);
        return 0;
                        
    }


