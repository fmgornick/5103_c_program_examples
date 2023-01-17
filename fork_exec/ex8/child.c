#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


/* Child process executes this code */

void main(int argc, char *argv[])
{
  printf("I am the child process after exec\n");
  printf("Child: I am  extiting with status 9\n");

  exit(9);
}
