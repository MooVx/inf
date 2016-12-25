#ifndef LIST
#define LIST

#include <iostream>
#include <new>          // std::bad_alloc
#include<cstring>
#include <cstdlib>
#include <unistd.h>

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

template <class T>
void List<T>::print(){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		Node<T>* ptr=_first;
		do{
			cout << ptr->_data;
			ptr=ptr->_next;
		}while (ptr!=_first);
		cout << endl;
		//realizacja kursora:
		do{
			if(ptr==_node)
				cout << "^";
			else
				cout << " ";
			ptr=ptr->_next;
		}
		while (ptr!=_first);
		cout << endl;
	}
	catch (exception& ba){
		cerr << "logic_error Lista.print(): " << ba.what() << endl;
		sleep(2);
	}
}

template<class T>
bool List<T>::isEmpty() const{
	if(_size==0)
		return true;
	return false;
}

template<class T>
void List<T>::insert(const T& new_elem){
	try{
		if(isEmpty()){
			_node=new Node<T>(new_elem);
			(*_node)._prev=_node;
			(*_node)._next=_node;
			_first=_node;
			_last=_node;
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
		}
		_size++;
	}
	catch (std::bad_alloc& ba){
		cerr << "bad_alloc Lista.insert(): " << ba.what() << endl;
		sleep(2);
		exit(1);
	}
}

template<class T>
void List<T>::replace(const T& new_data){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		_node->_data=new_data;
	}
	catch (logic_error& ba){
		cerr << "logic_error Lista.replace(): " << ba.what() << endl;
		sleep(2);
	}

}

template<class T>
void List<T>::remove(){
	try {
		if(isEmpty())throw logic_error("pusta lista");
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
	catch (logic_error& ba){
		cerr << "logic_error Lista.remove(): " << ba.what() << endl;
		sleep(2);
	}	
}

template<class T>
void List<T>::clear(){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		Node<T>* ptr= _first;
		while (ptr!=_last){
			_node=ptr;
			ptr=_node->_next;
			delete _node;
		}
		delete _last; 
		_size=0;
	}
	catch (bad_alloc &ba){
		cerr << "Error Lista.clear(): " << ba.what() << endl;
		sleep(2);
	}
}

template<class T>
void List<T>::gotoBegin(){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		_node=_first;
	}
	catch (logic_error& ba){
		cerr << "logic_error Lista.gotoBegin(): " << ba.what() << endl;
		sleep(2);
	}
}

template<class T>
void List<T>::gotoEnd(){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		_node=_last;
	}
	catch (logic_error& ba){
		cerr << "logic_error Lista.gotoEnd(): " << ba.what() << endl;
		sleep(2);
	}
}

template<class T>
void List<T>::gotoNext(){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		_node=_node->_next;
	}
	catch (logic_error& ba){
		cerr << "logic_error Lista.gotoNext(): " << ba.what() << endl;
		sleep(2);
	}
}

template<class T>
void List<T>::gotoPrev(){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		_node=_node->_prev;
	}
	catch (logic_error& ba){
		cerr << "logic_error Lista.gotoPrev(): " << ba.what() << endl;
		sleep(2);
	}
}

template<class T>
T List<T>::getCursor(){
	try{
		if(isEmpty())throw logic_error("pusta lista");
		return _node->_data;
	}
	catch (logic_error& ba){
		cerr << "logic_error Lista.getCursor(): " << ba.what() << endl;
		sleep(2);
	}
}

template<class T>
bool List<T>::operator==(const List<T>& current){
	try{
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
	catch (logic_error& ba){
		cerr << "logic_error Lista.gotoBegin(): " << ba.what() << endl;
		sleep(2);
		exit(1);
	}
}




#endif
