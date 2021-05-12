//***************************************************************************
//
//  main.cpp
//  CSCI 501 Assignment 8
//
//  Created by Ali Oku (z1893417)
//
//***************************************************************************

#include <iostream>
#include <string>
using namespace std;

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main()
{



	Shape* objects[6];

	Shape *circle1 = new Circle( "green", 10); // constructs the first circle
	objects[0] = circle1; //adds the pointer to the circle to the pointer array

	Shape *rectanlge1 = new Rectangle("red", 8, 6); //constructs the first rectangle
	objects[1] = rectanlge1; //adds the pointer to the rectangle to the pointer array

	Shape *triangle1 = new Triangle("yellow", 8, 4); //constructs the first triangle 
	objects[2] = triangle1; //adds the pointer to the triangle to the pointer array

	Shape *traingle2 = new Triangle("black", 4, 10); // constructs the second triangle
	objects[3] = traingle2; //adds the pointer to the triangle to the pointer array

	Shape *circle2 = new Circle("orange", 5); //constructs the second circle
	objects[4] = circle2; //adds the pointer to the circle to the pointer array

	Shape *rectanlge2 = new Rectangle ("blue", 3, 7); //constructs the second circle
	objects[5] = rectanlge2; //adds the pointer to the rectangle to the pointer array

	cout << "Printing all shapes..." << endl;
	cout << endl;


	for (int i = 0; i < 6; i++) //prints all the shapes in the array
	{
		objects[i]->print(); 
	}

	cout << endl;
	cout << "Printing only circles..." << endl;
	cout << endl;


	//to print only circles
	for (int i = 0; i < 6; i++)
	{
		if (dynamic_cast<Circle*>(objects[i]) != nullptr)
		{
			objects[i]->print();
		}
	}

	//delete all the contents in the array

	for (int i = 0; i < 6; i++)
	{
		delete objects[i];
	}


	return 0;





}