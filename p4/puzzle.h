#ifndef PUZZLE
#define PUZZLE
#include<cstring>
#include <cstdlib>

#include "lista.h"

using namespace std;

class Puzzle{
private:
    List<char> _solution; // rozwiązanie  puzzli
    List<char> _puzzle; // Aktualna  konfiguracja liter  
public:
    Puzzle( char answ[], char init[] ); // Konstruuje puzzle
    void display(); 
    bool isSolved();
    void cmd();
};

#endif

