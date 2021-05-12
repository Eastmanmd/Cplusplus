//***************************************************************************
//
//  Triangle.h
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Triangle : public Shape
{

private:

	int height;
	int base;

public:

	Triangle(const string& color2, int height2, int base2);

	void print() const;

	double get_area() const;

};

#endif /* TRIANGLE_H */