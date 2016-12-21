fine: main
	rm -f main.o 

main: main.o 
	g++ -lm -o main main.o 

main.o: main.cpp 
	g++ -Wall -c main.cpp -o main.o -std=c++11


.Phony: clean fine main

clean:
	rm -f main *.o