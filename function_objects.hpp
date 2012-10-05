#ifndef FUNCTION_OBJECTS_HPP
#define FUNCTION_OBJECTS_HPP

#include "function.hpp"
#include <string>
#include <iostream>
#include <sstream>

/* Each class is to be used with polymorphism.
Each class performs one function and expects a very specific
command to function properly.

Not tested without proper ruling - see rules.[hpp][cpp] */

class Help: public Function
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class Calculate: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class AddMatrix: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class PrintMatrix: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class FillMatrix: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class EditMatrix: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class PrintMatrices: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class DeterminantMatrix: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class EigenValuesMatrix: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class EigenVectorsMatrix: public Function 
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class InverseMatrix: public Function
{
public:
	void execute(std::string command, std::ostringstream &output);
};

class TransposeMatrix: public Function
{
public:
	void execute(std::string command, std::ostringstream &output);
};
#endif
