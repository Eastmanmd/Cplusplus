//***************************************************************************
//
//  bank.cpp
//  CSCI 501 Assignment 5
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************


#include "bank.h"
#include "account.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/**
 * default contructor for the bank class
 *
 *
 *
 * @note sets the string array to "none" and int values to "0"
 *    
 ********************************************************************************/
bank::bank() // default constructor
{
	strncpy(bank_name, "None", sizeof(bank_name)); 
	elements_filled = 0;

	for(int i =0; i>20; i++)
	{
		objects[i].account_balance = 0;
		strncpy(objects[i].account_number, "None", sizeof(objects[i].account_number)); //initializes this to "none"
		strncpy(objects[i].customer_name, "None", sizeof(objects[i].customer_name)); //initializes this to "none"

	}
}



/**
 * sorts the contenet of an array containing srings in ascending order 
 *
 * @param arr[] takes in an unsorted array and sorts the contents of this array
 *       using the selection sort algorithm 
 * @param n the number of items to be sorted in the array
 *
 * @note uses selection sort algorithm to sort strings in an array
 ********************************************************************************/
void bank::selection_sort(account arr[], int n) 
{
  int i = 0;
  int j; 
  int min_index; //tracks the smallest value in the array
  int result; //tracks the string comparison result using the strcmp() function

  while (i < (n-1))
  {

  	min_index = i;
    j = i + 1;
    while (j < n)
    {
    	result = strcmp(arr[j].get_account_number(), arr[min_index].get_account_number());

    	if (result < 0) 
    	{
    		min_index = j;
    	}
      	j = j + 1;
    }
    swap(arr[i], arr[min_index]);

    i = i + 1;
  }
}



/**
 * searches for a string in an array 
 *
 * @param arr[] array of account objects to be searched 
 * @param n the number of items in the array containing objects to be searched 
 * @param value[] a array containing the search input 
 *
 * @return -1 if the string was not found in the array
 *    
 * @note uses binary search so array must be sorted in ascending order
 ********************************************************************************/
int bank::bsearch(account a[], int n, char value[]) 
{
	size_t lo = 0;
	size_t hi = n-1;

	while (lo <= hi)
	{
		size_t mid = (lo + hi)/2;

		int result; //stores result from strcmp()
		result = strcmp(value, a[mid].get_account_number());

		if (result == 0)

			return mid; 

		if (result < 0)
			hi = mid - 1;

		else 
			lo = mid+1;
	}

	return -1; // it isnt there 
}


/**
 * reads the content of file into an entire class object
 *
 * @filename name of the file to be read
 *    
 * 
 ********************************************************************************/
void bank::read_accounts(const string& filename)
{
	ifstream in_file;

	//open the file and check for failures
	in_file.open(filename);
	if (!in_file)
	{
		cerr << "Error - unable to open input file " << filename << endl;
		exit(1);
	}

	in_file.read((char*) this, sizeof(bank));

	in_file.close();

	selection_sort(objects, elements_filled);


}


/**
 * reads the content of a file and call functions/processes based on the information 
 *       in the content of the file.
 *
 * @filename name of the file to be read
 *    
 * 
 ********************************************************************************/
void bank::process_transactions( const string& filename)
{
	ifstream trans_file;

	char date[5];
	char account_number1[32];
	char type[2];
	double amount;

	trans_file.open(filename);

	if (!trans_file)
	{
		cerr << "Error - unable to open input file " << filename << endl;
		exit(1);
	}


	cout << "Transaction Report" << endl;

	cout << left;

	cout << "Date" << "     " << setw(17) << "Account" << right << setw(5) << " Type"  << right << setw(17) << "Amount" << right << setw(20) << "New Balance" << endl;


	while (trans_file >> date)
	{
		// Read remaining data of the transaction
		trans_file >> account_number1;
		trans_file >> type;
		trans_file >> amount;

		int search_result;

		search_result = bsearch(objects, elements_filled, account_number1);

		if (search_result > 0)
		{
			int result;

			result = strcmp(type, "D");

			if( result == 0)
			{
				objects[search_result].process_deposit(amount);

				cout << date << "     " << left  << setw(17) <<  account_number1 << internal << setw(5) << type << right << fixed << setprecision(2) << setw(17) << amount << right << setw(20) << objects[search_result].account_balance << endl;
			}

			if(result > 0)
			{
				bool withdraw_successful = objects[search_result].process_withdrawal(amount);
				

				if (withdraw_successful)
				{
					cout << date << "     "<< left << setw(17) <<  account_number1 << internal << setw(5) << type << right << fixed << setprecision(2) << setw(17) << amount << right << setw(20) << objects[search_result].account_balance << endl;
				}

				else 
				{
					cout << date << "     " << left << setw(17) << account_number1 << internal << setw(5) << type << right << setw(17) << amount << internal << setw(20) << "   *** Insufficient funds ***" << endl;
				}


			}


		}

		else 
		{
			cout << date << "     " << left << setw(17) << account_number1 << internal << setw(5) << type << right << setw(17) << amount << internal << setw(20) <<  "   *** Invalid account number***" << endl;
		}


	}

	trans_file.close();


}


/**
 * overloaded insertion operator that prints out the contents of an object in an
 *    organized format
 *
 * @param lhs represents the insertion operator 
 * @param bank& rhs a reference to a obecj of the bank class
 *    
 * 
 ********************************************************************************/
ostream& operator<< (ostream& lhs, const bank& rhs)
{
	lhs << "Account Listing for " << rhs.bank_name << endl; 

	for (int i=0; i < rhs.elements_filled; i++)
	{
		cout << rhs.objects[i] << endl;
	}
	
	return lhs;
}
































