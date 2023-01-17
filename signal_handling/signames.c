#include  <signal.h>
#include  <stdio.h>
#include  <string.h>


void main(int argc, char* argv[]) {

    char *sigName;
    int sig;

    for (sig=1; sig<32; sig++ ){
      sigName = strsignal(sig);
      printf( "Signal number %d name %s\n",  sig, sigName);
    }
}

