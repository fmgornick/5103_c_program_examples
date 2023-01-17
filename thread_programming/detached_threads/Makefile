# @(#) Makefile 1.2 95/04/27 Richard.Marejka@Canada.Sun.COM
#
# Makefile for detached thread example program.
#

CFLAGS	= -v -D_REENTRANT
LIBS	= -lpthread

all	: detached

clean	:
	rm -f detached *.o  a.out core

detached :
	$(CC) $(CFLAGS) -o detached detached.c $(LIBS)  
