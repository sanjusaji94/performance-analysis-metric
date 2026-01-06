DEBUGFLAG=
CFLAGS_NOAUTO=$(DEBUGFLAG) -Wall -O3 -march=native -mtune=znver4 -ffast-math -fno-tree-vectorize
CFLAGS_AUTO=$(DEBUGFLAG) -Wall -O3 -march=native -mtune=znver4 -ffast-math 
CFLAGS_AUTO_S=$(DEBUGFLAG) -Wall -Os -march=native -mtune=znver4 -ffast-math 
CFLAGS=$(DEBUGFLAG) -Wall -O
CC=gcc
GCC=gcc
CLANG=clang
EXAMPLES=4
DISTFILES=Exercises4.txt Makefile \
	dp1-manual.c  dp1.c  dp1m.c \
	red1.c red1m.c \
	gen1.c gen1m.c \
	cond1.c cond1m.c \
	dp5.c dp5m.c \
	dp6.c dp6m.c

BINARIES=dp1-auto-clang dp1-auto-gcc dp1-noauto-clang dp1-noauto-gcc \
	dp1-manual-gcc dp1-manual-clang \
	dp2-auto-gcc dp2-noauto-gcc dp3-noauto-clang dp3-auto-clang \
	dp4-auto-gcc dp4-noauto-gcc dp4-manual-gcc \
	red1-auto-gcc red1-noauto-gcc red1-auto-clang red1-noauto-clang \
	gen1-auto-gcc gen1-noauto-gcc gen1-auto-clang gen1-noauto-clang \
	cond1-auto-gcc cond1-noauto-gcc cond1-auto-clang cond1-noauto-clang \
	dp5-auto-gcc dp5-noauto-gcc dp5-auto-clang dp5-noauto-clang \
	dp6-auto-gcc dp6-noauto-gcc dp6-auto-clang dp6-noauto-clang

all: $(BINARIES)

clean:
	rm -f *.o $(BINARIES)

dist:
	rm -rf $(EXAMPLES)
	mkdir $(EXAMPLES)
	cp $(DISTFILES) $(EXAMPLES)
	(cd $(EXAMPLES); make copies)
	zip -9r ../$(EXAMPLES).zip $(EXAMPLES)

copies:
	cp dp1.c dp2.c
	cp dp1m.c dp2m.c
	cp dp1.c dp3.c
	cp dp1m.c dp3m.c
	cp dp1.c dp4.c
	cp dp1m.c dp4m.c
	cp dp1-manual.c dp4-manual.c	

%-noauto-clang: %-noauto-clang.o %m.o
	$(CC) $^ -o $@

%-auto-clang: %-auto-clang.o %m.o
	$(CC) $^ -o $@

%-autos-clang: %-autos-clang.o %m.o
	$(CC) $^ -o $@

%-noauto-gcc: %-noauto-gcc.o %m.o
	$(CC) $^ -o $@

%-auto-gcc: %-auto-gcc.o %m.o
	$(CC) $^ -o $@

%-autos-gcc: %-autos-gcc.o %m.o
	$(CC) $^ -o $@

%-manual-gcc: %-manual-gcc.o %m.o
	$(CC) $^ -o $@

%-manual-clang: %-manual-clang.o %m.o
	$(CC) $^ -o $@

.PRECIOUS: %-noauto-clang.o %-auto-clang.o %-autos-clang.o %-noauto-gcc.o %-auto-gcc.o %-autos-gcc.o %-manual-gcc.o %-manual-clang.o %.o

%-noauto-clang.o: %.c
	$(CLANG) $(CFLAGS_NOAUTO) -c $< -o $@

%-auto-clang.o: %.c
	$(CLANG) $(CFLAGS_AUTO) -c $< -o $@

%-autos-clang.o: %.c
	$(CLANG) $(CFLAGS_AUTO_S) -c $< -o $@

%-noauto-gcc.o: %.c
	$(GCC) $(CFLAGS_NOAUTO) -c $< -o $@

%-auto-gcc.o: %.c
	$(GCC) $(CFLAGS_AUTO) -c $< -o $@

%-autos-gcc.o: %.c
	$(GCC) $(CFLAGS_AUTO_S) -c $< -o $@

%-manual-gcc.o: %-manual.c
	$(GCC) $(CFLAGS_AUTO) -c $< -o $@

%-manual-clang.o: %-manual.c
	$(CLANG) $(CFLAGS_AUTO) -c $< -o $@

