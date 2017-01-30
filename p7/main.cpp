#include <iostream>
#include <vector>

using namespace std;

//*********** A *************

template <class Iter>
void wypisz_na_cout(Iter begin, Iter end){
    cout << endl;
    for(Iter It= begin; It!= end; It++)
        cout << *It << " ";
}

template <class Iter>
void wypisz_na_cout(Iter begin, int how_many){
    int i = 0;
    cout << endl;
    for(Iter It= begin;i < how_many;i++, It++)
        cout << *It << " ";
}

template < class container>
void wypisz_na_cout(const container & gc){
    cout << endl;
    for(auto It= gc.begin();It!=gc.end(); It++)
        cout << *It << " " ;
}

//*********** B *************

template <class dt>
struct is_equal{
    dt _data;
	is_equal(dt in=10):_data(in){};
    bool operator() (const dt& x ){
        return _data == x;
    }
};

template <class dt>
struct multiple{
	dt _data;
	multiple(dt in=10):_data(in){};
	dt operator() (dt& x ){
		return x= _data * x;
	}
};

template <class Iter,class Cond,class Oper>
void zrealizuj(Iter a, Iter b, Cond cnd, Oper op){
    while (a != b) {
        if (cnd(*a))
            op(*a);
        ++a;
    }
}


//*********** main *************
 int main() {

     float tab[4] = {1, 2, 3, 4};
     vector<int> v = vector<int>(20, 10);
     v[5] = 30;
     cout << "wypisz wektor - 2 iteratory ";
     wypisz_na_cout(v.begin(), v.end());
     cout << endl << endl << "wypisz tablice ";
     wypisz_na_cout(tab, tab + 4);
     cout << endl << endl << "wypisz wektor - iterator i ilosc (6) ";
     wypisz_na_cout(v.begin(), 6);
     cout << endl << endl << "wypisz wektor";
     wypisz_na_cout(v);
     cout << endl << endl << "jesli element =30 pomnoz przez 10";
     zrealizuj(v.begin(), v.end(), is_equal<int>(30), multiple<int>(10));
     wypisz_na_cout(v);
     return 0;
}