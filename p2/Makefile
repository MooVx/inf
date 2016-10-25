fine: main
	rm -f main.o pracownik.o 

main: main.o pracownik.o 
	g++ -lm -o main main.o pracownik.o

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o

pracownik.o:  pracownik.cpp pracownik.h
	g++ -Wall -c pracownik.cpp -o pracownik.o

.Phony: clean fine main

clean:
	rm -f main main.o pracownik.o 
