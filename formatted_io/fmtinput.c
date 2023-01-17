

#include <stdio.h>

int main ( int argc,  char *argv[] )  {
char city[32], zipcode[6];
int  p, total;

FILE *infp;

     total = 0;
     infp = fopen ( argv[1],  "r");
     while (  feof(infp)  == 0 ) {
        fscanf( infp, "%s %s %d\n", city, zipcode, &p );
        total  += p;
        printf( "City %-12s   Zip %-6s \n",  city, zipcode);
     }
     printf( "Total population %d \n", total );
}
