#include<stdio.h>

int append(char *output,char *append)
{
  
  FILE *fp,*fp1;
  fp=fopen(output,"r");
  fp1=fopen(append,"r");

  char buffer1[100][100],buffer2[100][100],c,final_buffer[1024][1024];
  int i=0,j=0,k,length_output=0,length_append=0;
  while((c=fgetc(fp))!=EOF)
    {
      j=0;
      while(c!='\n')
	{
	  buffer1[length_output][j]=c;
	  c=fgetc(fp);
	  j++;
	  if(c==EOF)
	    {
	      buffer1[length_output][j+1]='\n';
	      break;
	    }
	}      
      buffer1[length_output][j]='\n';
      length_output++;
    }

  while((c=fgetc(fp1))!=EOF)
    {
      j=0;
      while(c!='\n')
  	{
  	  buffer2[length_append][j]=c;
  	  c=fgetc(fp1);
  	  j++;
  	  if(c==EOF)
  	    {
  	      buffer2[length_append][j+1]='\n';
  	      break;
  	    }
  	}
      buffer2[length_append][j]='\n';
      length_append++;
    }

  if(length_output>length_append)
    {
      length_output=length_append;
    }
  
  i=0,j=0;
  while(i<length_output)
     {
       j=0;
       while(buffer2[i][j]!='\n')
	 {
	   final_buffer[i][j]=buffer2[i][j]; 
	   
	   if(buffer2[i][j]==EOF)
	     {
	         break;
	     }
	   
	   j++;
	 }

       k=0;
       while(buffer1[i][k]!='\n')
       	 {
	    final_buffer[i][j]=buffer1[i][k];
       	   if(buffer1[i][k]==EOF)
       	     {
	           break;
       	     }
	      k++;
	     j++;
       	 }
	   final_buffer[i][j]='\n'; 
       i++;
     }
  fclose(fp);
  fclose(fp1);
  
   fp1=fopen(append,"w");
   
   for(j=0;j<length_output;j++)
     {
       k=0;
       while(final_buffer[j][k])
	 {
	   fprintf(fp1,"%c",final_buffer[j][k]);
	  
	   k++;
	 }
      
     }
   fclose(fp1);
  
  
}
