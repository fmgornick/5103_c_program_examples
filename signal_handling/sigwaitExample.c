#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* This program demonstrates the use of sigwait system call.
   Compile and run this program in a terminal.
     cc -o sigwaitExample sigwaitExample.c
     ./sigwaitExample

   Then in another terminal
   find out the process id of this process using ps command
     ps -ef | grep sigwaitExample
  
   Suppose the process id is 12345.
   Use kill command to send signal SIGUSR1 to this process.
     kill -USR1 12345.

   The signal will be handled through the sigwait system call
   instead of the signal handler function. 
   You would see the output of the printf statement after the
   sigwait call-
     returned value:0 and sig: 10
 */

void myhandler(int sig) {
  printf("received %d\n", sig);
}

void main() {

   printf( "My process id: %d \n", getpid() );

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
   /* sigset struct object to contain the signals
      to wait for */
   sigset_t wait_set;
   sigemptyset(&wait_set);

   /* add SIGUSR1 to the set of signal we are going to wait for */
   sigaddset(&wait_set, SIGUSR1);

   int sig; 
   /* sigwait system call will block untill the SIGUSR1 is received */
//   int num = sigwait(&wait_set, &sig);
//   printf("returned value:%d and sig:%d\n", num, sig);
  }
}
