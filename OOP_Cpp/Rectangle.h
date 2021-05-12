//***************************************************************************
//
//  Rectangle.h
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Rectangle : public Shape
{

private:

	int height;
	int width;

public:

	Rectangle(const string& color2, int height2, int width2);

	void print() const;

	double get_area() const;

};

#endif /* RECTANGLE_H */