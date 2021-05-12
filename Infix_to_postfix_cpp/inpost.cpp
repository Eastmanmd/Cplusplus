//***************************************************************************
//
//  inpost.cpp
//  CSCI 501 Assignment 7
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "inpost.h"
#include "mystack.h"
#include <iostream>
#include <cstddef>
#include <cctype>
#include <string>

using namespace std;


/**
 * Assigns an int value to rank operators using following mathematical order of 
 *     operations  
 *
 * @param operator Takes in a mathematical operator in a character format 
 *
 * @return The int value ranking the operator fro -1 to 3. 
 *
 * @note A higher return value means that the operator has higher precedence/ priority 
 ********************************************************************************/
int precedence_calc ( char operators)
{
	int result; //stores the result of the switch statement 

	switch(operators) //prioritizes the operators following the accepted mathematical order of operations
	{
		case '~':
		{
			result = 3;
			break;
		}

		case '^':
		{
			result = 3;
			break;
		}

		case '*':
		{
			result = 2;
			break;
		}

		case '/':
		{
			result = 2;
			break;
		}

		case '+':
		{
			result = 1;
			break;
		}

		case '-':
		{
			result = 1;
			break;
		}

		case '(':
		{
			result = -1;
		}

		default:
		{
			result = -1;
		}

	}

	return result;
}

/**
 * Converts a given string containing an operation in infix formats and 
 *      converts this to postfix format 
 *
 * @param infix A reference to a string containing an operation in infix format
 *
 * @return a string containing the converted operatio in postfix format
 *
 ********************************************************************************/
string convert(const string& infix)
{
	mystack opstack; //holds operators during conversion

	string postfix; //holds postfix output

	int len = infix.length(); // calculates the lenght of input string 


	for (int i = 0; i < len; i++)
	{
		if (!isspace(infix[i])) // ignores blank spaces during postfix convsersion 
		{
			if (isdigit(infix[i]))  //reads in digits
			{
				postfix += infix[i];

			}

			else if (islower(infix[i])) //takes in alpha characters, only reads in valid lowercase alpha characters 
			{
				postfix += infix[i];
	
			}

			else if (infix[i] == '(') //reads in forward parenthesis 
			{
				opstack.push(infix[i]);
			}

			else if (infix[i] == ')') 
			{

				while (opstack.top() != '(')
				{
					char top_char;

					top_char = opstack.top();

					postfix += ' ';
					postfix += top_char;


					opstack.pop();

				}

				opstack.pop(); //added this to get rid of the forward parenthesis prinintg 

			}

			else
			{
				if (postfix.back() != ' ')
				{
					postfix += ' '; //ensures that operands and operators are separated by a space
				}
				
				if (!opstack.empty())
				{
					
					while (!opstack.empty() && precedence_calc(opstack.top()) >= precedence_calc(infix[i]) ) //compares the order of operation given two operators
				
					{

						char top_char2;

						top_char2 = opstack.top();

						postfix += top_char2;

						postfix += ' ';

						opstack.pop();
					}

					opstack.push(infix[i]);
				}

				else 
				{
					opstack.push(infix[i]); //adds the operator string if the stack is empty
				}
			}
		}
	}

	while (!opstack.empty()) // empties the remaining contents of the opstack 
	{
		char top_char3;
		top_char3 = opstack.top();

		postfix += ' ';

		postfix += top_char3;
		

		opstack.pop();
	}

	if (postfix[0] == ' ') //removes leading blank spaces (if any) from the postfix string 
	{
		postfix = postfix.erase(0,1);
	}

	return postfix;
	
}
