This directory contains example programs that will help you understand how
to use system calls such as fork, different flavours of exec and wait. 

Brief explanation for each example follows.

Example 1:
----------
parent.c:
---------
- Parent creates the child using fork 
- Child executes a program called "child" passing it 3 arguments
  red, white, blue. Child uses execl to execute the different program
- Parent waits for the child to finish

child.c:
--------
- prints the number of arguments passed and name of each argument

Example 2:
----------
parent.c:
---------
- almost same as example 1. 
- Child uses execv to execute the different program
- Difference between execl and execv is that in execv you can 
  create an array of arguments and pass in the array to execv
- Note that the parent does not wait for the child to finish

child.c:
--------
- same as example 1

Example 3:
----------
executeCommand.c:
-----------------
- parent forks a child and child executes a command
- Note that this is slighlty different than earlier examples
  Here the child is executing one of the shell commands. Thus by 
  using one of the program from the exec family programs you can 
  make a program to execute some different program (any kind of 
  executable: shell command or any other executable)

Example 4:
----------
parent.c:
---------
- parent creates the child and uses system call wait to wait
  for the child to finish
- wait returns the process id (PID) of the child to the parent

child.c:
--------
- same as example 1

Example 5:
----------
parent.c:
---------
- opens the file with name "input"
- creates a child
- across the fork child and parent will share the file descriptor
- both child and parent read from the same descriptor and the output
  gets interleaved by the outputs of the two

Example 6:
----------
parent.c:
---------
- creates the child 
- keeps on looping while checking the status of the child
- uses the WNOHANG option of waitpid. This allows the parent to 
  keep looping while checking whether a child has exited or not

Example 7:
----------
pipeline.c:
-----------
- parent executes one command
- The output file descriptor of the parent is changed 
  from standard output to a pipe input descriptor
- Child changes its standard input descriptor to read
  from the pipe output descriptor

Example 8:
----------
parent.c:
---------
- parent creates child and waits for the child to finish
- If the child exits returning a status code, the parent prints 
  the child PID and the exit status

child.c:
--------
- child sends back the exit status 9


Example: exec-signal
------------------

This shows that pendign signals are retained on exec and delivered to the new process image.
