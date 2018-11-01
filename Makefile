CC=cc
CFLAGS=-Wall
LFLAGS=

OBJS=vnnoff_test.o vnnoff.o

%.o: %.c %.h
	$(CC) -c $<
	
%.o: %.c
	$(CC) -c $<
	
vnnoff.a: vnnoff.o
	ar rcs $@ $<
	
vnnoff_test: $(OBJS)
	$(CC) -o $@ $(OBJS)
	
.PHONY: debug
debug: vnnoff_test
	valgrind $<
	
.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf vnnoff_test
