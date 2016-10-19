#ifndef STOS
#define STOS

#include<iostream>

using namespace std;

class Stos
{
public:
	Stos(int rozmiar =10);
	void powieksz(int ile = 10);
	void push(int max);
	void pop();
	int top();
	bool isempty();
    bool isfull();
	int size();
	void wypisz_stos();
	~Stos();

	friend ostream & operator<<(ostream & out, const Stos & prawy);

private:
	int *m_zawartosc;
	int m_rozmiar;
	int m_ilosc;
};

#endif
