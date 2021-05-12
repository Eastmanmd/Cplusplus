//***************************************************************************
//
//  Circle.h
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;


class Circle : public Shape
{

private:

	int radius;

public:

	Circle(const string& color2, int radius2);

	void print() const;

	double get_area() const;



};

#endif /* CIRCLE_H */