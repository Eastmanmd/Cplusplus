//***************************************************************************
//
//  Triangle.cpp
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "Triangle.h"
#include <iostream>
#include <string>
using namespace std;


/**
 * Constructor; constructs objects in the triangle class 
 *
 * @param color2 a string color for encodes the color of the triangle
 * @param height2 represents the height of the triangle
 * @param base2 represents the base of the rectangle
 *
 *
 ********************************************************************************/
Triangle::Triangle(const string& color2, int height2, int base2) : Shape(color2), height(height2), base(base2)
{

}


/**
 * Overloaded function to print contents of objects in the triangle class 
 *
 *
 ********************************************************************************/
void Triangle::print() const
{
	Shape::print();

	cout << "," << " triangle, " << "height " << height << ", base " << base << endl;
}


/**
 * Calculates the area of the tringle by multpying the value of the base with the value
 *     of the height and diving the result by 2
 *
 * @return  the area of the triangle using the base and the height 
 *
 ********************************************************************************/
double Triangle::get_area() const
{
	double area; 

	area = 0.5 * base * height;

	return area;
}

