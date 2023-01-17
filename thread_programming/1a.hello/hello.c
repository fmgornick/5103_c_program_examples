/*
*  HELLO
* 
*  Copyright (C) 1995 by Sun Microsystems, Inc.
*  All rights reserved.
* 
*  This file is a product of SunSoft, Inc. and is provided for
*  unrestricted use provided that this legend is included on all
*  media and as a part of the software program in whole or part.
*  Users may copy, modify or distribute this file at will.
* 
*  THIS FILE IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING
*  THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR
*  PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.
* 
*  This file is provided with no support and without any obligation on the
*  part of SunSoft, Inc. to assist in its use, correction, modification or
*  enhancement.
* 
*  SUNSOFT AND SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT
*  TO THE INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS
*  FILE OR ANY PART THEREOF.
* 
*  IN NO EVENT WILL SUNSOFT OR SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY
*  LOST REVENUE OR PROFITS OR OTHER SPECIAL, INDIRECT AND CONSEQUENTIAL
*  DAMAGES, EVEN IF THEY HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
*  DAMAGES.
* 
*  SunSoft, Inc.
*  2550 Garcia Avenue
*  Mountain View, California  94043
*/

/* Include Files		*/

#include <stdio.h>

/* External References		*/

extern	int	hello( void );
extern	int	world( void );

/* main - Seven Sports For All	*/

int main( int argc, char *argv[] ) {
	hello();
	world();
	printf( "\n" );

	return( 0 );
}

/* hello - print the "hello" part.		*/

	int
hello( void ) {
	printf( "hello " );
	return( 0 );
}

/* world - print the "world" part.		*/

	int
world( void ) {
	printf( "world" );
	return( 0 );
}
