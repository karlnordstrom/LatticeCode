INCDIR=include
SRCDIR=src
LIBDIR=lib
CC=gcc -std=c99

all: run.exe

${LIBDIR}/metropolis.o:	${INCDIR}/metropolis.h ${SRCDIR}/metropolis.c
	${CC} -o ${LIBDIR}/metropolis.o -c ${SRCDIR}/metropolis.c -I${INCDIR}

run.exe: ${LIBDIR}/metropolis.o ${SRCDIR}/run.c
	${CC} -o run.exe ${SRCDIR}/run.c ${LIBDIR}/metropolis.o -I${INCDIR}

clean:
	rm ${LIBDIR}/metropolis.o
	rm run.exe
