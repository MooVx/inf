#ifndef SHOP
#define SHOP

#include<iostream>
#include<fstream>
#include "Vector.h"
#include "Zabawka.h"

using namespace std;


class Shop{
private:
    string _st_name;
	int _st_number;
    Vector<Toy> _Toys;


public:
    Shop(string st_name = "nie podano", int st_number = 0)
		: _st_name(st_name),_st_number(st_number) {}
	void addToy();
	string getStName(){
		return _st_name;
	}
	int getStNumber(){
		return  _st_number;
	}
	void deleteToy(string toyName);
	~Shop() {}

	friend std::ostream& operator<<(std::ostream& out, const Shop& outShop);
	friend std::istream& operator>>(std::istream& in, Shop& inShop);
	friend std::ifstream& operator>>(std::ifstream& in, Shop& inF);
	friend std::ofstream& operator<<(std::ofstream& out, const Shop& outShop);
};


#endif