#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main (int argc, char* argv[]) {
long maxpath;
char *cwdNamePntr; 
mode_t  perms =  0740;
char confirm[4];

  if ( argc != 2) {
     printf( "Usage: %s Directory-Path-Name\n ", argv[0] );
     exit(1);
  }

  do {  /* Ask for confirmation  */
    printf ("Do you really want to remove %s directrory? (\"yes\" or \"no\") ", argv[1]);
    scanf( "%3s", confirm);
    printf ("You confirmed %s to remove %s directrory?\n", confirm, argv[1]);
   } while ( !((strcmp(confirm, "yes")==0) || (strcmp(confirm, "no")==0)));


  if ( strcmp(confirm, "yes") == 0 ) {
     if ( (rmdir(argv[1])) == 0 ) {
        printf( "Directory deleted:  %s \n",argv[1]);
     }
     else  { 
        fprintf(stderr, "Error in removing  directory named  %s", argv[1]);
        perror(" : ");
     }  
   }
}
