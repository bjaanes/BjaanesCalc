#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <armadillo>

/* A virtual function meant to be used for polymorphism so that 
we can create a bunch of function classes that executes different
commands in different ways */
class Function 
{
public:
	// Takes a command, executes and returns an appropriate ouput (errors also):
	virtual void execute(std::string command, std::ostringstream &output) = 0;

    // Accessible for all inhereted classes
	static std::map<std::string, arma::Mat<double> > matrices;
};

#endif
