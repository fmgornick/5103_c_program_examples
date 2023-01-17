#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void  main (int argc, char * argv[])  {
char buffer[ ] =  "Hello,  I just created 16 null characters in this file."; 
mode_t   perms;
int		 fdesc;

    perms   = 0740;

    if  ( argc !=2 ) {
        printf( "Incorrect use: Usage: %s  file-name\n",  argv[0] );
        exit(1);
    } 

 
    if  ( (fdesc = open (argv[1], (O_WRONLY | O_CREAT),  perms)) == -1 ) {
        perror ( "Error in creating the output file:");
        exit (2);
    }
   
     if  ( lseek(fdesc, 16,  SEEK_END) == -1 ) {
         perror ("Error executing lseek") ;  
         exit(3);
     }
    
     if ( write (fdesc, buffer, strlen(buffer) ) != strlen(buffer) ) { 
         perror ("Error in writing" );
         exit(4);
    } 

    close(fdesc);
}
