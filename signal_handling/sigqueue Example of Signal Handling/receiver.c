
#include <signal.h>
#include <stdio.h>
 

void handler (int signum, siginfo_t *info, void *arg)
{
       int value  = info->si_value.sival_int;
       printf( "RECEIVER PROCESS:: Received Signal: %d, value: %d\n", signum, value );
}

int main()
{
        struct sigaction action;

        // print pid of the process executing this program
        
        printf("\nRECEIVER PROCESS:: PID = %d\n", getpid() );

        action.sa_flags = SA_SIGINFO;
        action.sa_sigaction = &handler;

        if (sigaction(SIGUSR1, &action, NULL) == -1) {
                perror("sigaction failed");
                return 0;
        }

        printf("RECEIVER PROCESS:: waiting for USR1 signal\n");

        sigset_t signalSet;
        sigemptyset ( &signalSet );
        sigsuspend ( &signalSet );  /* No signals are masked while waiting */

        return 0;
}
