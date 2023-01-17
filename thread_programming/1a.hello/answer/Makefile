# @(#) Makefile 1.2 95/04/27 Richard.Marejka@Canada.Sun.COM
#
# Makefile for HELLO program.
#

CFLAGS	= -v -D_REENTRANT
LIBS	= -lpthread

all	: hello

clean	:
	rm -f hello *.o *% a.out core

hello	:
	$(CC) $(CFLAGS) -o hello hello.c $(LIBS)
