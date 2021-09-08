#include <stdio.h>
#include <stdlib.h> // exit()
#include <sys/socket.h> // socket()
#include <netdb.h> // gethostbyname() 
#include <string.h> // bzero(), bcopy()
#include <unistd.h> // read(), write(), close()

void error(const char *msg)
{
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[])
{
  int port_no, sockfd, no_of_bytes;
  struct hostent *server;
  struct sockaddr_in serv_addr;
  char buffer[256];

  if(argc < 3)
  {
    fprintf(stderr, "Usage %s hostname port\n", argv[0]);
    exit(0);
  }
  port_no = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0)
  {
    error("ERROR opening socket");
  }

  server = gethostbyname(argv[1]);
  if(server == NULL)
  {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }

  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET; // address family(i.e Internet Protocol V4) is always AF_INET when TCP is used.
  bcopy((char *)server->h_addr, 
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = htons(port_no); // htons() function converts the unsigned short integer hostshort from host byte order to network byte order.
 
  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    error("ERROR connecting");
  }

  printf("Please enter the message: ");
  bzero(buffer, 256);
  fgets(buffer, 255, stdin); 

  no_of_bytes = write(sockfd, buffer, strlen(buffer));
  if(no_of_bytes < 0)
  {
    error("ERROR writing to socket");
  }
  
  bzero(buffer, 256);
  no_of_bytes = read(sockfd, buffer, 255);
  if(no_of_bytes < 0)
  {
    error("ERROR reading from socket");
  }

  printf("%s\n", buffer);
  
  close(sockfd);

  return 0;
}

/*OUTPUT:-)
./a.out localhost 8899
Please enter the message: Gitanjali Jedhe
I got your message
*/
