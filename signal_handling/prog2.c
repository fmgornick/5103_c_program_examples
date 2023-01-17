/* This program will setup a function named "myalarm"  to catch SIGALRM  */
/* and then it makes the "alarm" system call in the loop body to cause   */
/* SIGALRM to be delivered to the process afer 1 second.                 */
/* The process sleeps for 60  seconds, but the signal SIGALARM is        */
/* delivered to it after 1 second and it is resumed immediately.         */
/* It will first excecute the signal handler "myalarm" and then          */
/* it continues with the program execution.								 */



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
   int  sleepDeprived;
   signal( SIGALRM,   myalarm );

    for (i=0; i<10; i++ ){
       alarm(5);   /* set alarm for 5 seconds, SIGALRM will be delivered after 5 seconds  */
       printf( "Sleep for 60  second\n");
       sleepDeprived = sleep( 60 );

       printf("I did not get %d seconds of sleep which I really neeed to rest well\n", sleepDeprived); 
       
    }

}

