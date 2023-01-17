#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void  main( int argc,  char* argv[])
{
int stat;

    if (fork()) /* this is the parent process */
    {
       printf("Created a child process\n");
    }
    else    /* this is the child process */
    {
        printf("I am the newly created child process\n");
        printf("Now I will execute a different program\n");

        { char* newargs[4];
          newargs[0] = "child";
          newargs[1] = "red";
          newargs[2] = "white";
          newargs[3] = "blue";
          newargs[4] = 0;
    
          if ( execv ("./child", newargs) )
             printf ("exec returned non-zero value\n");
     
          printf("Hello! Are you there?\n");
      
        }
      }

      wait(&stat);
}
