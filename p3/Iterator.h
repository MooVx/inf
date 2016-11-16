#ifndef ITERATOR
#define ITERATOR

#include <iostream>


template <typename T, typename T_obj>
class Iterator{
private:
    T_obj* _ptr;
    int _position;

public:
    Iterator(T_obj& box): _position(0){
        _ptr=&box;
    }

    T& operator*(){
        return (*_ptr)[_position];
    }

    Iterator& operator++(){
		if (_position >= (*_ptr).current_size())
			std::cerr<<"Operation: ++ out of range";
        else{
            ++_position;
        }
        return *this;
	}

    Iterator& operator--(){
		if (_position <= 0 )
			std::cerr<<"Operation: -- out of range";
        else{
            --_position;
        }
        return *this;
	}
    Iterator operator++(int){
		if (_position >= (*_ptr).current_size())
			std::cerr<<"Operation: ++ out of range";
        else{
            _position++;
        }
        return *this;
	}

    Iterator operator--(int){
		if (_position <= 0 )
			std::cerr<<"Operation: -- out of range";
        else{
            _position--;
        }
        return *this;
	}
    Iterator& operator+(int add){
        if (_position > (*_ptr).current_size())
			std::cerr<<"Operation: + out of range";
        else{
        _position += add;
        }
        return *this;

	}

    Iterator& operator-(int sub){
		if (_position - sub < 0 )
			std::cerr<<"Operation: - out of range";
        else{
            _position -= sub;
        }
        return *this;
	}

    Iterator& operator=(const Iterator& source){
		_ptr = source._ptr;
		_position = source._position;
		return *this;
	}


	bool operator==(const Iterator& current){
        if(_ptr == current._ptr && _position == current._position)
            return true;
		else
            return false;
	}

	bool operator!=(const Iterator& current){
		return !(*this == current);
	}

};

#endif