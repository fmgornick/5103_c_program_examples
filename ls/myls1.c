#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


int main (int argc,  char* argv[] ) {
DIR   *dpntr;
struct  dirent   *dentry;

   if ( argc > 2 ) {
      printf ("Usage:  %s  [directory-name]\n", argv[0] );
      exit( 1 );
   }

   if ( argc ==  2 ) 
      dpntr =  opendir ( argv[1] );
   else
      dpntr =  opendir ( "." );

   if ( dpntr ==  0 ) {
      fprintf (stderr, "Error in opening directory:  %s\n", argv[1] );
      perror( "Could not opne directory");
      exit(2);
   }

   dentry =   readdir ( dpntr );
   
   while ( dentry != 0 )  {
      printf( "%6d   %s\n",  dentry->d_ino, dentry->d_name );
      dentry =   readdir ( dpntr );
   }
}

