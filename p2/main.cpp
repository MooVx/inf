
#include "pracownik.h"

using namespace std;

const int cnt = 3;

int main()
{
    Pay * tab[cnt];
    tab[0] = new Dealer("Adam", "Adam", 123, 12121212121, 15000, 0.25);
    tab[1] = new Contract("Michal", "Michal", 555, 34343434343, 10, 120);
    tab[2] = new Etat("Pele", "Pele", 987, 56565656565, 3400);

    for (int i = 0; i < cnt; ++i) {
        tab[i]->calc_wage();
        tab[i]->print();
    }

    for (int i = 0; i < cnt; ++i) {
        delete tab[i];
    }
    
    return 0;

}
