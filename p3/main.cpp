
#include "Vector.h"
#include "Iterator.h"
#include "Firma.h"


using namespace std;


int main(){
  	Vector<Firm> first;
		Vector<Firm>::iterator first_p = first.begin();

    Firm x;
    cin >> x;
    cout << x << endl ;
    x.AddPlace();

    cout << x << endl ;



}
