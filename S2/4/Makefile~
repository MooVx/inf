zad2: main.o tree.o
	gcc -lm -o zad2 main.o tree.o 


main.o: main.c

	gcc -Wall -c main.c -o main.o

tree.o: tree.c tree.h

	gcc -Wall -c tree.c 


.Phony: clean


clean:
	rm -f zad2 main.o tree.o