
#include "pracownik.h"
#include <iomanip>
using namespace std;

const int wciecie=12;

//konstruktory

Pay::Pay(string name, string surname, float pesel, float nip){
	_name = name;
	_surname = surname;
	_PESEL = pesel;
	_NIP = nip;
}

Etat::Etat(string name, string surname, float pesel, float nip, float salary)
	: Pay(name,surname,pesel,nip) {
		_salary = salary;		
}

Contract::Contract(string name, string surname, float pesel, float nip, int hours, float rate)
	: Pay(name,surname,pesel,nip) {
		_hours=hours;
		_rate=rate;
	
}

Dealer::Dealer(string name, string surname,float pesel, float nip, int sales, float percent)
	: Pay(name,surname,pesel,nip) {
		_sales=sales;
		_percent=percent;	
}

//funkcje print 

void Pay::print(){
	calc_wage();
	cout << setw(wciecie) << "Imie: " << _name << endl;
	cout << setw(wciecie) << "Nazwisko: " << _surname << endl;
	cout << setw(wciecie) << "Nip: " << _NIP << endl;
	cout << setw(wciecie) << "Pesel: " << _PESEL << endl;
}

void Etat::print(){
	Pay::print();
	cout << setw(wciecie) << "Pensja: " << _salary << endl << endl;
}

void Contract::print(){
	Pay::print();
	cout << setw(wciecie) << "Stawka: " << _rate << endl;
	cout << setw(wciecie) << "Godziny: " << _hours << endl;
	cout << setw(wciecie) << "Pensja: " << _salary << endl << endl;
	
}

void Dealer::print(){
	Pay::print();
	cout << setw(wciecie) << "Procent: " << _percent << endl;
	cout << setw(wciecie) << "Sprzedane: " << _sales << endl;
	cout << setw(wciecie) << "Pensja: " << _salary << endl << endl;
		
}

//funkcje calc_wage

void Contract::calc_wage(){
	if (_hours <= 40)
		_salary = static_cast<float>(4*_hours*_rate);
	else
		_salary = static_cast<float>(4*_hours*_rate*1.5);
}

void Dealer::calc_wage(){
	_salary = static_cast<float>(_sales*_percent);
}
