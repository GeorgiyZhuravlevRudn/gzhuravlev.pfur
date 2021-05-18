CC=g++
CFLAGS= -g -c
CompileFLAGS= -g -o

Doubly_Linked_Lists: main.o class.o
	$(CC) main.o class.o $(CompileFLAGS) Doubly_Linked_Lists

main.o: main.cpp class.cpp
	$(CC) $(CFLAGS) class.cpp main.cpp

class.o: class.cpp
	$(CC) $(CFLAGS) class.cpp

clean: 
	rm -rf *.o Doubly_Linked_Lists
