CC=gcc
CFLAGS=-O -Wall -fwrapv -march=rocketlake
DISTFILES=*.c *.h Makefile Exercises2.txt
EXAMPLES=2

perf: e2work1
	perf stat -e cycles:u -e instructions:u e2work1 array 1
	perf stat -e cycles:u -e instructions:u e2work1 array 2
	perf stat -e cycles:u -e instructions:u e2work1 list 1
	perf stat -e cycles:u -e instructions:u e2work1 list 2

e2work1: e2main1.o e2work1.o

dist:
	rm -rf $(EXAMPLES)
	mkdir $(EXAMPLES)
	cp $(DISTFILES) $(EXAMPLES)
	zip -9r ../$(EXAMPLES).zip $(EXAMPLES)

clean:
	rm *.o e2work1
