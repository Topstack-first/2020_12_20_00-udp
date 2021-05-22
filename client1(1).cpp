/*----- Include files */
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>
using namespace std;

/*----- Defines*/
#define  PORT_NUM        9082
#define  IP_ADDR "139.103.64.13"

/*===== Main program*/
int  main(void)
{
  unsigned int         server_s;
  struct sockaddr_in   server_addr;
  char                 out_buf[100];
  char                 in_buf[100];

    server_s = socket(AF_INET, SOCK_STREAM, 0);

     server_addr.sin_family      = AF_INET;         /* Address family to use*/
     server_addr.sin_port        = htons(PORT_NUM);    /* Port num to use*/
     server_addr.sin_addr.s_addr = inet_addr(IP_ADDR); /* IP address to use*/
    connect(server_s, (struct sockaddr *)&server_addr, sizeof(server_addr));

     strcpy(out_buf, "Message du client au serveur");
     send(server_s, out_buf, (strlen(out_buf) + 1), 0);

     recv(server_s, in_buf, sizeof(in_buf), 0);
     cout <<"Message Recu du serveur ... donnee  =  \n"<< in_buf<< endl;

   close(server_s);
  return (0);
}
