#ifndef LIST
#define LIST

//#include "Iterator.h"
#include "node.h"

template <typename T>
class List{
private:
    T* _node;
    T* _next;  
    T* _prev;
    int _size;
    int _current;

public:
//	typedef Iterator<T, Node<T> > iterator;

	//konstruktory
	List(T& node);
	//medody modyfikujace
	
	void push_back(const T& new_elem);
	void pop_back();
	void insert(const T& new_elem, int position);
	void erase(int position);
	void clear();
	//przeciaenia operatorw
	T& operator[](int position) const;
	Vector& operator=(const Vector& source);
	//metody sprawdzajace
	bool isempty() const;
	int max_size() const;
	int current_size() const;
	iterator begin(){
		return iterator(*this);
	}

	iterator end(){
		return iterator(*this) + _current_size;
	}
	~Vector(){
		delete [] _tab; 
	}
    
};


//konstruktory
template<class T>
List<T>::List(T &node)
: _size(1),_current(1),_node(&node),_next(NULL),_prev(NULL) {
}

template<class T>
void List<T>::push_back(const T& new_elem){
	_size++;
}

#endif
