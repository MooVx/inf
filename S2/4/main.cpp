
#include <iostream>
#include <new>

#include"c_vektor.h"
#include"c_matrix.h"

using namespace std;

void wyswietl();

int main()
{
	try
	{
		wyswietl();
	}
	catch (char const *error)
	{
		std::cerr << "Error !!! :" << error << endl;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "Blad alokacji pamieci: " << ba.what() << endl;
	}


}

void wyswietl()
{
    matrix x;
	cout << "wpisz macierz x :" << endl;
	cin >> x;
	matrix y;
	cout << "wpisz macierz y :" << endl;
	cin >> y;
	cout << "wpisane macierze :" << endl;
	cout << x << endl;
	cout << y << endl;
	matrix z;
	cout << "x+y=" << endl;
    z=x + y;
	cout << z << endl;
	cout << "x-y=" << endl;
	z = x - y;
	cout << z << endl;
	cout << "x*y=" << endl;
	z = x * y;
	cout << z << endl;
	cout << "x*15=" << endl;
	z = x * 15;
	cout << z << endl;
	cout << "15*x=" << endl;
	z = 15 * x;
	cout << z << endl;
	cout << "x==y ?" << endl;
	cout << (x == y) << endl;
	cout << "x!=y ?" << endl;
	cout << (x != y) << endl;
	cout << "x+=y" << endl;
	x += y;
	cout << x << endl;
}
