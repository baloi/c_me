CC = g++-4.9
CFLAGS=-Wall -std=c++11# 
CLEANFILES = core core.* *.core *.o temp.* *.out typescript* \
		*.lc *.lh *.bsdi *.sparc *.uw

PROGS = test_adb 

all: ${PROGS}

test_adb: test_adb.o
	${CC} ${CFLAGS} -o $@ test_adb.o

clean:
	rm -f ${PROGS} ${CLEANFILES} 
