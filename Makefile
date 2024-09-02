WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFLAGS = -DTEST_ADDFILE -DTEST_WRITESUM # -DDEBUG

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

# diff -w means do not care about space

a1: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o a1

.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

testall: test1 test2 test3

test1: a1
	./a1 inputs/input1 output1
	diff -w output1 expected/expected1

test2: a1
	./a1 inputs/input2 output2
	diff -w output2 expected/expected2

test3: a1
	./a1 inputs/input3 output3
	diff -w output3 expected/expected3

clean: # remove all machine generated files
	rm -f a1 *.o output* *~