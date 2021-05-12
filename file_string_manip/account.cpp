//***************************************************************************
//
//  account.cpp
//  CSCI 501 Assignment 5
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************


#include "account.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;


/**
 * default contructor for the account class
 *
 *
 *
 * @note sets the string array to "none" and int values to "0"
 *    
 ********************************************************************************/
account::account()
{
	account_balance = 0;
	strncpy(account_number, "None", sizeof(account_number)); //initializes this to "none"
	strncpy(customer_name, "None", sizeof(customer_name)); //initializes this to "none"
}



/**
 * gets the account account number from an object in the account class
 *
 * @return returns the address of the account number of an object in the account class
 *
 * @note this function is an accessor and can not change the contents of the account number
 *    
 ********************************************************************************/
const char * account::get_account_number() const
{
	const char *p = account_number;

	return p; //should i store this in the heap
}



/**
 * gets the account account balance from an object in the account class
 *
 * @return returns the account balance of an object in the account class
 *
 * @note this function is an accessor and can not change the account balance
 *    
 ********************************************************************************/
double account::get_balance() const
{ 
	return account_balance;

}



/**
 * updates the account account balance from an object in the account class by adding
 *       the deposit amount to the exisiting account balance 
 *
 * @param deposit amount to be added to the account balance 
 *
 * @note this function is an mutator and can change the account balance
 *    
 ********************************************************************************/
void account::process_deposit(double deposit)
{
	account_balance = account_balance + deposit;
}



/**
 * updates the account account balance from an object in the account class by subtracting
 *       the withdrawal amount from the exisiting account balance 
 *
 * @param withdrawal amount to be removed from the account balance
 *  
 * @return true if the withdrawal amount is less than or equalt to account balance
 * @return false is withdrawal is greater than account balance
 *    
 ********************************************************************************/
bool account::process_withdrawal(double withdrawal)
{
	if (account_balance <= withdrawal)
	{
		return false;
	}

	else
	{
		account_balance = account_balance - withdrawal;

		return true;
	}

}


/**
 * overloaded insertion operator that prints out the contents of an object in an
 *    organized format
 *
 * @param lhs represents the insertion operator 
 * @param account& rhs a reference to an instance  of the account class
 *    
 * 
 ********************************************************************************/
ostream& operator<< (ostream& lhs, const account& rhs)
{
	lhs << "Account Number: " << rhs.account_number << endl;
	lhs << "Name: " << rhs.customer_name << endl;
	lhs << "Balance: " << "$" << fixed << setprecision(2) << rhs.account_balance;
	return lhs;
}





















