#include <stdio.h>
#include <stdlib.h> // exit()
#include <sys/socket.h> // socket()
#include <string.h> // bzero() 
#include <netinet/in.h> // struct sockaddr_in
#include <unistd.h> // read(), write(), close()

void error(const char *msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sockfd, port_no, cli_sockfd, no_of_bytes;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t cli_len;
  char buffer[256];

  if(argc < 2)
  {
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  if(sockfd < 0)
  {
    error("ERROR opening socket");
  }

  bzero((char *)&serv_addr, sizeof(serv_addr));

  port_no = atoi(argv[1]);
  serv_addr.sin_family = AF_INET; // address family(i.e Internet Protocol V4) is always AF_INET when TCP is used.
  serv_addr.sin_addr.s_addr = INADDR_ANY; // constant defined in <netinet/in.h> 
  serv_addr.sin_port = htons(port_no); // htons() function converts the unsigned short integer hostshort from host byte order to network byte order.

  if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    error("ERROR on binding");
  }

  listen(sockfd, 5);

  cli_len = sizeof(cli_addr);

  cli_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);

  if(cli_sockfd < 0)
  {
    error("ERROR on accept");
  }

  bzero(buffer, 256);

  no_of_bytes = read(cli_sockfd, buffer, 255);
  if(no_of_bytes < 0)
  {
    error("ERROR reading from socket");
  }
  printf("Message from client : %s", buffer);

  no_of_bytes = write(cli_sockfd, "I got your message", 18);
  if(no_of_bytes < 0)
  {
    error("ERROR writing to socket");
  }

  close(cli_sockfd);
  close(sockfd);

  return 0;
}

/*OUTPUT:-)
./a.out 8899
Message from client : Gitanjali Jedhe
*/

