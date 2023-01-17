#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* This program demonstrates the use of sigaction system call.

   Runf this program in background:
     sigactionExample &
   It wioll pritn its process Id.
  

   Use kill command to send signal SIGUSR1 to this process.
     kill -USR1 12345.
 */

void myhandler(int sig) {
  printf("sigactionExample process received signal number  %d\n", sig);
}

void main() {

  printf( "Process-id of sigactionExample process %d\n", getpid());

  /* struct to hold the old sigaction object */
  struct sigaction old;

  /* struct to hold the new sigaction object */
  struct sigaction new;

  /* initialize the new sigaction object
     which will be used to install the handler
     function called "myhandler" */
  new.sa_handler = myhandler;

  /* mask indicates signals to be masked while
     executing myhandler. 
  */
  sigset_t mask;
  /* mask set to empty set */
  sigemptyset(&mask);
  new.sa_mask = mask;
  new.sa_flags = 0;

  /* call the sigaction system call to set the new handler */
  sigaction(SIGUSR1, &new, &old);
  
  while(1) {
   sleep(1);
  }
}
