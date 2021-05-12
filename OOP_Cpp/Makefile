
#
# PROGRAM:    Assignment 8
# PROGRAMMER: Ali Oku
# LOGON ID:   Z1893417
# DATE DUE:   12/02/2020
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
        
# Rule to link object code files to create executable file
main_shapes: main_shapes.o Shape.o Circle.o Triangle.o Rectangle.o
	$(CXX) $(CXXFLAGS) -o assign8 $^

# Rules to compile source code file to object code
main_shapes.o: main_shapes.cpp Shape.h Circle.h Rectangle.h Triangle.h
Shape.o: Shape.cpp Shape.h
Circle.o: Circle.cpp Circle.h
Rectangle.o: Rectangle.cpp Rectangle.h
Triangle.o: Triangle.cpp Triangle.h

Circle.h: Shape.h
Rectangle.h: Shape.h
Triangle.h: Shape.h
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f assign8 *.o