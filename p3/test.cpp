//by zygmunt ®
#include"Company.h"
#include<iostream>
#include<fstream>
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
		TVector<Company> CmpDB;
		TVector<Company>::iterator it = CmpDB.begin();

		bool done = false;
		while (!done)
		{
			Company temp;
			string tName;
			fstream fs;
			ToyShop tempShop;
			int selection = displayMenu();
			switch (selection) {
			case 1:
				cout << "Podaj nazwe firmy, ktora chcesz dodac:" << endl;
				cin >> temp;
				CmpDB.push_back(temp);
				break;
			case 2:
				cout << "Do ktorej firmy chcesz dodac sklep?" << endl;
				cin >> tName;
				it = CmpDB.begin();
				for (it; it != CmpDB.end(); it++)
				{
					if (tName == (*it).getName())
						break;
				}
				if (it != CmpDB.end())
					(*it).addStore();
				else cerr << "Brak firmy" << endl;
				break;
			case 3:
				cout << "Podaj nazwe firmy, ktorej dane chcesz wyswietlic:" << endl;
				cin >> tName;
				it = CmpDB.begin();
				for (it; it != CmpDB.end(); it++)
				{
					if (tName == (*it).getName())
						break;
				}
				if (it != CmpDB.end())
					cout << (*it);
				break;
			case 4:
				fs.open("dane.txt");
				if (!fs.is_open())
				{
					throw "File open error";
				}
				//cout << "OpenOK" << endl;
				while (!fs.eof())
				{
					fs >> temp;
					CmpDB.push_back(temp);
				}

				break;
			case 5:
				cout << "Podaj nazwe firmy, ktora chcesz usunac: " << endl;
				cin >> tName;
				for (int i = 0; i < CmpDB.GetSize(); i++)
					if (CmpDB[i].getName() == tName)
						CmpDB.erase(i);
				break;
			case 6:
				it = CmpDB.begin();
				while (it != CmpDB.end())
				{
					cout << (*it) << endl;
					it++;
				}
				break;
			case 7:
				cout << "Podaj adres sklepu, do ktorego chcesz dodac/usunac zabawki: " << endl;
				int temp_n;
				cin >> tName >> temp_n;
				it = CmpDB.begin();
				for (it; it != CmpDB.end(); it++)
				{
					for (int NumberOfStore = 0; NumberOfStore < (*it).GetVecSize(); NumberOfStore++)
					{
						tempShop = (*it).GetShopInfo(NumberOfStore);
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
	system("PAUSE");
	return 0;
}