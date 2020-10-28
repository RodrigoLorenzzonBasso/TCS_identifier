GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = identifier
GCC = gcc

SOURCES = identifier.c main.c
EXEC = exec

all: $(ALL)

identifier: $(SOURCES)
	cppcheck $^
	$(GCC) $(GCCFLAGS) -o $(EXEC) $^

cov: identifier.c main.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o exec identifier.c main.c

clean:
	rm -fr exec *.o cov* *.dSYM *.gcda *.gcno *.gcov


