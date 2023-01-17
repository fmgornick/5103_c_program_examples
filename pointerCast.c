/*
 * This example show how to cast a memory address to 
 *  pointer of a specific type such as a struct or array  
*/

#include <stdio.h>
#include <stdlib.h>

  typedef struct Person {
     char* name;
     char* phone;
     int age;
     int height; 
  } PersonType;

int main(int ac, char* av[]){

  PersonType person;

  printf( "Sizes of PersonType %u \n", sizeof(PersonType));

  char* mempntr = malloc( sizeof(PersonType) );

  if(mempntr==0) {
   exit(1);
  }

  PersonType* prsnPntr;

/* Now we will cast the mempntr to a pointer to a struct of PersonType  */

  prsnPntr = (PersonType *) mempntr;
  
  prsnPntr->name = "Mickey Mouse";
  prsnPntr->phone = "12345";
  prsnPntr->age= 2;
  prsnPntr->height= 6;
   
  printf("Person: name %s phone %s age %u  height %u\n", prsnPntr->name, prsnPntr->phone, prsnPntr->age, prsnPntr->height);

/* Now we will cast the same mempntr to an integer array address */
  int i;
  int* A = (int *) mempntr;
  for (i = 0; i<6; i++) {
    A[i] =  i;
  }

  for (i = 0; i<6; i++) {
    printf(" A[%u] is %u \n", i, A[i] ); 
  }
   
}

