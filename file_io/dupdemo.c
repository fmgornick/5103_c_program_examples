/*                          Introduction to Operating Systems         
			    CSCI 4061 
This program reads in data from an input source specified by the user. and output
written by the program to standard-out is redorected to the specified output file.
USAGE : dupdemo inputfile outputfile
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
  /*  Declarations begin */
  int inputStream = -1;
  int outputStream = -1;
  char buffer[BUFSIZE];
  int amt = BUFSIZE;  /* bytes transferred in current operation */
  int stat; 
  /*  Declarations end */
  
  /* Command line checking */
  if(argc < 3)
    {
      perror("Missing Parameters: \n Usage : dupdemo <input> <output>");
      exit(1);
    }
  /* Open the input file for reading */
  if ((inputStream = open(argv[1], O_RDONLY)) == -1)
    {
      perror("Unsuccessful open of the input stream");
      exit(2);
    }

  /* Open the output file for writing */ 
  if ((outputStream = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR)) == -1)
    {
      perror("Unsuccessful open of the output stream");
      exit(3);
    }

  /* Duplicate the Standard Out to outputStream */
  
  if (dup2(outputStream, STDOUT_FILENO) == -1)
    {
      perror("Could not redirect to STDOUT");
      exit(4);
    }
  
  while (amt == BUFSIZE) 
    {
      amt  = read(inputStream, buffer, BUFSIZE);
      stat = write(1, buffer, amt);
    }
  
  close(inputStream);
  close(outputStream);
  return 0;
}






