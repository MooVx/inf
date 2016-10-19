zad4: main.o c_vektor.o c_matrix.o
	g++ -lm -o zad4 main.o c_vektor.o c_matrix.o

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o

c_vektor.o:  c_vektor.cpp c_vektor.h
	g++ -Wall -c c_vektor.cpp 

c_matrix.o:  c_matrix.cpp c_matrix.h
	g++ -Wall -c c_matrix.cpp 

.Phony: clean


clean:
	rm -f zad4 main.o c_vektor.o c_matrix.o
