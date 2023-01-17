#include  <signal.h>
#include <stdio.h>
#include <unistd.h>


/* p is a pointer to a function that takes one integer argument */
void  ( * p )  ( int );

void myalarm2 ( int signum ) {
   printf( "Inside Signal handler 2 - received signal number %d\n", signum );
   /*  We will install the handler function pointed to by p */  
   signal( SIGALRM, *p);
}

void myalarm1 ( int signum ) {
   printf( "Inside Signal handler 1 - received signal number %d\n", signum );
   signal( SIGALRM,   myalarm1 );
   p =  signal( SIGALRM,   myalarm2 );
}

int  main () {
   int  i;
   signal( SIGALRM,   myalarm1 );

    for (i=0; i<10; i++ ){
       alarm(1);
       printf( "Sleep for 2 second\n");
       sleep( 2 );
    }

}


