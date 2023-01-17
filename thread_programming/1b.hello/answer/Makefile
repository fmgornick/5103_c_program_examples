# @(#) Makefile 1.2 95/04/27 Richard.Marejka@Canada.Sun.COM
#
# Makefile for HELLO program.
#

CFLAGS	= -v -D_REENTRANT
LIBS	= -lpthread

all	: hello hello-s

clean	:
	rm -f hello hello-s *.o *% a.out core

hello	:
	$(CC) $(CFLAGS) -o hello hello.c $(LIBS)

hello-s	:
	$(CC) $(CFLAGS) -DSOLARIS -o hello-s hello.c $(LIBS) -lthread
