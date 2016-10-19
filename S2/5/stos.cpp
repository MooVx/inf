#include "stos.h"



Stos::Stos(int rozmiar)
{
	m_zawartosc = new int[rozmiar];
	m_rozmiar = rozmiar;
	m_ilosc = 0;

};

void Stos::powieksz(int ile)
{
	int *p_zawartosc = new int[(m_rozmiar + ile)];
	m_rozmiar += ile;
	for (int i = 0; i < m_rozmiar; i++)
		p_zawartosc[i] = m_zawartosc[i];
	delete[] m_zawartosc;
	m_zawartosc = p_zawartosc;
}
void Stos::push(int max)
{
    if (isfull())
        powieksz();
	m_zawartosc[m_ilosc] = max;
	m_ilosc++;
}
void Stos::pop()
{
    if(isempty()==false)
        m_ilosc--;

}
int Stos::top()
{
	if (isempty() == 1)
	{
		cout << "Brak elementow na stosie!" << endl;
		return 0;
	}
	return m_zawartosc[m_ilosc-1];
}
bool Stos::isfull(){
    if (m_rozmiar==m_ilosc)
        return true;
    else
        return false;
}

bool Stos::isempty()
{
	if (m_rozmiar)
		return false;
	else
		return true;
}
int Stos::size()
{
	return m_ilosc;
}

void Stos::wypisz_stos()
{
	for (int i = 0; i < m_ilosc; i++) 
		cout << m_zawartosc[i] << " ";
	cout << endl;
}


Stos::~Stos()
{
	delete[] m_zawartosc;
	m_ilosc = 0;
	m_rozmiar = 0;
}

ostream & operator<<(ostream & out, const Stos & prawy)
{
	for (int i = 0; i < prawy.m_ilosc; i++)
		out << prawy.m_zawartosc[i] << " ";
	cout << endl;
	return out;
}
