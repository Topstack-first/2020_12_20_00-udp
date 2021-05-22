#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

#define  PORT_NUM   9082
#define  MAX_LISTEN    5
using namespace std;

int main(void)
{
  unsigned int         server_s;
  struct sockaddr_in   server_addr;
 unsigned int         client_s;
  struct sockaddr_in   client_addr;
  struct in_addr       client_ip_addr;
  unsigned  int        addr_len;
  char                 out_buf[100];
  char                 in_buf[100];
  int i;

  server_s = socket(AF_INET, SOCK_STREAM, 0);

  server_addr.sin_family      = AF_INET;
  server_addr.sin_port        = htons(PORT_NUM);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(server_s, (struct sockaddr *)&server_addr, sizeof(server_addr));

  listen(server_s, MAX_LISTEN);

  addr_len = sizeof(client_addr);
  client_s = accept(server_s, (struct sockaddr *)&client_addr, &addr_len);

  recv(client_s, in_buf, sizeof(in_buf), 0);
  cout <<"donnees recu du  client=  \n"<< in_buf<<endl;

  strcpy(out_buf, "Message -- server  uclient");
  send(client_s, out_buf, (strlen(out_buf) + 1), 0);

   close(client_s);
   close(server_s);

   return (0);

}

