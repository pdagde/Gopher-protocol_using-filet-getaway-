
#define MAX 99999999
char buffer[MAX];


char *help1(FILE *fileptr)
{
  
  
  int i=0;
  char c;
  

  while((c = fgetc(fileptr)) != EOF)
    {
      
          buffer[i]=c;
      i++;
    }
  //buffer[i]='\0';
  
  return buffer;
  
}
