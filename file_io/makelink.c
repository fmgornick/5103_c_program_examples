/*
       Introduction to Operating Systems CSCI 4061
This program demonstrates how to create a symbolic link to a file. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int status;

    if(argc < 3)       /*If the user does not enter any directory name*/
    {
	    printf("Usage: %s ExistingFilePath NewLinkFilePath \n" ,  argv[0] );
        exit(1);
    }

    status = symlink( argv[1], argv[2] );

    if ( status == -1) {
       perror("Failed to create a symbolic link");  
       exit(2);
    }
}
