
#include "c_matrix.h"

matrix::matrix(int roz_vec, int row)
{
    m_vecs = new vektor*[row];
	m_row = row;
	m_roz_vec = roz_vec;
	for (int i = 0; i < row; i++)
        (m_vecs[i]) = new vektor(roz_vec);
}

matrix::matrix(const matrix & zrodlo)
{
    m_vecs = new vektor*[zrodlo.m_row];
	m_row = zrodlo.m_row;
	m_roz_vec = zrodlo.m_roz_vec;
	for (int i = 0; i < zrodlo.m_row; i++)
        m_vecs[i] =zrodlo.m_vecs[i];
}

matrix::~matrix()
{

    for (int i = 0; i < m_row; i++)
           delete  *(m_vecs + i);
    delete[] m_vecs;
}

matrix & matrix::operator=(const matrix & prawy)
{
	if (this == &prawy) return *this;
    for (int i = 0; i < m_row; i++)
           delete  *(m_vecs + i);
    delete[] m_vecs;
    m_vecs = new vektor*[prawy.m_row];
	m_row = prawy.m_row;
	m_roz_vec = prawy.m_roz_vec;
    for (int i = 0; i < m_row; i++)
        m_vecs[i] = new vektor(m_roz_vec);
    for (int i = 0; i < m_row; i++)
         *(*(m_vecs +i)) = *(*(prawy.m_vecs +i));
	return *this;
}

matrix matrix::operator+(const matrix & prawy)
{
	matrix sum(m_roz_vec,m_row);
	if ((m_row == prawy.m_row)&&(m_roz_vec == prawy.m_roz_vec))
	{
		for (int i = 0; i < m_row; i++)
		{
            *(*(sum.m_vecs +i)) = *(*(m_vecs +i)) + *(*(prawy.m_vecs +i));
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return sum;
}

matrix matrix::operator-(const matrix & prawy)
{
	matrix sum(m_roz_vec, m_row);
	if ((m_row == prawy.m_row) && (m_roz_vec == prawy.m_roz_vec))
	{
		for (int i = 0; i < m_row; i++)
		{
          *(*(sum.m_vecs +i)) = *(*(m_vecs +i)) - *(*(prawy.m_vecs +i));
		}
    }
	else {
		throw "niedozwolone dzalanie";
	}
	return sum;
}

matrix matrix::operator*(const matrix & prawy)
{
	matrix sum(m_roz_vec, m_row);
	if ((m_row == prawy.m_row) && (m_roz_vec == prawy.m_roz_vec))
	{
		for (int i = 0; i < m_row; i++)
		{
          *(*(sum.m_vecs +i)) = *(*(m_vecs +i)) * *(*(prawy.m_vecs +i));
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return sum;
}

matrix matrix::operator*(const int & skalar)
{
	matrix sum(m_roz_vec, m_row);
	for (int i = 0; i < m_row; i++)
	{
          *(*(sum.m_vecs +i)) = *(*(m_vecs +i))  * skalar;
	}
		
	return sum;
}

matrix & matrix::operator+=(const matrix & prawy)
{
	if ((m_row == prawy.m_row) && (m_roz_vec == prawy.m_roz_vec))
	{
		for (int i = 0; i < m_row; i++)
		{
           *(*(m_vecs +i)) = *(*(m_vecs +i)) + *(*(prawy.m_vecs +i));
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return *this;
}
matrix & matrix::operator-=(const matrix & prawy)
{
	if ((m_row == prawy.m_row) && (m_roz_vec == prawy.m_roz_vec))
	{
		for (int i = 0; i < m_row; i++)
		{
          *(*(m_vecs +i)) = *(*(m_vecs +i)) - *(*(prawy.m_vecs +i));
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return *this;
}
matrix & matrix::operator*=(const matrix & prawy)
{
	if ((m_row == prawy.m_row) && (m_roz_vec == prawy.m_roz_vec))
	{
		for (int i = 0; i < m_row; i++)
		{
          *(*(m_vecs +i)) = *(*(m_vecs +i)) * *(*(prawy.m_vecs +i));
		}
	}
	else {
		throw "niedozwolone dzalanie";
	}
	return *this;
}
bool matrix::operator==(const matrix & prawy)
{
	if ((m_row == prawy.m_row) && (m_roz_vec == prawy.m_roz_vec))
	{
		for (int i = 0; i < m_row; i++)
		{
            if (          *(*(m_vecs +i)) == *(*(prawy.m_vecs +i)))return false;
		}
		return true;
	}
	return false;
}

bool matrix::operator!=(const matrix & prawy)
{
		return !((*this) == prawy);
}

istream & operator>>(istream & in, matrix & prawy)
{
	for (int i = 0; i < prawy.m_row; i++)
        in >> *(*(prawy.m_vecs +i));
	return in;
}

ostream & operator<<(ostream & out, const matrix & prawy)
{
	for (int i = 0; i < prawy.m_row; i++)
        out << *(*(prawy.m_vecs +i));
	return out;
}

matrix operator*(const int & skalar, matrix & prawy)
{
	return prawy* skalar;
}
