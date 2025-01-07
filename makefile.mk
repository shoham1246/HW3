CC=gcc
CCLINK= gcc -o
CFLAGS=-g -Wall -std=c99
OBJS=main.o stack.o student.o
EXEC= prog.exe
RM=rm -rf *.o *.exe

$(EXEC): $(OBJS)
	$(CCLINK) $(EXEC) $(OBJS)
	

stack.o: stack.c stack.h common.h
	$(CC) $(CFLAGS) -c stack.c

student.o: student.c student.h common.h
	$(CC) $(CFLAGS) -c student.c

main.o: main.c student.h stack.h common.h
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM)
