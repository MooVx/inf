
#include <iostream>
#include "Vector.h"
#include "Iterator.h"
#include "Firma.h"

using namespace std;


int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Toy Stores Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Dodaj firme" << endl;
	cout << "2) Dodaj sklep" << endl;
	cout << "3) Wyswietl dane firmy" << endl;
	cout << "4) Wczytaj dane z pliku" << endl;
	cout << "5) Usun firme" << endl;
	cout << "6) Wyswietl wszystkie firmy" << endl;
	cout << "7) Dodaj/usun zabawki do sklepu" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";
	cin >> selection;
	return selection;
}

int main()
{
	try{
		Vector<Firm> fm;
		Vector<Firm>::iterator it = fm.begin();

		bool done = false;
		while (!done)
		{
			Firm temp;
			string tName;
			fstream fs;
			Shop tempShop;
			int selection = displayMenu();
			switch (selection) {
			case 1:
				cout << "Podaj nazwe firmy, ktora chcesz dodac:" << endl;
				cin >> temp;
				fm.push_back(temp);
				break;
			case 2:
				cout << "Do ktorej firmy chcesz dodac sklep?" << endl;
				cin >> tName;
				it = fm.begin();
				for (it; it != fm.end(); it+1)
				{
					if (tName == (*it).Name())
						break;
				}
				if (it != fm.end())
					(*it).AddPlace();
				else cerr << "Brak firmy" << endl;
				break;
			case 3:
				cout << "Podaj nazwe firmy, ktorej dane chcesz wyswietlic:" << endl;
				cin >> tName;
				it = fm.begin();
				for (it; it != fm.end(); it+1)
				{
					if (tName == (*it).Name())
						break;
				}
				if (it != fm.end())
					cout << (*it);
				break;
			case 4:
				fs.open("dane1.txt");
				if (!fs.is_open())
				{
					throw "File open error";
				}
				//cout << "OpenOK" << endl;
				while (!fs.eof())
				{
					fs >> temp;
					fm.push_back(temp);
				}

				break;
			case 5:
				cout << "Podaj nazwe firmy, ktora chcesz usunac: " << endl;
				cin >> tName;
				for (int i = 0; i < fm.current_size(); i++)
					if (fm[i].Name() == tName)
						fm.erase(i);
				break;
			case 6:
				it = fm.begin();
				while (it != fm.end())
				{
					cout << (*it) << endl;
					++it;
				}
				break;
			case 7:
				cout << "Podaj adres sklepu, do ktorego chcesz dodac/usunac zabawki: " << endl;
				int temp_n;
				cin >> tName >> temp_n;
				it = fm.begin();
				for (it; it != fm.end(); ++it)
				{
					for (int NumberOfStore = 0; NumberOfStore < (*it).Number(); NumberOfStore++)
					{
						tempShop = (*it).PlaceInfo(NumberOfStore);
						if (tempShop.GetStreet() == tName && tempShop.GetStNumber() == temp_n)
							(*it).ModifyStore(NumberOfStore);
					}
				}
				break;
			case 0:
				done = true;
				break;
			default:
				cerr << "Unknown command." << endl;
				break;
			}
		}

	}
	catch (out_of_range& oor){
		cerr << oor.what() << endl;
	}
	catch (string er){
		cout << er;
	}

	return 0;
}