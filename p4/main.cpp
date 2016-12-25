#include <string>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "lista.h"
#include "puzzle.h"

using namespace std;

int main(){
    Puzzle p((char*)"Zmien na spacje",(char*)"Zmien_na_spacje");
    system("clear");
    p.display();
    while(!p.isSolved()){
        cout<<"To nie jest jeszcze rozwiązanie"<<endl;
        p.cmd();
        system("clear");
        p.display();
    }
    cout<<"Gratulacje puzzle rozwiązane"<<endl;

    return 0;
}