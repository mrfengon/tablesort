CC = gcc

CCFLAGS = -g

OBJ = table.o main.o

.SUFFIXES: .c .o

main: $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o main

main.o: table.o
	$(CC) -c $(CCFLAGS) main.c

table.o: table.h table.c
	$(CC) -c $(CCFLAGS) table.h table.c

clean:
	@rm -f *.o *.gch main