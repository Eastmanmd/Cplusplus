//***************************************************************************
//
//  matrix.cpp
//  CSCI 501 Assignment 6
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Constructor, sets the default components of the matrix to either "1" or "0" 
 *
 *
 ********************************************************************************/
matrix::matrix() //identity matrix constructor 
{
	matrix_array[0][0] = 1;
	matrix_array[0][1] = 0;
	matrix_array[1][0] = 0;
	matrix_array[1][1] = 1;

}


/**
 * Overloaded constructor, sets the components of a matrix to the values of a given matrix
 *
 * @param arr[][] An 2 x 2 array to be copied or ater which the matrix in he class
 *    will be constructed 
 *
 *
 * @note The argument must be a 2 x 2 matrix becasue the private member within the 
 *      class is also a 2 x 2 matrix
 ********************************************************************************/
matrix::matrix(int arr[2][2])
{
	matrix_array[0][0] = arr[0][0];
	matrix_array[0][1] = arr[0][1];
	matrix_array[1][0] = arr[1][0];
	matrix_array[1][1] = arr[1][1];

}



/**
 * calculates the determinant of the array 
 *
 *
 * @return returns the calculated determnant of the matrix  in the class 
 *
 * @note this function is a constant function and should not be able to chnage the 
 *       contents of the object passed 
 ********************************************************************************/
int matrix::determinant() const
{
	int det = (matrix_array[0][0] * matrix_array[1][1]) - (matrix_array[0][1] * matrix_array[1][0]);

	return det;
}



/**
 * Overloaded addition operator, takes the sum of two matrix objects. 
 *
 * @param matrix& rhs takes a reference to an object belonging to the matrix class
 *
 * @return returns an object belonging  to the matrix class.
 *
 * @note this function is a constant function and should not be able to chnage the 
 *       contents of the object passed 
 ********************************************************************************/
matrix matrix::operator+(const matrix& rhs) const //check this 
{
	matrix result;

	result.matrix_array[0][0] = matrix_array[0][0] + rhs.matrix_array[0][0];
	result.matrix_array[0][1] = matrix_array[0][1] + rhs.matrix_array[0][1];
	result.matrix_array[1][0] = matrix_array[1][0] + rhs.matrix_array[1][0];
	result.matrix_array[1][1] = matrix_array[1][1] + rhs.matrix_array[1][1];

	return result;

}


/**
 * Overloaded multiplication operator, mutiplies a matrix object with an integer
 *
 * @param num a integer value 
 *
 * @return returns an onject belonging  to the matrix class. Returns The result of 
 *      multiplying the elements of the matrix left operand by the integer right 
 *      operand (a new matrix object).
 *
 * @note this function is a constant function and should not be able to chnage the 
 *       contents of the object passed 
 ********************************************************************************/
matrix matrix::operator*(int num) const
{
	matrix result;

	result.matrix_array[0][0] = matrix_array[0][0] * num;
	result.matrix_array[0][1] = matrix_array[0][1] * num;
	result.matrix_array[1][0] = matrix_array[1][0] * num;
	result.matrix_array[1][1] = matrix_array[1][1] * num;

	return result;

}



/**
 * Overloaded addition operator, multiplies two matrix objects together
 *
 * @param matrix& rhs takes a reference to an object belonging to the matrix class
 *
 * @return The result of multiplying the elements of the matrix left operand by the 
 *       matrix right operand (a new matrix object).
 *
 * @note this function is a constant function and should not be able to chnage the 
 *       contents of the object passed 
 ********************************************************************************/
matrix matrix::operator*(const matrix& rhs) const // check this 
{
	matrix result;

	result.matrix_array[0][0] = (matrix_array[0][0] * rhs.matrix_array[0][0]) + (matrix_array[0][1] * rhs.matrix_array[1][0]);
	result.matrix_array[0][1] = (matrix_array[0][0] * rhs.matrix_array[0][1]) + (matrix_array[0][1] * rhs.matrix_array[1][1]);
	result.matrix_array[1][0] = (matrix_array[1][0] * rhs.matrix_array[0][0]) + (matrix_array[1][1] * rhs.matrix_array[1][0]);
	result.matrix_array[1][1] = (matrix_array[1][0] * rhs.matrix_array[0][1]) + (matrix_array[1][1] * rhs.matrix_array[1][1]);

	return result;

}




/**
 * Overloaded comparison operator, checks if two matrix objects are equal
 *
 * @param matrix& rhs takes a reference to an object belonging to the matrix class
 *
 * @return true if all elements of the left operand are equal to the 
 *     corresponding elements of the right operand. 
 * @return false if one or all elements of the left operand are not equal to the corresponding
 *      elements of the right operand
 *
 ********************************************************************************/
bool matrix::operator==(const matrix& rhs) const //check this  
{
	if (matrix_array[0][0] == rhs.matrix_array[0][0] && matrix_array[0][1] == rhs.matrix_array[0][1] && matrix_array[1][0] == rhs.matrix_array[1][0] && matrix_array[1][1] == matrix_array[1][1])
		return true;

	else 
		return false;


}


/**
 * Overloaded comparison operator, checks if two matrix objects are equal
 *
 * @param matrix& rhs takes a reference to an object belonging to the matrix class
 *
 * @return false if all elements of the left operand are equal to the 
 *     corresponding elements of the right operand. 
 * @return true if all elements of the left operand are not equal to the corresponding
 *      elements of the right operand
 *
 ********************************************************************************/
bool matrix::operator!=(const matrix& rhs) const //check this 
{
	if (matrix_array[0][0] == rhs.matrix_array[0][0] && matrix_array[0][1] == rhs.matrix_array[0][1] && matrix_array[1][0] == rhs.matrix_array[1][0] && matrix_array[1][1] == matrix_array[1][1])
		return false;

	else 
		return true;

}


/**
 * Overloaded insertion operator, prints out the content of a matrix object in a 
 *      formatted style. 
 *
 * @param lhs reference to the object belonging to the ostream class
 * @param matrix& rhs takes a reference to an object belonging to the matrix class
 *     the right hand operand.
 *
 * @return lhs (peints the contents of the object passed to it )
 *
 ********************************************************************************/
ostream& operator<< (ostream& lhs, const matrix& rhs)
{
	lhs << "[[" << rhs.matrix_array[0][0] << ", " << rhs.matrix_array[0][1] << "]," << " [" << rhs.matrix_array[1][0] << ", " << rhs.matrix_array[1][1] << "]]" ;

	return lhs;

}



/**
 * Overloaded multiplication operator, mutiplies a matrix object with an integer
 *
 * @param num a integer value 
 * @param matrix& rhs takes a reference to an object belonging to the matrix class
 *     the right hand operand.
 *
 * @return  the result of multiplying the elements of the matrix (left operand) 
 *     by an integer (right operand)
 *
 * @note this function is a constant function and should not be able to chnage the 
 *       contents of the object passed 
 ********************************************************************************/
matrix operator*(int num, const matrix& rhs)
{
	matrix result;

	result.matrix_array[0][0] = num * rhs.matrix_array[0][0];
	result.matrix_array[0][1] = num * rhs.matrix_array[0][1];
	result.matrix_array[1][0] = num * rhs.matrix_array[1][0];
	result.matrix_array[1][1] = num * rhs.matrix_array[1][1];

	return result;

}

