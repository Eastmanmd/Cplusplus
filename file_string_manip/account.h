//***************************************************************************
//
//  account.h
//  CSCI 501 Assignment 5
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "account.h"
#include <iostream>
#include <iomanip>


using namespace std;

class account
{
private:
	double account_balance;
	char account_number[32];
	char customer_name[16];

public:

	account(); //default constructor 

	const char * get_account_number() const;

	double get_balance() const;

	void process_deposit(double deposit); // takes in deposit and adds to the current account balance

	bool process_withdrawal(double withdrawal);

	friend ostream& operator<< (ostream& lhs, const account& rhs);


	friend class bank;
	

};


#endif /* ACCOUNT_H */