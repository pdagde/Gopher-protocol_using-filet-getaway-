#include <stdio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include<string.h>
 #include<stdlib.h>
void error(char *msg)
{
  perror(msg);
  exit(0);
}
int main()
{
  int sockfd,portno,n,newsockfd,i;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  
  char buffer[1024];
  portno=7070;
  sockfd=socket(AF_INET,SOCK_STREAM,0);

  server=gethostbyname("localhost");
  
  bzero((char*)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family=AF_INET;
  bcopy((char*)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
  serv_addr.sin_port=htons(portno);
  connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
  
  bzero(buffer,1024);

  /* printf("-------------------------\n"); */
  /* printf("Help          -> --help,-h\n"); */
  /* printf("supported font ->-l,--list-font\n"); */
  /* printf("string and formating word select one among the list  <string> font\n"); */
  /* printf("\n e.g CLI >> HELPSHIFT@123 small \n"); */
  /* printf("CLI >>:   ");  */

  while(fgets(buffer,1024, stdin) != NULL)
    {
      printf("\n-------------------------\n");
      printf("Help         CLI >> --help,-h\n");
      printf("supported font  CLI >>-l,--list-font\n");
      printf("string and formating word select one among the list  <string> font\n");
      printf("\n e.g CLI >> HELPSHIFT@123 small \n");
      printf("CLI >>:   ");     
      
      
	   n=write(sockfd,buffer,strlen(buffer));
	       bzero(buffer,1024);
	       memset(&buffer[0], 0, sizeof(buffer));
	       n=read(sockfd,buffer,1524);
	       fputs(buffer, stdout);
	       
      
      
    }
  return 0;
}
