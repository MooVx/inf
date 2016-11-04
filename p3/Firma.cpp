
#include "Firma.h"

#include<fstream>


using namespace std;

void Firm::AddPlace(){
    string st_name;
    int number;
    cout << "Podaj nazwe ulicy:" << endl;
    cin >> st_name;
    cout << "Numer lokalu ?" << endl;
    cin >> number;
    _places.push_back(Shop(st_name, number));
    _number=_places.current_size();
    cout << "Czy chcesz wprowadzic zabawki do tego sklepu T/N?" << endl;
	char a;
	cin >> a;

	if (a == 'T'){
		cout << "Ile zabawek chcesz dodac?" << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			_places[_number - 1].addToy();
	}
}

void Firm::ModPlace(int number){	
		cout << "Czy chcesz dodac/usunac zabawki, wprowadz: D/U" << endl;
		char a;
		cin >> a;
		if (a == 'D'){
            _places[number].addToy();
        }
		else
		{
			cout << "Jakie zabawki chcesz usunac?" << endl;
			string Name;
			cin >> Name;
			_places[number].deleteToy(Name);
		}
}

ostream& operator<<(ostream& out, const Firm& outF){
	out << setw(20) << outF._name << endl;
	for (int i = 0; i < outF._number; i++){
		out << outF._places[i];
    }
	return out;
}

istream& operator>>(std::istream& in, Firm& inF){
	in >> inF._name;
	return in;
}

ifstream& operator>>(std::ifstream& infile, Firm& inF){
////////////////////
	return infile;
}