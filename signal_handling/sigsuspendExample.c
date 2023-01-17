
/*  This example shows use of sigsuspend to wait for a signal. */

#include <signal.h>
#include <stdio.h>

void handler (int sig) {
   printf( "Received signal %d \n",  sig);
}

int main ( int arg,  char* argv[] )  {
   int  i;
   sigset_t  signalSet;

   signal( SIGUSR1, handler );
   signal( SIGUSR2, handler );
   signal( SIGINT, handler );
   printf(" wait for signal\n");


   sigemptyset ( &signalSet );

   printf( "My process id: %d \n", getpid() );
   printf( "Waiting for a signal ....\n");

   sigsuspend ( &signalSet );  /* No signals are masked while waiting */

  printf( "continue ... \n");

}

