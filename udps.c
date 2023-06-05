#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
int serv_sockfd,portno,clilen,newsockfd,rec1,i,j,rec2,k=0,sen1;
struct sockaddr_in serv_addr,cli_addr;
char buffer[256];
//creating socket
serv_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
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
//recieve from client
rec1= recvfrom(serv_sockfd,&i, sizeof(i), MSG_WAITALL, ( struct sockaddr
*)&cli_addr,&clilen);
if (rec1<0)
printf("error while recieving");
else
printf( "Received num = %d\n",i);
//recieve from client
rec2= recvfrom(serv_sockfd,&j, sizeof(j), MSG_WAITALL, ( struct sockaddr
*)&cli_addr,&clilen);
if (rec1<0)
printf("error while recieving");
else
printf( "Received num = %d\n",j);

k=i+j;
//send to client
sen1=sendto(serv_sockfd, &k, sizeof(k),MSG_CONFIRM, (const struct sockaddr
*) &cli_addr,clilen);
if (sen1<0)
printf("error while sending");
printf( "sum = %d\n",k);
return 0;
}