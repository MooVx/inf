#ifndef VEKTOR
#define VEKTOR

#include <iostream>
#include <iomanip>

using namespace std;

class vektor
{
public:
	vektor(int wymiar = 2);
	vektor(const vektor &zrodlo);
	~vektor();

	friend ostream& operator<< (ostream& out, const vektor& prawy);
	friend istream& operator>> (istream& in, vektor& v_in);
	
	vektor& operator=(const vektor& prawy);
	vektor operator+(const vektor& prawy)const;
	vektor operator-(const vektor& prawy)const;
	vektor operator*(const int &skalar);
	vektor operator*(const vektor& prawy);
	friend vektor operator*(const int &skalar, vektor &prawy);

	const int& operator[](const int& pos);

	vektor& operator+=(const vektor& prawy);
	vektor& operator-=(const vektor& prawy);
	vektor& operator*=(const vektor& prawy);

	bool operator==(const vektor &prawy);
	bool operator!=(const vektor &prawy);

private:
	int m_wym;
	int* m_tab;
};

#endif
