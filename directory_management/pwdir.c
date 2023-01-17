
#include <unistd.h>

void main (int argc, char* argv[]) {
long maxpath;
char *cwdNamePntr; 

  if  ( (maxpath = pathconf("/", _PC_PATH_MAX) ) == -1 ) {
      perror( "Error while finding max pathlength");
     exit(1);
  }
  
  if ((cwdNamePntr = (char * ) malloc(maxpath+1) ) == NULL ) {
     perror( "Error in allcating char array  for pathname");
    exit(1);
   }

  if (getcwd(cwdNamePntr, maxpath) == NULL) {
     perror ( "Error in reading current working directory");   
     exit(1);
  }
 
  printf( "Current working directory: %s \n", cwdNamePntr);

}
