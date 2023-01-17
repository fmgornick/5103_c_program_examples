#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main( int argc,  char* argv[])
{

    if (fork()) /* this is the parent process */
    {
       printf("Created a child process\n");
    }
    else    /* this is the child process */
    {
        printf("I am the newly created child process\n");
        printf("Now I will execute a different program\n");

        { char* newargs[4];
          newargs[0] = "red";
          newargs[1] = "white";
          newargs[2] = "blue";
          newargs[3] = 0;
 
          alarm(15);  //set alarm singal after 15 seconds   

          if ( execv ("./child", newargs) )
             printf ("exec returned non-zero value\n");
     
          printf("Hello! Are you there?\n");
      
        }
      }
}
