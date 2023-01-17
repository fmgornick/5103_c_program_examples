#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void main( int argc, char* argv[])
{
    pid_t child_id;
    int stat_loc;
    int fd;
    char* buffer;
    ssize_t bytes_read;
    int BUFFER_SIZE = 32;

    /* open the file "input" */

    buffer = (char *)malloc (BUFFER_SIZE * sizeof (int));
    if ((fd = open("./input", O_RDONLY)) == -1) {
    	printf("Could not open the file\n");
        exit(1);
    }
    
    if ((child_id = fork()) == -1) {
	   printf("Could not fork()\n");
	   exit (-1);
    }

    if (child_id == 0) {
	/* this is the child process */
        printf("CHILD: I am the newly created child process\n");
	
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE-1)) != 0)
	{
	    if (bytes_read <  BUFFER_SIZE)
		   buffer[bytes_read] = '\0';
	    printf("Child:: %s\n", buffer);
	    sleep(1);
	}
	printf("Child is done\n");
      
    } else {
	
	/* this is the parent process */

	while ((bytes_read = read(fd, buffer,BUFFER_SIZE-1 )) != 0)
	{
	    if (bytes_read <  BUFFER_SIZE)
		    buffer[bytes_read] = '\0';
	    printf("Parent:: %s\n", buffer);
	    sleep(1);
	}

	printf("Parent is done\n");
       
    }
    
}
