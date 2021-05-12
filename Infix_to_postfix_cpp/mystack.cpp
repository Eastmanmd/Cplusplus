//***************************************************************************
//
//  mystack.cpp
//  CSCI 501 Assignment 7
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "mystack.h"
#include <iostream>
#include <cstddef>

using namespace std;

/**
 * Default constructor for the mystack class. Initiializes the size_t variables to 
 * 		"0" and sets the pointer to nullpoiner
 *
 *
 ********************************************************************************/
mystack::mystack()
{
	stack_size = 0;
	stack_capacity = 0;
	stack_arr_ptr = nullptr; 

}

/**
 * Copy constuctor for the mystack class. Copies the content an object of the mystack
 * 		class into another mystack object
 *
 * @param x The object of the mystack class of which we want to replicate 
 *
 * @note This is a deep copy so the stack_arr_ptr of the new onject should point
 *     to a new array
 ********************************************************************************/
mystack::mystack(const mystack& x)
{
	stack_size = x.stack_size;
	stack_capacity = x.stack_capacity;

	if (x.stack_capacity == 0)
	{
		stack_arr_ptr = nullptr;
	}

	else 
	{
		stack_arr_ptr = new char[stack_capacity];
	}

	for (size_t i = 0; i < stack_size; ++i)
	{
		stack_arr_ptr[i] = x.stack_arr_ptr[i];
	}



}

/**
 * Destructor function of the mystack class. Ensures that all the contents of 
 *      the dynamically assigned arrays are deleted 
 *

 ********************************************************************************/
mystack::~mystack()
{
	delete[] stack_arr_ptr; //deletes the dynamic array

}


/**
 * Overloaded assignment operator that assigns the content of object in the mystack
        class to another object of the same class.
 *
 * @param mystack& x takes in a reference of to an object in the mystack class of which 
        contains members to be assigned to another mystack object. 
 *
 * @return the new object after the assignment operation is completed. 
 *
 ********************************************************************************/
mystack& mystack::operator=(const mystack& x)
{
	if (this != & x)  //checks if left and right side of the operand are already equal
	{
		delete[] stack_arr_ptr; //deletes the stack array if one already exist

		stack_size = x.stack_size;
		stack_capacity = x.stack_capacity;

		if (x.stack_capacity == 0)
		{
			stack_arr_ptr = nullptr;
		}

		else 
		{
			stack_arr_ptr = new char[stack_capacity];
		}

		for (size_t i = 0; i < stack_size; ++i)
		{
			stack_arr_ptr[i] = x.stack_arr_ptr[i];
		}


	}


	return *this;

}

/**
 * Gets the current capacity of the stack
 *
 *
 * @return the current capacity of the stack 
 *
 * @note this is a constant function and can not change the private member of the 
 *     class. 
 ********************************************************************************/
size_t mystack::capacity() const
{
	return stack_capacity;

}


/**
 * Gets the current size of the stack
 *
 *
 * @return the current size of the stack 
 *
 * @note this is a constant function and can not change the private member of the 
 *     class. 
 ********************************************************************************/
size_t mystack::size() const
{
	return stack_size;

}


/**
 * Checks if the stack is emtpty, i.e if the size of the stack is zero 
 *
 *
 * @return true if the stack is empty 
 * @return false if the stack is not emoty 
 *
 * @note this is a constant function and can not change the private member of the 
 *     class. 
 ********************************************************************************/
bool mystack::empty() const //checks if the stack is empty
{
	if (stack_size == 0)
	{
		return true;
	}

	else
	{
		return false;
	}

}


/**
 * Resets the size of the stack to zero hereby emoptying the stack
 *
 *
 * @note this is a mutator fucntion that can change a private member of the class 
 ********************************************************************************/
void mystack::clear()
{
	stack_size = 0; // sets the stack size to zero

}

/**
 * Increases the capacity of the stack only if the stack runs of out of capacity 
 *
 * @param n the new capacity of the stack 
 *
 ********************************************************************************/
void mystack::reserve(size_t n)
{
	if (n < stack_size || n == stack_capacity)
	{
		return;
	}

	stack_capacity = n;

	char * temp; // temporarily holds the content of the pointer 

	temp = new char[stack_capacity];

	for (size_t i = 0; i < stack_size; ++i)
	{
		temp[i] = stack_arr_ptr[i];
	}

	delete [] stack_arr_ptr; //deletes the contents of the old array 

	stack_arr_ptr = temp;



}



/**
 * Accesses the element at the top of the stack 
 *
 *
 * @return returns the element at the top of the stack 
 *
 * @note this is a constant function and can not change the private member of the 
 *     class. 
 ********************************************************************************/
const char& mystack::top() const
{

	return stack_arr_ptr[ stack_size - 1];

}


/**
 * Function to push a new element into the top of the stack 
 *
 * @param value The new character value to be pushed onto the top of the stack
 *
 ********************************************************************************/
void mystack::push(char value)
{
	if (stack_size == stack_capacity)
	{
		if (stack_capacity == 0)
		{
			reserve(1);
		}

		else 
		{
			reserve((2 * stack_capacity));
		}
	}

	stack_arr_ptr[stack_size] = value;

	stack_size++;

}


/**
 * Function to remove an element from the top of the stack 
 *
 ********************************************************************************/
void mystack::pop()
{

	stack_size --;

}



