
#define MAX 99999999
char buffer[MAX];


char *help(FILE *fileptr)
{
  
  
  int i=0;
  char c;
  

  while((c = fgetc(fileptr)) != EOF)
    {
      
          buffer[i]=c;
      i++;
    }
  
  
  return buffer;
  
}
