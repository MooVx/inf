#ifndef FIRM
#define FIRM

#include "Vector.h"
#include "Iterator.h"
#include "Sklep.h"
#include<iomanip>
#include <fstream> 

using namespace std;


class Firm{
private:
    string _name;
    Vector<Shop> _places;
    int _number;

public:

    Firm(string name="nie podano")
        :_name(name), _number(0){}
    ~Firm() {}
    void AddPlace();
    string Name(){
        return _name;
    }
    int Number(){
        return _number;
    }
    Shop& PlaceInfo(int pos){
        return _places[pos];
    }
    void ModPlace(int number);

    friend std::ostream& operator<<(std::ostream& out, const Firm& outF);
	friend std::istream& operator>>(std::istream& in, Firm& inF);
	friend std::ifstream& operator>>(std::ifstream& infile, Firm& inF);

};


#endif