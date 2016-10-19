#include <iostream>
#include <cstdio>
#include "stos.h"
#include "kalkulator.h"

using namespace std;


int main()
{
    try
    {
        int exit=1;
        while(exit){
            Kalkulator kalkulator;
            kalkulator.pracuj();
            cout << kalkulator << endl;
            cout << " kontynuowac ? 0/1" << endl;
            cin >> exit;
            getchar();
        };
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "Blad alokacji pamieci: " << ba.what() << endl;
    }

};
