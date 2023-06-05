#include<stdio.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
int sockfd,portno,wri,rea;
struct sockaddr_in serv_addr;
char buffer[256];
//creating socket
sockfd =socket(AF_INET, SOCK_STREAM,0);
if (sockfd<0)
printf("error while creating socket");
portno = atoi(argv[1]);
serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(portno);
serv_addr.sin_addr.s_addr=INADDR_ANY;
//connect to server
if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
printf("error while connecting");
printf("Please enter the message: ");
bzero(buffer,256);
fgets(buffer,255,stdin);
//write to server
wri = write(sockfd,buffer,strlen(buffer));
if (wri<0)
printf("error while writing");
bzero(buffer,256);
//read from server
rea = read(sockfd,buffer,255);
if(rea<0)
printf("error while reading");
else
printf("%s\n",buffer);
return 0;
}