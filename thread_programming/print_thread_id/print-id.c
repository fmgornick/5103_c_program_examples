#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>



pthread_t ntid;

void printids(const char *s)
{
    pid_t      pid;
    pthread_t  tid;

    pid = getpid() ;
    tid = pthread_self() ;
    printf("%s pid %u tid %u \n", (char *)s, (unsigned int) pid, (unsigned int) tid ) ;
}

void * thr_fn(void *arg)
{
    printids("new thread: ") ;
    return((void *) 0) ;
}

int main(void)
{
    int     err;
    void *status;
    err = pthread_create(&ntid, NULL, thr_fn, NULL) ;
    if (err != 0)
        printf("can' t create thread: \n")  ;
    printids("main thread: ") ;
//    sleep(1) ;
    pthread_join(ntid, &status);
    exit(0) ;
}
