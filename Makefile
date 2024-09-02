WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

# diff -w means do not care about space

a1: $(OBJS) 
	$(GCC) $(OBJS) -o a1

.c.o: 
	$(GCC) -c $*.c

testmemory: a1
	$(VAL) ./a1 90

run: a1
	./a1

clean: # remove all machine generated files
	rm -f a1 *.o output* *~