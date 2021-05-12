//***************************************************************************
//
//  main.cpp
//  CSCI 501 Assignment 5
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "bank.h"
#include "account.h"
#include <iostream>

using namespace std;

int main()
{
	bank b;

	b.read_accounts("accounts.bin");

	cout << b << endl;

	b.process_transactions("transactions.txt");

	cout << endl << b;


}