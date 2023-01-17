#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

char *getUserName ( uid_t uid ){
static char uidString[10];
struct passwd  *pswdpntr;
    if  ( (pswdpntr = getpwuid(uid)) == 0)  {
        sprintf( uidString, "%d", uid);
        return uidString;
    }
    else  return ( pswdpntr->pw_name);
}

char *getGroupName ( gid_t gid ){
static char gidString[10];
struct group  *grpntr;
    if  ( (grpntr = getgrgid(gid)) == 0)  {
        sprintf( gidString, "%d", gid);
        return gidString;
    }
    else  return ( grpntr->gr_name);
}

char *getAccessModeString ( const mode_t mode, char mstr[] ){
    sprintf(mstr, "----------");

    /* Get file typeifnormation bit */
    if ( S_ISLNK(mode) )   mstr[0] ='l';
    if ( S_ISDIR(mode) )   mstr[0] ='d';
    if ( S_ISCHR(mode) )   mstr[0] ='c';
    if ( S_ISBLK(mode) )   mstr[0] ='b';
 
    /* Get user access bits         */
    if ( S_IRUSR & mode )  mstr[1] = 'r';
    if ( S_IWUSR & mode )  mstr[2] = 'w';
    if ( (S_IXUSR & mode) && !(S_ISUID & mode) )  mstr[3] = 'x';
    if ( !(S_IXUSR & mode) && (S_ISUID & mode) )  mstr[3] = 'S';
    if ( (S_IXUSR & mode) && (S_ISUID & mode) )  mstr[3] = 's';

    /* Get group access bits         */
    if ( S_IRGRP & mode )  mstr[4] = 'r';
    if ( S_IWUSR & mode )  mstr[5] = 'w';
    if ( (S_IXGRP & mode) && !(S_ISGID & mode) )  mstr[6] = 'x';
    if ( !(S_IXGRP & mode) && (S_ISGID & mode) )  mstr[6] = 'S';
    if ( (S_IXGRP & mode) && (S_ISGID & mode) )  mstr[6] = 's';

    /* Get other access bits         */
    if ( S_IROTH & mode )  mstr[7] = 'r';
    if ( S_IWOTH & mode )  mstr[8] = 'w';
    if ( (S_IXOTH & mode) && !(S_ISVTX & mode) )  mstr[9] = 'x';
    if ( !(S_IXOTH & mode) && (S_ISVTX & mode) )  mstr[9] = 'S';
    if ( (S_IXOTH & mode) && (S_ISVTX & mode) )  mstr[9] = 's';
}

void print_statdata ( const char *filename,  const struct stat  *statdata) {
char accessmodes[11];
    getAccessModeString(statdata->st_mode, accessmodes); 
    printf( "Mode:       %s \n", accessmodes);
    printf( "Link count: %ld \n", statdata->st_nlink);
    printf( "UID:        %s \n", getUserName(statdata->st_uid) ) ;
    printf( "GID:        %s \n", getGroupName(statdata->st_gid) );
    printf( "Size:       %-8ld \n", statdata->st_size);
    printf( "Mod Time:   %.16s \n", ctime( &(statdata->st_mtime) ) );
    printf( "Name:       %s \n", filename);
}


void do_stat_and_print (const char* dirname,  const char *filename ) {
struct stat statdata;
char filepathname[256];

    sprintf(filepathname, "%s/%s", dirname, filename);
    printf("Relative pathname for the file is: %s\n", filepathname);
    if ( ! stat( filepathname, &statdata) )  {
       print_statdata( filename,  &statdata );        
    }  
    else {
       fprintf (stderr, "Getting stat for %s", filepathname);
       perror( "Error in statdata while getting stat");
    }
}


int main (int argc,  char* argv[] ) {
DIR   *dpntr;
struct  dirent   *dentry;
char *dirname;
   if ( argc > 2 ) {
      printf ("Usage:  %s  [directory-name]\n", argv[0] );
      exit( 1 );
   }
   if ( argc ==  2 ) {
      dpntr =  opendir ( argv[1] );
      dirname = argv[1];
   }
   else {
      dpntr =  opendir ( "." );
      dirname = ".";
   }
   if ( dpntr ==  0 ) {
      fprintf (stderr, "Error in opening directory:  %s\n", argv[1] );
      perror( "Could not open the directory");
      exit(2);
   }

   dentry =   readdir ( dpntr );
   
   while ( dentry != 0 )  {
      printf( "*******\n");
      printf("Calling print for file %s\n",  dentry->d_name);
      do_stat_and_print( dirname,  dentry->d_name );     
      dentry =   readdir ( dpntr );
   }
}

