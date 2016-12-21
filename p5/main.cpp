#include <iostream>
#include <vector> //vector class-template
#include <algorithm>    // std::find

using namespace std;

int main()

{

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
	
	for (it = v.begin(); it != v.end(); it++)

	{

		cout << *it << " ";

	}
	
	
	cout << endl;
	
	v.insert( v.begin()+1, 7 );
	
	for (it = v.begin(); it != v.end(); it++)

	{

		cout << *it << " ";

	}

	//============================================================
	cout << endl;
	
	v[0]=9;

	for (it = v.begin(); it != v.end(); it++)

	{

		cout << *it << " ";

	}

	//============================================================
	cout << endl;

	v.push_back(v[0]);
	v.push_back(v[1]);
	
	
	for (it = v.begin(); it != v.end(); it++)

	{

		cout << *it << " ";

	}

	//============================================================
	cout << endl;
	
	
	itr=find(v.begin(),v.end(),3);
	
	
		for (it = v.begin(); it != v.end(); it++)

	{


		if(itr==it)
			cout << "^";
		else
			cout << " ";
		cout << " ";

	}

	//============================================================
	cout << endl;
	
	v.erase(itr);
	
	for (it = v.begin(); it != v.end(); it++)

	{

		cout << *it << " ";

	}

	//============================================================
	cout << endl;
	
	cout << *min_element(v.begin(),v.end()) << endl;
	
	
	return 0;
}