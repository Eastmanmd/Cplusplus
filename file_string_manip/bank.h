//***************************************************************************
//
//  bank.h
//  CSCI 501 Assignment 5
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#ifndef BANK_H 
#define BANK_H

#include "account.h"
#include <string>
#include <fstream>
#include<iostream>
#include <string.h>
using namespace std;

class bank 
{
private:

	char bank_name[32];
	account objects[20]; 
	int elements_filled; //the number of account objects[] filled with valid data 
	
public:

	bank(); // default constructor

	void read_accounts(const string& filename); 

	void process_transactions( const string& filename);

	friend ostream& operator<< (ostream& lhs, const bank& rhs); //overloaded insertion function

	void selection_sort(account arr[], int n); 

	int bsearch(account a[], int n, char value[]);


};

#endif /* BANK_H */