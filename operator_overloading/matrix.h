//***************************************************************************
//
//  matrix.h
//  CSCI 501 Assignment 6
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#ifndef MATRIX_H 
#define MATRIX_H

#include <iostream>
using namespace std;

class matrix
{
private:

	int matrix_array[2][2]; //two dimensional array (2 rows and 2 columns)

public:

	matrix(); //indentity matrix constructor 

	matrix(int arr[2][2]);  //Array initialization constructor 

	int determinant() const;

	matrix operator+(const matrix& rhs) const;

	matrix operator*(int num) const;

	matrix operator*(const matrix& rhs) const;

	bool operator==(const matrix& rhs) const; //check this 

	bool operator!=(const matrix& rhs) const; //check this 

	friend ostream& operator<< (ostream& lhs, const matrix& rhs);

	friend matrix operator*(int num, const matrix& rhs);




};




#endif /* MATRIX_H */