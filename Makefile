INCDIR=include
SRCDIR=src
LIBDIR=lib
CC=gcc -std=c99 -O3

all: run.exe

${LIBDIR}/metropolis.o:	${INCDIR}/metropolis.h ${SRCDIR}/metropolis.c
	${CC} -o ${LIBDIR}/metropolis.o -c ${SRCDIR}/metropolis.c -I${INCDIR} -lm

${LIBDIR}/observable.o:	${INCDIR}/observable.h ${SRCDIR}/observable.c
	${CC} -o ${LIBDIR}/observable.o -c ${SRCDIR}/observable.c -I${INCDIR} -lm

${LIBDIR}/error.o:	${INCDIR}/error.h ${SRCDIR}/error.c
	${CC} -o ${LIBDIR}/error.o -c ${SRCDIR}/error.c -I${INCDIR} -lm

${LIBDIR}/mt64.o:	${INCDIR}/mt64.h ${SRCDIR}/mt19937-64.c
	${CC} -o ${LIBDIR}/mt64.o -c ${SRCDIR}/mt19937-64.c -I${INCDIR} -lm

run.exe: ${LIBDIR}/metropolis.o ${LIBDIR}/observable.o ${LIBDIR}/error.o ${LIBDIR}/mt64.o ${SRCDIR}/run.c
	${CC} -o run.exe ${SRCDIR}/run.c ${LIBDIR}/metropolis.o ${LIBDIR}/observable.o ${LIBDIR}/error.o ${LIBDIR}/mt64.o -I${INCDIR} -lm

clean:
	rm ${LIBDIR}/metropolis.o
	rm ${LIBDIR}/observable.o
	rm ${LIBDIR}/error.o
	rm ${LIBDIR}/mt64.o
	rm run.exe
