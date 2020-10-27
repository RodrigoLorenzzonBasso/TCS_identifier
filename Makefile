GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = identifier
GCC = gcc

all: $(ALL)

identifier: identifier.c main.c
	$(GCC) $(GCCFLAGS) -o exec identifier.c main.c

cov: identifier.c main.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o exec identifier.c main.c

clean:
	rm -fr exec *.o cov* *.dSYM *.gcda *.gcno *.gcov

test: all
	bash test
