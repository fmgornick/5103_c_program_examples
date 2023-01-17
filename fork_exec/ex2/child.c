#include <stdio.h>
#include <sys/types.h>


/* Child process executes this code */

void main(int argc, char *argv[])
{
  printf("I am the child process after exec\n");
  printf("Number of args passed to me %d\n", argc);

 { int i;
   for (i=0; i<argc; i++) {
     printf("Argument %d is %s \n", i, argv[i] );
    }
 }
}
