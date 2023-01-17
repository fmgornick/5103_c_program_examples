

#include <stdio.h>

int main ( int argc,  char *argv[] )  {
float pi;
char msg[256] = "How are you?";
int i;

   pi = 3.141593;

   printf ("Value of pi is %10.4f\n", pi);
   printf ("Value of pi is %010.4f\n", pi);
   printf ("Value of pi is %-10.4f\n", pi);


   printf ("Message: %s\n", msg );
   printf ("Message: %20s\n", msg );
   printf ("Message: %-20s\n", msg );
   printf ("Message: %20.4s\n", msg );
   printf ("Message: %-20.4s\n", msg );

   i = 1234567890;

   printf ("Value of integer i: %5d\n", i );
   printf ("Value of integer i: %10d\n", i );
   printf ("Value of integer i: %15d\n", i );
   printf ("Value of integer i: %015d\n", i );
   printf ("Value of integer i: %-015d\n", i );
   printf ("Value of integer i: %+015d\n", i );

   i =  - 1234567890;
   printf ("Value of integer i: %10d\n", i );
   printf ("Value of integer i: %+10d\n", i );
   printf ("Value of integer i: %+15d\n", i );

}
