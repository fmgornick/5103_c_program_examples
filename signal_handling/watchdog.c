#include  <signal.h>
#include  <stdio.h>
#include  <unistd.h>
#include  <stdlib.h>
#include <sys/wait.h>

/*   comple 								*/
/*   cc watchdog.c -o watchdog 				*/
/* 	 Example execution:						*/
/*	 Run longsleep under watchdog			*/
/*     watchdog -2 longsleep				*/
/*	 Now try								*/
/*     watchdog -20 longsleep				*/


int cpid;

int main ( int argc, char *argv[]) {
int  sec = 10;
int status;
void onTimeout( int );
char *progname;

   progname =  argv[0];
   int i;

   if (argc < 2 ) { 
      printf("Usage: %s [-10] command \n", progname);
      exit(1);
   }

   for (i=0; i< argc ; i++) {
     printf(" Argv %d is %s \n", i, argv[i] );
   }

   if ( argc > 1 && argv[1][0] == '-' ) {
        sec =  atoi(++(argv[1]));
        printf("Timeout is set to %d\n", sec);
        argc--;
        argv++;
   }

   if ( (cpid = fork())== 0) {
      execvp( argv[1],  &argv[1] );
      printf( "Could not start program %s", argv[1] );
      exit(2);
   }

   signal(SIGALRM, onTimeout);
   alarm( sec );

   if (wait(&status) == -1 || WIFSIGNALED(status) ) {
      printf( "%s terminated\n", argv[1]);
      exit(3);
   }
  
   if ( WIFEXITED(status) ) {
      printf("Program %s exited with status %d\n", argv[1], WEXITSTATUS(status)); 
      exit (WEXITSTATUS(status));
   }

} 


void onTimeout( int s ) {
   kill(cpid, SIGKILL);
}

