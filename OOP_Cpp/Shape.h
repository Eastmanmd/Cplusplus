//***************************************************************************
//
//  Shape.h
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:

	string color;

public:

	Shape(const string&); //incomplete

	virtual ~Shape(); //destrcutor 

	virtual void print () const; 

	virtual double get_area() const = 0; //pure virtual function 



};

#endif /* SHAPE_H */