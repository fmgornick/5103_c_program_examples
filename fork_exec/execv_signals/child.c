#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include  <signal.h>
#include  <unistd.h>
#include  <stdio.h>


/* Child process executes this code */

void myalarm ( int signum ) {
   printf( "Inside Signal handler - received signal number %d\n", signum );
   signal( SIGALRM,   myalarm );
}

void main(int argc, char *argv[])
{
  int retval;

  printf("I am the child process after exec\n");
  printf("Number of args passed to me %d\n", argc);

  signal(SIGALRM, myalarm);

  retval = sleep(60);

  printf("Sleep returned = %d \n", retval );
  
 { int i;
   for (i=0; i<argc; i++) {
     printf("Argument %d is %s \n", i, argv[i] );
    }
 }
}
