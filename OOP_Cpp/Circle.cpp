//***************************************************************************
//
//  Circle.cpp
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "Circle.h"
#include <iostream>
#include <string>
using namespace std;



/**
 * Constructor; constructs objects in the Circle class 
 *
 * @param color2 a string color for encodes the color of the circle object
 * @param radius  encodes the radius of the circle 
 *
 *
 ********************************************************************************/
Circle::Circle(const string& color2, int radius2) : Shape(color2), radius(radius2)
{

}


/**
 * Overloaded function to print contents of the Circle 
 *
 *
 ********************************************************************************/
void Circle::print() const
{
	Shape::print();

	cout << "," << " circle," << " radius " << radius << endl;

}

/**
 * Calculates the area of a circle by multpying the value of pi with the square 
 *     of the radius
 *
 * @return  the area of the circle using the value of pi and the radius 
 *
 ********************************************************************************/
double Circle::get_area() const
{
	double area;

	area = 3.14159265358979323846 * radius * radius;

	return area;
}
