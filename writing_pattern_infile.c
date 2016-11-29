#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "matrix_addition_letter1.h"

int possition_in_pattern(char format,char *buffer)
{
  int i=0;
  while(buffer[i])
    {
      if(format==buffer[i])
	{
	  return i;
	}
      i++;
    }
}



void write_pattern(FILE *fp1,char *file_name,int number)
{
  FILE *fp;
  int i=0,j;
  fp=fopen(file_name,"r");
  
  char strings[12311],c,array[1024][1024];
  while((c=fgetc(fp))!=EOF)
    
    {
      if(c=='#')
	{
	  i++;
	}
      
      if(i==number && c!='#' && c!='@')
	{
	  fprintf(fp1,"%c",c);
	}
    }
  fclose(fp);
}



void write_in_file(char *file_name,char *pattern,char *buffer)
{
  FILE *fp,*fp1;
  int i=0,flag=0;
  if(strstr(file_name,".flf")==NULL)
    {
      strcat(file_name,".flf");
    }
    while(pattern[i])
    {
     fp=fopen("output.txt","w");
     
       write_pattern(fp,file_name,possition_in_pattern(pattern[i],buffer));
       fclose(fp);
      if(flag==0)
	{
	  fp1=fopen("append.txt","w");
	   write_pattern(fp1,file_name,possition_in_pattern(pattern[i],buffer));
	  fclose(fp1);
	  flag=1;
	}
      else
	{
	  append("output.txt","append.txt");
	}
      
      i++;
     
    }
  
  
}





int main(int argc,char *argv[])
{
  int i=0,j;
   char *pattern=argv[1];
   char *file_name=argv[2];
   
   char cwd[1024];
   getcwd(cwd, sizeof(cwd));
   strcat(cwd,"/figlet/fonts/");
   strcat(cwd,file_name);
   strcpy(file_name,cwd);
   char buffer[1024];
  char name[]={'!','"','#','$','%','(',')','*','+',',','-','.','/',':',';','{','=','}','?','@','[',']','_'};

  
  while(name[i])
    {
      buffer[i]=name[i];
      i++;
    }
  for(j=0;j<=9;j++,i++)
    {
      buffer[i]=j+'0';
    }
  
  for(j='A';j<='Z';j++,i++)
    {
      buffer[i]=j;
    }

  for(j='a';j<='z';j++,i++)
    {
      buffer[i]=j;
    }


   write_in_file(file_name,pattern,buffer);

}
