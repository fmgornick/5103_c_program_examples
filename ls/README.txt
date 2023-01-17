
The programs given here are originally from Robins and Robins book on systems programming.

This folder contains examples of programs for reading and listing a directory.
These programs illustrate how a program for implementing the UNIX shell command "ls"
is written using the systems calls for reading the entry records in a directory file.
Six version of the "myls" program are given here, showing how the program successively
enahanced to give more detailed information for files in a given directory.

The programs given here are myls0.c, myls1.c, myls2.c, myls3.c, myls4.c, myls5.c and mylsFinal.c.
The last program in this list produces output very similar to "ls -l" command's output.
 
Run any of these programs as follows:
   myls0       // it will list files in the current directory
   myls0 directory-pathname  // it will list the files in the specified directory

myls0.c
   This is the lists only the name of the files

myls1.c
   This lists the inode-number and the name fo each file.

myls2.c
    It will list for each file:
    Mode:  as Octal number      
    Link count:  integer
    UID: integer number         
    GID: integer number      
    Size: integer number       
    Mod Time: integer number   
    Name: string       

myls3.c
    The same as above except that Mode is now printed as "rwx" permissions for user/group/others

myls4.c
   This program extends myls3.c to  resolves integer count of ticks for time to calendar date and time format using ctime function.

myls5.c
   This extends myls4.c to print symbolic names for UID and GID  using getUserName() and getGroupName() functions

myLsFinal
   It is myls5.c but prints all information for a file on one line.
   Its output looks very similar to "ls -l" command's output


   
