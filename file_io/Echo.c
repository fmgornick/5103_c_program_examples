#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE  256

void  main (int argc, char* argv[])  {
char  buffer[BUFSIZE];
ssize_t  count;

    while (  (count=read(STDIN_FILENO, buffer, BUFSIZE)) > 0 ) {
          if ( write ( STDOUT_FILENO, buffer, count) != count ) { 
             perror ("Error in writing" );
             exit(1);
          }
    } 
}
