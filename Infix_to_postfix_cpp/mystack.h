//***************************************************************************
//
//  mystack.h
//  CSCI 501 Assignment 7
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************


#ifndef MYSTACK_H 
#define MYSTACK_H


#include <iostream>
#include <cstddef>

using namespace std;

class mystack
{

private:

	char* stack_arr_ptr; 
	size_t stack_capacity; //the capacity of stack array
	size_t stack_size; //how much of the stack array is currently used. 

public:

	mystack();  // default constructor 

	mystack(const mystack& x); //copy constructor (deep copu)

	~mystack();

	mystack& operator=(const mystack& x);

	size_t capacity() const;

	size_t size() const;

	bool empty() const;

	void clear();

	void reserve(size_t n);

	const char& top() const;

	void push(char value);

	void pop();

	friend string convert(const string& infix);


} ;



#endif /* MYSTACK_H */
