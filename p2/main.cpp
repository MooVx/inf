
#include "pracownik.h"

using namespace std;

const int cnt = 4;

int main()
{
    Pay * tab[cnt];
    tab[0] = new Dealer("Adam", "Adam", 123, 212121, 150234, 0.259);
    tab[1] = new Contract("Michal", "Michal", 555, 344343, 80, 100);
    tab[2] = new Etat("Pele", "Pele", 987, 56665, 34300);
    tab[3] = new Dealer("fdgd", "fdgdf", 6765, 745765, 10000,0.6);

    for (int i = 0; i < cnt; ++i) {
        tab[i]->print();
    }

    for (int i = 0; i < cnt; ++i) {
        delete tab[i];
    }
    
    return 0;

}
