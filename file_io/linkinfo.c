/*                          
     Introduction to Operating Systems CSCI 4061
This program demonstrates the use of readlink and lstat system call to display 
link information about links in a ginve directory.


The argument to this program is a directory path.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define NAMESIZE 1024

int main(int argc, char *argv[])
{
    /* Declarations */
    struct stat statbuf;
    char *dirname;
    char linkinfo[1024];
    char filepath[1024];
    int retval;
    DIR *dp; 
    struct dirent *direntry;
    int totalsum = 0;
    dirname = (char*)malloc(NAMESIZE*sizeof(char));
    /* End of declarations */

    if(argc < 2)       /*If the user does not enter any directory name*/
    {
	    printf("No directory name specified. Executing the function in the current directory.\n");
	    dirname = getcwd(dirname, NAMESIZE);
    }
    else              /* If the user enters a directory name */
    {
	    dirname = getcwd(dirname, 1024);
        strcat(dirname,"/");
        strcat(dirname,argv[1]);

    }
    /* Check if the directory entered exists or not*/
    stat(dirname,&statbuf);
    if(!(S_ISDIR(statbuf.st_mode))){
        printf("The directory name is not valid. Directory does not exist\n");
        exit(1);
    }

    if((dp=opendir(dirname))==NULL){
        perror("Error while opening the directory");
        exit(2);
    }
    /* Loop through the directory structure */
    chdir(dirname); //previously missing
    while( (direntry = readdir(dp)) != NULL )
    {
	
      /*************************/ 
      lstat(direntry->d_name,&statbuf);
      
      if (S_ISDIR(statbuf.st_mode)) {
	    printf("Dir: %s\n",direntry->d_name);
      }
      if (S_ISREG(statbuf.st_mode)) {
	    printf("Reg: %s\n",direntry->d_name);
      }
      if (S_ISLNK(statbuf.st_mode)) {
   	    printf("Lnk: %s\n",direntry->d_name);

        strcpy( filepath, dirname);
        strcat(filepath, "/");
        strcat(filepath, direntry->d_name);

        /* filepath contains the fullpath of the link entry in the directory */

        printf("Link entry path: %s\n", filepath); 

        /*  readlink will obtain and store the link information in linkinfo array  */
        if ( (retval = readlink(filepath, linkinfo, 1024)) == -1 ) {
           perror("Error reading symbolic information");
           exit(2);
        };  
        
        linkinfo[retval] = '\0';
   	    printf("Link Information:  %s\n",   linkinfo );
      }
      /*************************/
      
    }
    
    
}
