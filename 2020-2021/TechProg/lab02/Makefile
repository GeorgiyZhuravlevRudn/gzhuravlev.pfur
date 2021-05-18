CC=g++
CFLAGS= -g -c
CompileFLAGS= -g -o

Matrix: main.o matrix_class.o
	$(CC) main.o matrix_class.o $(CompileFLAGS) Matrix

main.o: main.cpp matrix_header.h
	$(CC) $(CFLAGS) main.cpp

matrix_class.o: matrix_class.cpp matrix_header.h
	$(CC) $(CFLAGS) matrix_class.cpp

clean: 
	rm -rf *.o *.gch Matrix
