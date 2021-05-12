//***************************************************************************
//
//  Rectangle.cpp
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "Rectangle.h"
#include <iostream>
#include <string>
using namespace std;


/**
 * Constructor; constructs objects in the rectangle class 
 *
 * @param color2 a string color for encodes the color of the rectangle
 * @param height2 represents the height of the rectangle
 * @param width2 represents the width of the rectangle
 *
 *
 ********************************************************************************/
Rectangle::Rectangle(const string& color2, int height2, int width2) : Shape(color2), height(height2), width(width2)
{

}


/**
 * Overloaded function to print contents of objects in the rectangle class 
 *
 *
 ********************************************************************************/
void Rectangle::print() const
{
	Shape::print();

	cout << "," << " rectangle, " << "height " << height << ", width " << width << endl;
}

/**
 * Calculates the area of the rectangle by multpying the value of width with the value
 *     of the height
 *
 * @return  the area of the rectangle byb multiplying the height and width
 *
 ********************************************************************************/
double Rectangle::get_area() const
{
	double area; 

	area = height * width;

	return area;
}

