#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main( int argc,  char* argv[] )
{
    pid_t child_id;
    int stat;

    if ((child_id = fork())) /* this is the parent process */
    {
       printf("PARENT: Created a child process\n");
       printf("PARENT:   will wait till my child with pid %d finishes\n", child_id);
       child_id = wait(&stat);
       printf("PARENT: My child with pid %d is finishd \n", child_id );

       if (WIFEXITED(stat) ) {
           printf("PARENT:  child exit status %d \n", WEXITSTATUS(stat) );
       }
    }
    else    /* this is the child process */
    {
        printf("CHILD: I am the newly created child process\n");
        printf("CHILD: Now I will execute a different program\n");
        execl ("./child", "child",  "red", "white", "blue",  NULL);
        printf("Hello! Are you there?\n");
      
    }
}
