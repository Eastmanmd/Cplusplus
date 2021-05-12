//***************************************************************************
//
//  Shape.cpp
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Default constructor for the Shape class
 *
 * @param color2 takes in a string with the color of the shape 
 *
 *
 * @note this is an abstract class so this constructor will only be invoked by
 *       a derived-class constructor 
 ********************************************************************************/
Shape::Shape(const string& color2)
{
	color = color2;

}


/**
 * Destructor for the Shape class
 *
 *
 *
 * @note this is a virtual function
 ********************************************************************************/
Shape::~Shape()
{

}

/**
 * Prints out contents in the Shape class
 *
 *
 * @note this is a virtual function
 ********************************************************************************/
void Shape::print() const
{
	cout << color << " " << "[" << "area " << get_area() << "]";
}






