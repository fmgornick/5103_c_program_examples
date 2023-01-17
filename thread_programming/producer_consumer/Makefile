# @(#) Makefile 1.2 95/04/27 Richard.Marejka@Canada.Sun.COM
#
# Makefile for PRODCON program.
#

CFLAGS	= -v -D_REENTRANT
LIBS	= -lpthread

all	: prodcon

clean	:
	rm -f prodcon *.o  a.out core

prodcon :
	$(CC) $(CFLAGS) -o prodcon prodcon.c $(LIBS)  
