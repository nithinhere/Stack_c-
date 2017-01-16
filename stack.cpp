#include "stack.h"


// dynamic array implementation of stack ADT

// consturctor create a new stack of given capacity
// parameter:
//    capacity: the initial capacity of the stack, default to INITCAP
stack::stack(int capacity): _capacity(capacity), _tos(0){
    _arr = new TYPE[_capacity];
    for(int i=0; i < _capacity; i++)
        _arr[i] = "";
}

// copy constructor create a new stack whick is a deep copy
// of the rhs stack. 
// parameter:
//    rhs: the stack object to copy from
// returns: n/a 
stack::stack(const stack& rhs){
    _tos = rhs._tos;
    _capacity = rhs._capacity;
    _arr = new TYPE[_capacity];
    for(int i=0; i < _tos; i++)
        _arr[i] = rhs._arr[i];
}

// assignment operator
// parameter:
//    rhs: the stack object to be assigned from 
// returns: a deep copy of the rhs stack object
stack& stack::operator=(const stack& rhs) {
    if (this != &rhs){
        _capacity = rhs._capacity;
        _tos = rhs._tos;
        delete [] _arr;
        _arr = new TYPE[_capacity];
        for ( int i=0; i<_tos; i++ )
            _arr[i] = rhs._arr[i];
    }
    return *this;
}

stack::~stack(){ delete [] _arr; }


// push an element on the stack. If the stack's full
// capacity is not reached, push directly. Otherwise,
// double the stack capacity and then push the element.
// parameter:
//    x: element to be pushed on stack
// returns: void
void stack::push(string x){
    if(_tos == _capacity){
        _capacity *= 2;
        TYPE * temp = new TYPE[_capacity];  // double the size
        for ( int i=0; i<_tos; i++ )
            temp[i] = _arr[i];
        delete [] _arr;
        _arr = temp;
    }
    _arr[_tos++] = x;
}

// pop the top element from the stack
// precondition: stack is not empty
// parameter: none
// returns: void
void  stack::pop(){
    if(_tos == 0)
        throw EmptyStackException();
    _tos--;
}

// return the top element from the stack
// the element is not popped from the stack
// precondition: stack is not empty
// parameter: none
// returns: void
string& stack::top(){
    if(_tos == 0)
        throw EmptyStackException();
    
    return _arr[_tos-1];
}

// return true if the stack is empty, false otherwise
// parameter: none
// returns: bool 
bool stack::empty(){
    return (_tos == 0);
}


// return the number of elements currently on the stack
int stack::size(){
    return _tos;
}


// return the capacity of the stack
int stack::capacity(){
    return _capacity;
}

// output stack elements 
void stack::dump(ostream &os){
    for(int i=1; i<=_tos; i++)
        os << _arr[_tos-i] << " ";
	os << endl;
}


