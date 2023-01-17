#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
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
        execl ("./child",  "child", "red", "white", "blue",  NULL);
     
        printf("Hello! Are you there?\n");
      
    }
    wait( &stat );
}
