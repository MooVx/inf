#ifndef LIST
#define LIST

#include <iostream>

using namespace std;

template <class T>
class List;

template <class T>
class Node{
    private:
        T _data;
        Node* _prev;
        Node* _next;
		friend class List<T>;
        Node(const T &data){_data=data;}
	public:
        virtual ~Node(){}
};

template <class T>
class List{
private:
    Node<T> * _first;
	Node<T> * _last;
	Node<T> * _node;
    int _size;
public:
	List(): _size(0){}
	virtual ~List();
	bool isEmpty () const;
	void print();
	void insert(const T& new_elem);
	void remove();
	void replace(const T& new_data);
	void clear ();
	void gotoBegin();
	void gotoEnd();
	void gotoNext();
	void gotoPrev();
	T getCursor();
	bool operator==(const List& current);



    
};

template <class T>
void List<T>::print(){
	Node<T>* ptr=_first;
	do{
		cout << ptr->_data;
//		cout << " ";
		ptr=ptr->_next;
	}while (ptr!=_first);
	cout << endl;
	//realizacja kursora:
	do{
		if(ptr==_node)
			cout << "^";
		else
			cout << " ";
//		cout << " ";
		ptr=ptr->_next;
	}while (ptr!=_first);
	cout << endl;
}


//destruktor
template<class T>
List<T>::~List(){
	Node<T>* ptr= _first;
	while (ptr!=_last){
		_node=ptr;
		ptr=_node->_next;
		delete _node;
	}
	delete _last; 
}

template<class T>
bool List<T>::isEmpty() const{
	if(_size==0)
		return true;
	return false;
}

template<class T>
void List<T>::insert(const T& new_elem){
	if(isEmpty()){
		_node=new Node<T>(new_elem);
		(*_node)._prev=_node;
		(*_node)._next=_node;
		_first=_node;
		_last=_node;
		_size++;
	}
	else{
		Node<T>* ptr=new Node<T>(new_elem);
		ptr->_next=_node->_next;
		_node->_next=ptr;
		(ptr->_next)->_prev=ptr;
		ptr->_prev=_node;
		if(_node==_first&&_size!=1)_first=ptr;
		if(_node==_last)_last=ptr;

		_node=ptr;
		_size++;
	}
}

template<class T>
void List<T>::replace(const T& new_data){
	_node->_data=new_data;


}

template<class T>
void List<T>::remove(){
	Node<T>* N=_node->_next;
	Node<T>* P=_node->_prev;
	P->_next=N;
	N->_prev=P;
	if(_node==_first)_first=N;
	if(_node==_last)_last=P;
	delete _node;
	_node=P;
	_size--;
}
template<class T>
void List<T>::clear(){
	Node<T>* ptr= _first;
	while (ptr!=_last){
		_node=ptr;
		ptr=_node->_next;
		delete _node;
	}
	delete _last; 
	_node=NULL;
	_first=NULL;
	_last=NULL;
	_size=0;
}

template<class T>
void List<T>::gotoBegin(){
	_node=_first;
}

template<class T>
void List<T>::gotoEnd(){
	_node=_last;
}

template<class T>
void List<T>::gotoNext(){
	_node=_node->_next;
}

template<class T>
void List<T>::gotoPrev(){
	_node=_node->_prev;
}

template<class T>
T List<T>::getCursor(){
	return _node->_data;
}

template<class T>
bool List<T>::operator==(const List<T>& current){
	Node<T>* ptr1=_first;
	Node<T>* ptr2=current._first;
    do{
        if(ptr1->_data!=ptr2->_data)
			return false;
        ptr1=ptr1->_next;
		ptr2=ptr2->_next;
    }while (ptr1!=_first);
	return true;
}




#endif
