
#include <signal.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
        if (argc != 3) {
          printf("SENDER PROCESS Usage: sender recieverPID integerValue\n");
          return(1);
        }

        union sigval value;
        int pid = atoi(argv[1]);

        value.sival_int = atoi(argv[2]);
        if(sigqueue(pid, SIGUSR1, value) == 0) {
                printf("signal USR1  sent with value  %d \n", value.sival_int);
        } else {
                perror("sigqueue failed:");
        }
        return 0;
}
