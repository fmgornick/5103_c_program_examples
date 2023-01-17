

#include <stdio.h>

int main ( int argc,  char *argv[] )  {
char city[32], zipcode[6];
FILE *infp;

     infp = fopen ( "addrs",  "r");
   

     while (  feof(infp)  == 0 ) {
        fscanf( infp, "%s %s", city, zipcode);
        printf( "City %s   Zip %s \n",  city, zipcode);
     }

}
