CC = g++
CFLAGS = -g -c
CompFlags= -g -o

calculate: Calculator.o main.o operation.o
	$(CC) Calculator.o main.o operation.o $(CompFlags) calculate

Calculator.o: Calculator.cpp CalcHeader.h
	$(CC) $(CFLAGS) Calculator.cpp

main.o: main.cpp CalcHeader.h
	$(CC) $(CFLAGS) main.cpp

operation.o: operation.cpp CalcHeader.h
	$(CC) $(CFLAGS) operation.cpp

clean:
	rm -rf *.o calculate
