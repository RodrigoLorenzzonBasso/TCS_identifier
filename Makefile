GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = identifier
GCC = gcc
SANITIZER = -fsanitize=address

INPUT = abc
INPUT2 = 1abc

SOURCES = identifier.c main.c
EXEC = exec

all: $(ALL)

identifier: $(SOURCES)
	cppcheck --error-exitcode=1 $^
	$(GCC) $(GCCFLAGS) -o $(EXEC) $^
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT2)
	$(GCC) $(GCCFLAGS) $(SANITIZER) -o $(EXEC) $^
	./$(EXEC) $(INPUT)
	./$(EXEC) $(INPUT2)
	

cov: identifier.c main.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o exec identifier.c main.c

clean:
	rm -fr exec *.o cov* *.dSYM *.gcda *.gcno *.gcov


