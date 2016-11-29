#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#define MAX 99999999



char *removeextention(char* mystr)
{
  char *retstr;
  char *lastdot;
  if (mystr == NULL)
    return NULL;
  if ((retstr = malloc (strlen (mystr) + 1)) == NULL)
    return NULL;
  strcpy (retstr, mystr);
  lastdot = strrchr (retstr, '.');
  if (lastdot != NULL)
    *lastdot = '\0';
  return retstr;
}







void only_ls_command(char *path)
{
  DIR *dir;
  struct dirent *ent;
  char temp[99999];
  int i=0,line=0;
    FILE *fp;

  fp=fopen("all_font.lst","w");

  if((dir = opendir(path))!=NULL)
    {
       fprintf(fp,"\n\n%s \n\n","LIST OF ALL SUPPORTED FONTS CLI ARE");
      while((ent =readdir(dir))!= NULL)
	{
	  //printf("%s\n",ent->d_name);
	  if(strstr(ent->d_name,".flf"))
	    {
	      if(i%5==0)
		{
		  fprintf(fp,"%s \n",removeextention(ent->d_name));
		  line++;
		}
	      else
		{
		   fprintf(fp,"%s\t",removeextention(ent->d_name));
		}
	      i++;
	    }
	}
    }
  if(line<20)
    {   
      while(line<10)
	{
	  line++;
	  fprintf(fp,"\n%s \n\n\n","                                      ");
	}
      fprintf(fp,"\n%s \n\n","------------------------------------------------");
    }
  closedir (dir);
  fclose(fp);
}





/* int main() */
/* { */
  
 

/*   char cwd[1024]; */
/*   getcwd(cwd, sizeof(cwd)); */
/*   strcat(cwd,"/figlet/fonts"); */
 
  
  
/*   only_ls_command(cwd); */
/*   return 0; */

/* } */
