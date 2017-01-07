#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

void ZadA(void);
void ZadB(void);
void ZadC(void);

int main(){
	ZadA();
	ZadB();
	ZadC();
	return 0;
}

void ZadA(void){
	//zadA***************************
	cout << endl << "****ZadA************************************" << endl << endl;
	vector<int> v;
	// add integers at the end of the vector
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	v.push_back(5);
	// display info about v
	cout << "The size of v is: " << v.size() << "\nThe capacity of v is: " << v.capacity();
	vector<int>::const_iterator it;
	vector<int>::const_iterator itr;
	cout << "\nThe content of v is: ";
	cout << endl;
	for (it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl << endl ;
	//1
	v.insert(v.begin()+1, 7);
	//2
	v[0]=9;
	//3
	v.push_back(v[0]);
	v.push_back(v[1]);
	//4
	cout << "Element o wartosci 3: " << *find(v.begin(), v.end(), 3) << endl;
	//5
	v.erase(find(v.begin(), v.end(), 3));
	//6
	cout << "Minimum: " << *min_element(v.begin(), v.end()) << endl;
	//7
	sort(v.begin(), v.end());
	//8
	reverse(v.begin(), v.end());
	//9
	cout << "Ilosc 9 : " << count(v.begin(), v.end(), 9) << endl
	     << "Suma 9 : " << count(v.begin(), v.end(), 9) * 9 << endl;
	//10
	cout << "Suma 4 pierwszych elementow : " << accumulate(v.begin(), v.begin() + 4, 0) << endl;
	
	// display info about v
	cout << "\nThe size of v is: " << v.size() << "\nThe capacity of v is: " << v.capacity();
	cout << "\nThe content of v is: ";
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;

	//============================================================
}

void ZadB(void){
	//zadB***************************
	cout << endl << "****ZadB************************************" << endl << endl;
	set<int, less <int>> s;
	set<int, less <int>>::const_iterator it_s;
	// add integers to set
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(7);
	s.insert(5);
	cout << "The size of s is: " << s.size();
	cout << "\nThe content of s is: ";
	for (it_s = s.begin(); it_s != s.end(); it_s++) {
		cout << *it_s << " ";
	}
	cout << endl << endl;
	//1
	s.insert(7);
	//2
	s.erase(s.begin());
	s.insert(9);
	//4
	cout << "Element o wartosci 3: " << *find(s.begin(), s.end(), 3) << endl;
	//5
	s.erase(find(s.begin(), s.end(), 3));
	//6
	cout << "Minimum: " << *min_element(s.begin(), s.end()) << endl;
	//9
	cout << "Ilosc 9 : " << count(s.begin(), s.end(), 9) << endl
	     << "Suma 9 : "  << count(s.begin(), s.end(), 9) * 9 << endl;
	//10
	cout << "Suma 4 pierwszych elementow : " << accumulate(s.begin(), s.end(), 0) << endl;
	
	// display info about s
	cout << "\nThe size of s is: " << s.size();
	cout << "\nThe content of s is: ";
	for (it_s = s.begin(); it_s != s.end(); it_s++) {
		cout << *it_s << " ";
	}
	cout << endl << endl;

	//============================================================
}

void ZadC(void){
	//zadC***************************
	cout << endl << "****ZadC************************************" << endl << endl;
	typedef multimap <int, string, less <int>> mp_type;
	mp_type mp;
	mp_type::iterator it_mp;
	// add pairs to multimap
	mp.insert(pair<int, string>(2, "dwa"));
	mp.insert(pair<int, string>(3, "trzy"));
	mp.insert(pair<int, string>(4, "cztery"));
	mp.insert(pair<int, string>(7, "siedem"));
	mp.insert(pair<int, string>(5, "piec"));
	cout << "The size of mp is: " << mp.size();
	cout << "\nThe content of mp is: \n";
	for (it_mp = mp.begin(); it_mp != mp.end(); it_mp++) {
		cout << (*it_mp).first << " - " << (*it_mp).second << endl;
	}
	cout << endl;
	//1
	mp.insert(pair<int, string>(7, "siedem"));
	//2
	mp.erase(mp.begin());
	mp.insert(pair<int, string>(9, "dziewiec"));
	//3
	pair <int, string> temp = *mp.begin();
	it_mp = (++mp.begin());
	mp.insert(temp);
	mp.insert(*it_mp);
	//4
	pair <mp_type::iterator, mp_type::iterator> range;
	range = mp.equal_range(3);
	cout << "Element o wartosci 3: ";
	for (it_mp = range.first; it_mp != range.second; it_mp++)
		cout << (*it_mp).first << " - " << (*it_mp).second << endl;
	//5
	mp.erase(3);
	//6
	cout << "Minimum: " << (*min_element(mp.begin(), mp.end())).first << " - " << (*min_element(mp.begin(), mp.end())).second << endl;
	//9
	cout << "Ilosc 9 : " << mp.count(9) << endl
	     << "Suma 9 : "  << mp.count(9) * 9 << endl;
	//10
	int sum, n;
	for (it_mp = mp.begin(), n = 0, sum = 0; n < 4; it_mp++, n++) {
		sum+=(*it_mp).first;
	}
	cout << "Suma 4 pierwszych elementow : " << sum << endl;
	// display info about mp
	cout << "\nThe size of mp is: " << mp.size();
	cout << "\nThe content of mp is: \n";
	for (it_mp = mp.begin(); it_mp != mp.end(); it_mp++) {
		cout << (*it_mp).first << " - " << (*it_mp).second << endl;
	}
	cout << endl;

	//============================================================	
}