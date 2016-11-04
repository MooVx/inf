
#include <iomanip>
#include "Sklep.h"

using namespace std;

void Shop::addToy(){
    string name;
    float price;
    int number;
    cout << "Jaka zabawke chcesz dodac?" << endl;
    cin >> name;
    cout << "Ile sztuk ?" << endl;
    cin >> number;
    cout << "W jakiej cenie?" << endl;
    cin >> price;
    _Toys.push_back(Toy(name,price,number));

}

void Shop::deleteToy(string toyName)
{
	for (int i = 0; i < _Toys.current_size(); i++){
		if (_Toys[i]._name == toyName){
			_Toys.erase((i));
        }
    }
}

ostream& operator<<(ostream& out, const Shop& outShop)
{
	out << "ul." << setw(17) << outShop._st_name 
    << setw(10)  << outShop._st_number << endl << endl;
	out << setw(20) <<"Nazwa zabawki:" << setw(10) << "Cena:"<< setw(10) << "Sztuk:" << endl;
	for (int i = 0; i < outShop._Toys.current_size(); i++){
		out << setw(20) << outShop._Toys[i]._name;
		out << setw(10) << outShop._Toys[i]._price;
		out << setw(10) << outShop._Toys[i]._amount << endl;
    }
	return out;
}

istream& operator>>(std::istream& in, Shop& inShop){
    string name;
    float price;
    int number;
    in >> name >> number >> price;
    inShop._Toys.push_back(Toy(name,price,number));
    
    return in;
}