#ifndef VECTOR
#define VECTOR

#include "Iterator.h"


template <typename T>
class Vector{
private:
    T* _tab;     
    int _current_size;
    int _max_size;
    void resize();

public:
    typedef Iterator<T, Vector<T> > iterator;

    //konstruktory
    explicit Vector(int _max_size =10);
    Vector(const Vector<T>& source);
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
template<typename T>
Vector<T>::Vector(int init_cap)
: _current_size(0),_max_size(init_cap) {
    _tab = new T[_max_size];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& source){
    _current_size = source._current_size;
    _max_size = source._max_size;
    _tab = new T[_max_size ];
	for (int i = 0; i < _current_size ; i++)
		_tab[i] = source._tab[i];
}

//medody modyfikujace
template<typename T>
void Vector<T>::push_back(const T& new_elem){
    insert(new_elem,_current_size);
}

template<typename T>
void Vector<T>::pop_back(){
    erase(_current_size - 1);
}

template<typename T>
void Vector<T>::insert(const T& new_elem, int position){
    if(position>_current_size)
        _current_size=position+1;
    else
        _current_size++;
    if(_current_size>=_max_size){
        resize();
    }

    T* temp = new T[_max_size];
	for (int i = 0; i < position; i++)
		temp[i] = _tab[i];

	temp[position] = new_elem;
	for (int i = position; i < _current_size; i++)
		temp[i+1] = _tab[i];

	delete [] _tab;
	_tab = temp;
}

template<typename T>
void Vector<T>::erase(int position){
    for (int i = position; i < _current_size; i++){
        _tab[i] = _tab[i + 1];
    }
	_current_size--;
}

template<typename T>
inline void Vector<T>::clear(){
    _current_size=0;
}

template<typename T>
void Vector<T>::resize(){
    _max_size += 5;
    T* temp = new T[_max_size];
	for (int i = 0; i < _current_size; i++)
		temp[i] = _tab[i];

	delete [] _tab;
	_tab = temp;
 }

//metody sprawdzajace
template<typename T>
inline bool Vector<T>::isempty() const{
    if(_current_size==0)
        return true;
    else
        return false;
}

template<typename T>
inline int Vector<T>::max_size() const{
    return _max_size;
}

template<typename T>
inline int Vector<T>::current_size() const{
    return _current_size;
}


//przeciaenia operatorw
template<typename T>
T& Vector<T>::operator[](int position) const{
    if (position>_max_size){
		std::cerr<<"Out of max size!\n";
    }
    return _tab[position];
    
	

}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& source){
    _current_size = source._current_size;
    _max_size = source._max_size;
    if (_tab != 0){
        delete[] _tab;
    }
    _tab = new T[_max_size ];
	for (int i = 0; i < _current_size ; i++)
		_tab[i] = source._tab[i];

	return *this;
}


#endif
