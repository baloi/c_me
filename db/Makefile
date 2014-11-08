CC = g++
CFLAGS=-Wall -c -std=c++11 # 
CLEANFILES = core core.* *.core *.o temp.* *.out typescript* \
		*.lc *.lh *.bsdi *.sparc *.uw

PROGS = adb 

all: ${PROGS}

adb: adb.o
	${CC} ${CFLAGS} -o $@ adb.o

clean:
	rm -f ${PROGS} ${CLEANFILES} 
