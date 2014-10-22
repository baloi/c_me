CC = gcc
CFLAGS=-Wall -g 
CLEANFILES = core core.* *.core *.o temp.* *.out typescript* \
		*.lc *.lh *.bsdi *.sparc *.uw

PROGS = userin char_types printing max_min

all: ${PROGS}


max_min: max_min.o
	${CC} ${CFLAGS} -o $@ max_min.o

userin: userin.o
	${CC} ${CFLAGS} -o $@ userin.o

char_types: char_types.o
	${CC} ${CFLAGS} -o $@ char_types.o

printing: printing.o
	${CC} ${CFLAGS} -o $@ printing.o



clean:
	rm -f ${PROGS} ${CLEANFILES} 
