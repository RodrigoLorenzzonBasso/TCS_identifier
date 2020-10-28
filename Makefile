GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = identifier
GCC = gcc
SANITIZER = -fsanitize=address
GCOVFLAGS = -fprofile-arcs -ftest-coverage

INPUT = abc
INPUT2 = 1abc

SOURCES = identifier.c main.c
EXEC = exec

UNITY_ROOT = Unity
UNITY_SRC=$(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  test/TestIdentifier.c \
  test/TestIdentifierRunner.c \
  test/all_tests.c \
  identifier.c
UNITY_INC_DIRS = -Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
UNITY_TARGET = all_tests

all: $(ALL)

identifier: $(SOURCES)
	cppcheck --error-exitcode=1 $^
	$(GCC) $(GCCFLAGS) -o $(EXEC) $^
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT2)
	$(GCC) $(GCCFLAGS) $(SANITIZER) -o $(EXEC) $^
	./$(EXEC) $(INPUT)
	./$(EXEC) $(INPUT2)
	
tests:
	$(GCC) $(GCCFLAGS) $(UNITY_INC_DIRS) $(UNITY_SRC) -o $(UNITY_TARGET)
	- ./$(UNITY_TARGET) -v
	
gcovtests:
	$(GCC) $(GCCFLAGS) $(GCOVFLAGS) $(UNITY_INC_DIRS) $(UNITY_SRC) -o $(UNITY_TARGET)
	- ./$(UNITY_TARGET) -v

cov: identifier.c main.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o exec $(SOURCES)

clean:
	rm -fr $(EXEC) $(UNITY_TARGET) *.o cov* *.dSYM *.gcda *.gcno *.gcov


