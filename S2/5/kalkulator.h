#ifndef KALKULATOR
#define KALKULATOR

#include <iostream>
#include <string>
#include <cstdlib>


#include "stos.h"

using namespace std;

class Kalkulator
{
public:
	void pracuj();
	void wczytaj();
	void przetwarzaj();
	void dodaj();
	void minus();
	void razy();
	int konwert(char znak);


	friend ostream & operator<<(ostream & out, const Kalkulator & prawy);


private:
	Stos m_stos;
	string m_dane;
};


#endif
