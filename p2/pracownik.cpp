
#include "pracownik.h"
#include <iomanip>
using namespace std;

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
		calc_wage();		
}

Dealer::Dealer(string name, string surname,float pesel, float nip, int sales, float percent)
	: Pay(name,surname,pesel,nip) {
		_sales=sales;
		_percent=percent;
		calc_wage();		
}

//funkcje print 

void Pay::print(){
	cout << setw(10) << "Imie: " << _name << endl;
	cout << setw(10) << "Nazwisko: " << _surname << endl;
	cout << setw(10) << "Nip: " << _NIP << endl;
	cout << setw(10) << "Pesel: " << _PESEL << endl;
}

void Etat::print(){
	Pay::print();
	cout << setw(10) << "Pensja: " << _salary << endl << endl;
}

void Contract::print(){
	Pay::print();
	cout << setw(10) << "Stawka: " << _rate << endl;
	cout << setw(10) << "Godziny: " << _hours << endl;
	cout << setw(10) << "Pensja: " << _salary << endl << endl;
	
}

void Dealer::print(){
	Pay::print();
	cout << setw(10) << "Procent: " << _percent << endl;
	cout << setw(10) << "Sprzedarze: " << _sales << endl;
	cout << setw(10) << "Pensja: " << _salary << endl << endl;
		
}

//funkcje calc_wage

void Contract::calc_wage(){
	if (_hours <= 40)
		_salary = 4*_hours*_rate;
	else
		_salary = 4*_hours*_rate*1.5;
}

void Dealer::calc_wage(){
	_salary = _sales*_percent;
}
