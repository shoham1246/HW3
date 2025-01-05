CC=gcc
CLINK=$(CC)
CFLAGS=-g -Wall -std=c99
OBJS=main.o stack.o student.o
EXEC=prog.exe
//define RM?

//default rule
prog.exe: $(OBJS)
	$(CCLINK) $(OBJS) -o prog.exe
	
//other rules
main.o: main.c stack.h student.h

stack.o: stack.c stack.h

student.o: student.c student.h

//clean rule
clean:
	rm -rf *.o *.exe
