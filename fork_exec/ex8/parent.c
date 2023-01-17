#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main( int argc,  char* argv[] )
{
    int cpid;
    int stat;
    int retval;

    if (cpid = fork()) /* this is the parent process */
    {
       printf("Created a child process\n");
       printf("Wait for the child process %d\n", cpid);
       retval = wait ( &stat );    
       if ( WIFEXITED(stat) ) {
          printf("Parent:  child pid=%d exited with status %d \n", cpid, WEXITSTATUS(stat) );
       } 
    }
    else    /* this is the child process */
    {
        printf("I am the newly created child process\n");
        printf("Now I will execute a different program\n");
        execl ("./child", "red", "white", "blue",  NULL);
     
        printf("Hello! Are you there?\n");
      
    }
}
