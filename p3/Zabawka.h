#ifndef TOY
#define TOY

#include<string>

using std::string;

class Toy{
public:
	string _name;
	float _price;
	int _amount;

	Toy(string name="brak", float price=0, int amount=0) 
		: _name(name), _price(price), _amount(amount) {}
	~Toy(){}
};

#endif