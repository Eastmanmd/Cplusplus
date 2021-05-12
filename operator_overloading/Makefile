#
# PROGRAM:   assign6
# AUTHOR:    name
# LOGON ID:  z-ID
# DUE DATE:  2/27/2020
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

all: assign6

# Rule to link object code files to create executable file
assign6: main.o matrix.o
	$(CXX) $(CCFLAGS) -o assign6 $^

# Rules to compile source code files to object code
main.o: main.cpp matrix.h
matrix.o: matrix.cpp matrix.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign6 *.o

world: clean all