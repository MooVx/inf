#include "kalkulator.h"



void Kalkulator::pracuj()
{
	wczytaj();
	przetwarzaj();
}

void Kalkulator::wczytaj()
{
	cout << "Wprowadz wyrazenie: ";
	getline(cin, m_dane);
	m_dane += ' ';
}

void Kalkulator::przetwarzaj()
{

	char **ciag;
		ciag = new char*[m_dane.size()];
        for (unsigned int i = 0; i < m_dane.size(); i++)
			ciag[i] = new char[m_dane.size()];
		int j = 0;
		int k = 0;
    for (unsigned int i = 0; i < m_dane.size(); i++)
	{

		if (m_dane[i] == ' ')
		{
			ciag[j][k] ='\0';
			j++;
			k = 0;
		}
		else
		{
			ciag[j][k] = m_dane[i];
            k++;
			ciag[j + 1][0] = '\0';
		}
	}

	for (char i = 0; ciag[i][0] != '\0'; i++)
	{
        if (ciag[i][0] == '+')
			dodaj();
		else if (ciag[i][0] == '-')
			minus();
		else if (ciag[i][0] == '*')
			razy();
		else
		{
			m_stos.push(atoi(ciag[i]));
		}

	}


    for (unsigned int i = 0; i < m_dane.size(); i++)
		delete[]ciag[i];
	delete[]ciag;
}


void Kalkulator::dodaj()
{
	int x = m_stos.top();
	m_stos.pop();
	int y = m_stos.top();
	m_stos.pop();
	m_stos.push(x + y);
}

void Kalkulator::minus()
{
	int x = m_stos.top();
	m_stos.pop();
	int y = m_stos.top();
	m_stos.pop();
	m_stos.push(x - y);
}

void Kalkulator::razy()
{
	int x = m_stos.top();
	m_stos.pop();
	int y = m_stos.top();
	m_stos.pop();
	m_stos.push(x * y);
}

int Kalkulator::konwert(char znak)
{
	if (znak <'0' || znak >'9')
	{
		return NULL;
	}
	else return (znak - '0');
}




ostream & operator<<(ostream & out, const Kalkulator & prawy)
{
	out << "Wynik to: " << endl;
	out << (prawy.m_stos);
	
	return out;
}
