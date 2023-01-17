#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>


int main (int argc, char* argv[]) {
char pathname[1024];

  if ( argc != 2) {
     printf( "Usage: %s Directory-Path-Name\n ", argv[0] );
     exit(1);
  }

  if ( (chdir(argv[1])) == 0 ) {
     if ( getcwd(pathname, 1024) )
        printf( "Current Directory changed:  %s\n", pathname);
  }
  else  { 
        fprintf(stderr, "Error in changing working directory to %s", argv[1]);
        perror(" : ");
  }  
}
