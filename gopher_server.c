#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include "help_command.h"
#include "help_command1.h"
#include "list_all_font.h"
#include "check_pattren.h"
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#define MAX 99999999


void error(char *msg)
{
  perror(msg);
  exit(1);
}
int main()
{
  FILE *fp,*fp1,*fp2;
  char *buffer1,mybuffer[1024];
  char pattern[20];
  char *pattern1;
  char cwd[1024];
  int i=0;
  getcwd(cwd, sizeof(cwd));
  strcat(cwd,"/figlet/fonts");
  
  
  int sockfd,newsockfd,portno,clilen,k;
  char buffer[2546];
  pid_t childpid;
  struct sockaddr_in serv_addr,cli_addr;
  int n;
  
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  bzero((char *)&serv_addr,sizeof(serv_addr));
  portno=7070;
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_addr.s_addr=INADDR_ANY;
  serv_addr.sin_port=htons(portno);
  
  bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)); 
  k=listen(sockfd,5);

  for (;;) {
    clilen=sizeof(cli_addr);
    newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
    
    printf("Connection accepted...\n");

    if ((childpid = fork()) == 0) { 
      while(1) {
	bzero(buffer,1024);
	read(newsockfd,buffer,355);
	
	if(strstr(buffer,"--list-font") || strstr(buffer,"-l"))
	  {
	    only_ls_command(cwd);
	    fp1=fopen("all_font.lst","r");
	    buffer1=help(fp1);
	    fclose(fp1);
	    remove("append.txt");
	   
	  }


	
	
	else if(strstr(buffer,"--help") || strstr(buffer,"-h"))
	  {
	    fp=fopen("help.txt","r");
	    buffer1=help(fp); 
	    fclose(fp);
	  }
	
	 else  
	   {
	     
	     pattern1=strtok(buffer," ");
	     pattern1=strtok(NULL," ");
	     strcpy(pattern,pattern1);
	     figlet_getway(pattern,buffer);
	     fp2=fopen("append.txt","r");
	     if(fp2!=NULL)
	       {
		 buffer1=help(fp2);
		 fclose(fp2);
	       }
	     else
	       {
		 strcpy(buffer1,"\n\n''FONT FORMAT IS NOT SUPPORT''\n");
	       }
	   }
	
	 write(newsockfd,buffer1,strlen(buffer1));
        
      }
    }
    close(newsockfd);
  }
}
