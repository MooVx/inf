main: main.o strtype.o
	g++ main.o strtype.o -o main
main.o: main.cpp
	g++ -c main.cpp 
strytype.o: strtype.cpp strtype.h
	g++ -c strtype.cpp
	 
clean:
	rm -f main.o strtype.o

.PHONY: clean