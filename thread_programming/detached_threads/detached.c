/* This program creates two threads and one of them is detached.Each thread
  prints its thread id . The main thread (main()) joins the non detached 
  thread. Here joining makes main() thread to wait for the other thread to
  finish . Detached thread is not joined. Detached thread start executing
  independent of other threads...it reamins part of the same process */
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

/* thread function executed by the two created threads*/
void * printID (void *arg)
{ int i,id;
  id=(int)pthread_self();/*pthread_self() returns the id of calling thread*/ 
  printf("Thread ID = %d\n",id);
}

int main( int argc,char* argv[])
{
  pthread_t thread1,thread2;/* thread variables */
  pthread_attr_t attr; /*attribute object*/
  int n;

 if(n= pthread_attr_init(&attr)){ /*initalize the attribute object */
   fprintf(stderr,"pthread_init_err: %s\n",strerror(n));
   exit(1);
   }

  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
   /* set the attribute object to detached */

  if(n=pthread_create(&thread1,&attr, printID, NULL)){
    fprintf(stderr,"pthread_create :%s\n",strerror(n));
    exit(1); } /* create thread on ewith detached attribute and rthred function
               thread() with no argument*/


  if(n=pthread_create(&thread2,NULL, printID, NULL)){
    fprintf(stderr,"pthread_create :%s\n",strerror(n));
     exit(1);} /*create thread with default attributes */

  if(n=pthread_join(thread2,NULL)){ /*join second thread to main thread*/ 
   fprintf(stderr,"pthread_join:%s\n",strerror(n));
   exit(1);
   }
}


