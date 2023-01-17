/*  This program will catch and ingore interrupt signal SIGINT     */
/*  After the loop is executed, it will reset the default action   */
/*  for SIGINT, which is to exit the program execution.            */

#include  <signal.h>
#include  <stdio.h>
#include  <unistd.h>

void main () {
   int  i;

    signal( SIGINT,  SIG_IGN);

    for (i=0; i<15; i++ ){
       printf( "Cannot terminate this process by cntrl-C\n");
       sleep( 1 );
    }

    signal( SIGINT, SIG_DFL );
    printf( "Now type cntrl-C\n");
    sleep( 10 );
} 
