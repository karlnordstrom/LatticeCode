INCDIR=include
SRCDIR=src
LIBDIR=lib
CC=gcc -std=c99

all: run.exe

${LIBDIR}/metropolis.o:	${INCDIR}/metropolis.h ${SRCDIR}/metropolis.c
	${CC} -o ${LIBDIR}/metropolis.o -c ${SRCDIR}/metropolis.c -I${INCDIR} -lm

${LIBDIR}/observable.o:	${INCDIR}/observable.h ${SRCDIR}/observable.c
	${CC} -o ${LIBDIR}/observable.o -c ${SRCDIR}/observable.c -I${INCDIR} -lm

run.exe: ${LIBDIR}/metropolis.o ${LIBDIR}/observable.o ${SRCDIR}/run.c
	${CC} -o run.exe ${SRCDIR}/run.c ${LIBDIR}/metropolis.o ${LIBDIR}/observable.o -I${INCDIR} -lm

clean:
	rm ${LIBDIR}/metropolis.o
	rm run.exe
