
/* This program causes a process to ignore SIGINT if it*/
/* is using the default handler for this signal.	  */


#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void main (int argc,  char *argv[] ) {
struct sigaction act;
int i;

  /* First obtain the current signal handler */
  if  (sigaction(SIGINT,  NULL, &act) == -1 ) {
      perror("Error in getting old handler for SIGINT");
  }
  else   
      if (act.sa_handler == SIG_DFL) {
         act.sa_handler = SIG_IGN;  /* new handler to be set is to ignore */
         if ( sigaction(SIGINT, &act, NULL) == -1 ) 
            perror("Error in settting ignore for SIGINT");
      } 

  for (i=0; i<15; i++ ){
      printf( "Cannot terminate this process by cntrl-C\n");
      sleep( 1 );
  }
}
