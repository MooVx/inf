#include "c_vektor.h"


//konstruktory
vektor::vektor(int wymiar)
{
	m_wym = wymiar;
	m_tab = new int[wymiar];
	for (int i = 0; i < m_wym; i++)
	{
		m_tab[i] = 0;
	};
}
vektor::vektor(const vektor &zrodlo) 
{
	m_tab = new int[zrodlo.m_wym];
	m_wym = zrodlo.m_wym;
	for (int i = 0; i < m_wym; i++)
	{
		zrodlo.m_tab[i] = 0;
	};
}


ostream & operator<<(ostream & out, const vektor & prawy)
{
	out << "[";
	for (int i = 0; i < prawy.m_wym; i++)
	{
		out << setw(3) << prawy.m_tab[i];
	}
	out << "  ]" << endl;
	return out;
}

istream & operator>>(istream & in, vektor & prawy)
{
	for (int i = 0; i < prawy.m_wym; i++)
	{
		in >> prawy.m_tab[i];
	}
	return in;
}


vektor& vektor::operator=(const vektor& prawy) 
{
	if (this == &prawy) return *this;
	if (m_wym == prawy.m_wym)
		for (int i = 0; i < m_wym; i++) {
			m_tab[i] = prawy.m_tab[i];
		}
	else
	{
		delete[] m_tab;
		m_tab = new int[prawy.m_wym];
		m_wym = prawy.m_wym;
		for (int i = 0; i < m_wym; i++) {
			m_tab[i] = prawy.m_tab[i];
		}
	}
	return *this;
}

vektor vektor::operator+(const vektor& prawy)const
{
	vektor sum(m_wym);
	if (m_wym == prawy.m_wym)
	{
		
		for (int i = 0; i < m_wym; i++)
		{
			sum.m_tab[i]= m_tab[i] + prawy.m_tab[i];
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return sum;
}

vektor vektor::operator-(const vektor& prawy)const
{
	vektor sum(m_wym);
	if (m_wym == prawy.m_wym)
	{

		for (int i = 0; i < m_wym; i++)
		{
			sum.m_tab[i] = m_tab[i] - prawy.m_tab[i];
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return sum;
}

vektor vektor::operator*(const int &skalar)
{
	vektor r(m_wym);
	for (int i = 0; i < m_wym; i++)
	{
		r.m_tab[i] = m_tab[i]*skalar;
	}
	return r;
}

vektor vektor::operator*(const vektor & prawy)
{
	vektor sum(m_wym);
	if (m_wym == prawy.m_wym)
	{

		for (int i = 0; i < m_wym; i++)
		{
			sum.m_tab[i] = m_tab[i] * prawy.m_tab[i];
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return sum;
}

vektor operator*(const int &skalar, vektor& prawy) 
{
	return prawy*skalar;
}


const int& vektor::operator[](const int& pos)
{
	return m_tab[pos - 1];
}


vektor& vektor::operator+=(const vektor& prawy) 
{
	if (m_wym == prawy.m_wym)
	{

		for (int i = 0; i < m_wym; i++)
		{
			m_tab[i] = m_tab[i] + prawy.m_tab[i];
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return *this;
}

vektor & vektor::operator-=(const vektor & prawy)
{
	if (m_wym == prawy.m_wym)
	{

		for (int i = 0; i < m_wym; i++)
		{
			m_tab[i] = m_tab[i] - prawy.m_tab[i];
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return *this;
}

vektor & vektor::operator*=(const vektor & prawy)
{
	if (m_wym == prawy.m_wym)
	{

		for (int i = 0; i < m_wym; i++)
		{
			m_tab[i] = m_tab[i] * prawy.m_tab[i];
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return *this;
}

bool vektor::operator==(const vektor &prawy)
{
	if (m_wym == prawy.m_wym)
	{
		for (int i = 0; i < m_wym; i++)
		{
			if(m_tab[i] != prawy.m_tab[i])return false;
		}
		return true;
	}
		return false;
}

bool vektor::operator!=(const vektor &prawy)
{
	return !((*this) == prawy);
}

//destruktor
vektor::~vektor()
{
	delete[] m_tab;
}