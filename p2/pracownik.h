#ifndef PRACOWNIK
#define PRACOWNIK

#include <iostream>
#include <string>

using std::string;

class Pay {
	private:
		string _name;
		string _surname;
		float _NIP;
		float _PESEL;

	public:
		Pay(string name = "nie uzupelniono", string surname = "nie uzupelniono", float pesel = 0000, float nip = 0000);
		virtual void print();
		virtual void calc_wage() = 0;
		virtual ~Pay() {}
};

class Etat : public Pay { 
	private:
		float _salary;

	public: 
		Etat(string name, string surname, float pesel, float nip, float salary);
		void print();
		void calc_wage() {}
		virtual ~Etat() {}
};

class Contract : public Pay { 
	private:
		float _salary;
		int _hours;
		float _rate;
	public: 
		Contract(string name, string surname, float pesel, float nip, int hours, float rate);
		void print();
		void calc_wage();
		virtual ~Contract() {}
};

class Dealer : public Pay { 
	private:
		float _salary;
		int _sales;
		float _percent;
	public: 
		Dealer(string name, string surname, float pesel, float nip, int sales, float percent);
		void print();
		void calc_wage();
		virtual ~Dealer() {}
};


#endif
