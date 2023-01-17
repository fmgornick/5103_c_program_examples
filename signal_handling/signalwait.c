
#include  <signal.h>
#include  <unistd.h>
#include  <stdio.h>


void myalarm ( int signum ) {
   printf( "Inside Signal handler - received signal number %d\n", signum );
   signal( SIGALRM,   myalarm );   
   /* It will need to be reset on Solaris, as above, but no needed on Linux. */
}


void main () {
   int  i;
   int  status;
   sigset_t sgnset;

   signal( SIGALRM,   myalarm );

   for (i=0; i<10; i++ ){
       alarm(10);   /* set alarm for 1 second, SIGALRM will be delivered after 10 second  */
       printf( "Sleep for 60  second\n");
       sigemptyset( &sgnset);
       sigaddset(&sgnset, SIGALRM); 
       printf("Waiting for alarm signal...\n");
       status = sigwait(&sgnset); 
       /*  Handler is NOT executed when Alarm signal is delivered */
       printf("Received signal %d\n", status);
   }

}

