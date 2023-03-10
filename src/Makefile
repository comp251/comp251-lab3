# make DEFINE=-DDEBUG <target>
DEFINE=
DEBUGGER=-g
CFLAGS=$(DEBUGGER) $(DEFINE) -Wall -Werror
CC=gcc
OUTPUT=

# make SAN=asan
SAN=
ifeq ($(SAN),asan)
	CLFLAGS+=-fsanitize=address
endif

TESTS=
TESTS+=tests/fnv64_test
TESTS+=tests/map_test

APPS=
APPS+=idriver
APPS+=word_count
APPS+=stress_test

all: $(TESTS) $(APPS)

test: $(TESTS)
	$(foreach TEST,$(TESTS), ./$(TEST);)

test-leaks: $(TESTS)
	$(foreach TEST,$(TESTS), valgrind --leak-check=full ./$(TEST);)

tests/map_test: tests/map_test.o tests/test_utils.o map.o tests/airport_codes.o
	$(CC) $(CFLAGS) -o $@ $^

tests/fnv64_test: tests/fnv64_test.o tests/test_utils.o fnv64.h
	$(CC) $(CFLAGS) -o $@ $^

idriver: interactive_driver.o map.o
	$(CC) $(DEBUGGER) -o $@ $^

word_count: word_count.o map.o fnv64.h rand1.h
	$(CC) $(DEBUGGER) -o $@ $^

stress_test: stress_test.o map.o fnv64.h rand1.h
	$(CC) $(DEBUGGER) -o $@ $^

run_word_count: word_count
ifeq ($(OUTPUT),file)
	valgrind --leak-check=full ./word_count -f books/alice-in-wonderland.txt -s 20 -d -r > valgrind-wc-out.txt 2>&1 
else
	valgrind --leak-check=full ./word_count -f books/alice-in-wonderland.txt -s 20 -d -r 
endif

run_stress_test: stress_test 
ifeq ($(OUTPUT),file)
	valgrind --leak-check=full ./stress_test -r 50 -i 4 -s 256 -k 2048 -m 4 > valgrind-st-out.txt 2>&1 
else
	valgrind --leak-check=full ./stress_test -r 50 -i 4 -s 256 -k 2048 -m 4
endif

clean:
	rm -f *.o tests/*.o $(TESTS) $(APPS) tests/fnv64_test
