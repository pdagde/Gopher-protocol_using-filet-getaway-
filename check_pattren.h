#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#define MAX 99999999

char *send_string(char *name)
{
  char *buffer;
  int i=0,j=0;
  while(name[i]!='\n')
    {
      buffer[i]=name[i];
      i++;
    }
  buffer[i]='\0';
  return buffer;
}

int figlet_getway(char file_name[],char pattren[])
{
  char buffer[1024];
  remove("output.txt");
  remove("append.txt");
  system("gcc writing_pattern_infile.c");
  snprintf(buffer, sizeof(buffer), "./a.out %s %s", pattren, file_name);
  system(buffer);
}
