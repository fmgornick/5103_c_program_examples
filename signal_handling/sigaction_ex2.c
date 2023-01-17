
/* This is example 5.15 in the book. 		  				*/ 
/* This program causes a process to set a handler for SIGINT.*/


#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void catch_cntrl_c( int signo ) {
   printf( "Signal SIGINT was caught.\n");
}


void main (int argc,  char *argv[] ) {
struct sigaction act;
int i;


  act.sa_handler = catch_cntrl_c;
  sigemptyset( &act.sa_mask);
  act.sa_flags = 0;

  if (sigaction(SIGINT, &act, NULL) == -1) { 
       perror("Error in settting handler for SIGINT");
  } 

  for (i=0; i<15; i++ ){
      printf( "-\n");
      sleep( 1 );
  }
}
