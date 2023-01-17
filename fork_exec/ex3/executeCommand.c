#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main( int argc, char* argv[] )
{
    int status, pid;

    if (fork()) /* this is the parent process */
    {
       printf("Created a child process\n");
       pid = wait(&status);
       
    }
    else    /* this is the child process */
    {
        printf("I am the newly created child process\n");
        printf("Now I will execute a different program\n");

        { char* newargs[4];
          newargs[0] = "ls";
          newargs[1] = "-l";
          newargs[2] = 0;
    
          if ( execvp ("ls", newargs) )
             printf ("exec returned non-zero value\n");
     
          printf("Hello! Are you there?\n");
      
        }
      }
}
