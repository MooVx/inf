#ifndef MATRIX
#define MATRIX

#include <iostream>
#include "c_vektor.h"

class matrix
{
public:
	matrix(int roz_vec=2, int row=2);
	matrix(const matrix& zrodlo);
	~matrix();

	friend istream& operator>>(istream& in,matrix &prawy);
	friend ostream& operator<<(ostream& out,const matrix& prawy);

	matrix& operator=(const matrix& prawy);
	matrix operator+(const matrix& prawy);
	matrix operator-(const matrix& prawy);
	matrix operator*(const matrix& prawy);
	matrix operator*(const int&skalar);
	friend matrix operator*(const int& skalar, matrix & prawy);
	
	matrix& operator+=(const matrix& prawy);
	matrix& operator-=(const matrix& prawy);
	matrix& operator*=(const matrix& prawy);

	bool operator==(const matrix &prawy);
	bool operator!=(const matrix &prawy);
	
private:
    vektor** m_vecs;
	int m_row;
	int m_roz_vec;
};


#endif
