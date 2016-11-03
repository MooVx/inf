fine: main
	rm -f main.o firm.o shop.o

main: main.o firm.o shop.o
	g++ -lm -o main main.o firm.o shop.o

main.o: main.cpp Vector.h Iterator.h Firma.h
	g++ -Wall -c main.cpp -o main.o

firm.o: Firma.cpp Firma.h
	g++ -Wall -c Firma.cpp -o firm.o

shop.o: Sklep.cpp Sklep.h
	g++ -Wall -c Sklep.cpp -o shop.o


.Phony: clean fine main

clean:
	rm -f main main.o firm.o shop.o