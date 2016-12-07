#include <string>
#include <iostream>
#include <cstdlib>
#include "Vector.h"
#include "Iterator.h"
#include "Firma.h"

using namespace std;


int displayMenu(){
	int selection;
	cout <<endl<< "---> ";
	cin >> selection;
  	system("clear");
  	printf("\033[%d;%dH", 1, 1);
	cout << endl;
	cout << "Toy Stores Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Dodaj firme" << endl;
	cout << "2) Dodaj sklep" << endl;
	cout << "3) Wyswietl firmy" << endl;
	cout << "4) dodaj firme z pliku" << endl;
	cout << "5) Usun firme" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	return selection;
}

int main()
{

	Vector<Firm> fm;
	Vector<Firm>::iterator it = fm.begin();
	bool done = false;
	system("clear");
	printf("\033[%d;%dH", 1, 1);
	cout << endl;
	cout << "Toy Stores Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Dodaj firme" << endl;
	cout << "2) Dodaj sklep" << endl;
	cout << "3) Wyswietl firmy" << endl;
	cout << "4) dodaj firme z pliku" << endl;
	cout << "5) Usun firme" << endl;
	cout << "0) Quit" << endl;
	while (!done)
	{
		Firm temp;
		string tName;
		ifstream fs;
		Shop tempShop;
		int selection = displayMenu();
		bool w=0;
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
			// for (int i=0; i<fm.current_size();i++){
			// 	if (tName ==fm[i].Name())
			// 		fm[i].AddPlace();
			// 	else 
			// 		cerr << "Brak firmy" << endl;
			// }
			
			for (it = fm.begin(); it != fm.end();it++){
				if (tName ==(*it).Name()){
					(*it).AddPlace();
					w=1;
				}
			}
			if(!w){
				cerr << "Brak firmy" << endl;
			}

			break;
		case 3:
			for (int i=0; i<fm.current_size();i++){				
				cout<<fm[i]<< endl;
			}

			break;
		case 4:
			fs.open("dane1.txt");
			fs >> temp;
			fm.push_back(temp);
			fs.close();
			cout<< "wczytano. "<<endl;
			break;
		case 5:
			cout << "Podaj nazwe firmy, ktora chcesz usunac: " << endl;
			cin >> tName;
			for (int i = 0; i < fm.current_size(); i++)
				if (fm[i].Name() == tName)
					fm.erase(i);
			break;
		case 0:
			done = true;
			break;
		default:
			cout << "Unknown command." << endl;
			break;
		}
// cin.ignore();
// cin.ignore();
	}



	return 0;
}