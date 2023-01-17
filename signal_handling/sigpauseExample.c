/*  This example shows use of sigpause to wait for a signal.  */


#include <signal.h>
#include <stdio.h>

void handler (int sig) {
   printf( "Received signal %d \n",  sig);
   signal( sig, handler );
}

int main ( int arg,  char* argv[] )  {
   int  i;
   sigset_t  signalSet;

   signal( SIGUSR1, handler );
   printf(" wait for signal\n");

   sigpause( SIGUSR1 );

  printf( "continue ... \n");

}

