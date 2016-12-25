fine: main
	rm -f *.o

main: main.o puzzle.o
	g++ -lm -o main main.o puzzle.o

main.o: lista.h 
	g++ -Wall -c main.cpp -o main.o

puzzle.o: puzzle.cpp puzzle.h
	g++ -Wall -c puzzle.cpp -o puzzle.o

.Phony: clean fine main

clean:
	rm -f main *.o