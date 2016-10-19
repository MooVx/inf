zad5: main.o kalkulator.o stos.o
	g++ -lm -o zad5 main.o kalkulator.o stos.o

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o

kalkulator.o:  kalkulator.cpp kalkulator.h
	g++ -Wall -c kalkulator.cpp 

stos.o:  stos.cpp stos.h
	g++ -Wall -c stos.cpp 

.Phony: clean


clean:
	rm -f zad4 main.o kalkulator.o stos.o
