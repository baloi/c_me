CC = gcc
CFLAGS=-Wall -g 
CLEANFILES = core core.* *.core *.o temp.* *.out typescript* \
		*.lc *.lh *.bsdi *.sparc *.uw

PROGS = hello ex6 ex14 ex8 ex9

all: ${PROGS}

hello: hello.o
	${CC} ${CFLAGS} -o $@ hello.o

ex9: ex9.o
	${CC} ${CFLAGS} -o $@ ex9.o

ex6: ex6.o
	${CC} ${CFLAGS} -o $@ ex6.o

ex14: ex14.o
	${CC} ${CFLAGS} -o $@ ex14.o

ex8: ex8.o
	${CC} ${CFLAGS} -o $@ ex8.o



clean:
	rm -f ${PROGS} ${CLEANFILES} 
