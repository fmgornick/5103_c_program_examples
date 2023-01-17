

The following examples are contained in this directory.  

prog1.c   This illustrates how cntrl-C signal is ignored by a process.

prog2.c   This shows use of alarm system call, and catching SIGALRM

prog3.c   This show how the current handler for a signal is saved and then it can be re-installed later.

sigpauseExample.c This shows use of sigpause to wait for a signal. (Do not use sigpause. Use sigsuspend.) 

sigsuspendExample.c  This shows how a process waits for any signal using sigsuspend.

sigactionExample.c  Illustrates use of sigaction system call to set handler for a signal.
sigaction_ex1.c  Illustrates obtaining the current handler for SIGINT, and if it is default then change to SIG_IGN (i.e. ignore).
sigaction_ex2.c  Show how to set a handler function using sigaction.

sigwaitExample.c  Use of sigwait to wait till any signal in a specified set becomes pending.

watchdog.c  This show how to run a program using watchdog, which would terminated the  program process if it does not complete in the specified time. 


Examples of realtime signals using sigqueue system call for sending a value are in the following programs:
   realtime.c  and  realtime2.c  are almost similar except the number of signals being sent
   realtime3.c   similar to the above two except for showing how to keep a set of signals is specifed to be masked while the handler rt_handler is executing
                 This is done by specifying the signals to be masked in the sigaction structure
   sigqueue-example   directory whihc has two programs sender.c and receiver.c 
	sender sends a value with SIGUSR1 signal to the receiver process

signames.c   This program uses strsignal() sysem all to obtain the description for a singal given its number






