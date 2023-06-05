#include<stdio.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
int serv_sockfd,portno,clilen,newsockfd,rea,wri,i,j,k;
struct sockaddr_in serv_addr,cli_addr;
char buffer[256],buffer1[256];
//creating socket
serv_sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (serv_sockfd<0)
printf("error while creating socket");
portno = atoi(argv[1]);
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY;
serv_addr.sin_port = htons(portno);
//binding
if(bind(serv_sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr))<0)
printf("error in bind");
//listen to the client
listen(serv_sockfd,5);
clilen = sizeof(cli_addr);
//accept connection
newsockfd = accept(serv_sockfd, (struct sockaddr *) &cli_addr, &clilen);
if (newsockfd<0)

printf("error while accepting");

bzero(buffer,256);
//read from client
rea = read(newsockfd,buffer,255);
if(rea<0)
printf("error while reading");
else
printf("Here is the message: %s\n",buffer);
k = strlen(buffer);
k--;
//reversing
for(j=0;k>=0;k--,j++)
buffer1[j]= buffer[k];
buffer1[j]='\0';
//write to client
wri = write(newsockfd,buffer1,255);
if (wri<0)
printf("error while writing");
return 0;
}