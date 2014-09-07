/*
 * Heavly influenced by the calculater from the book:
 * Programming: Practice & Principles using c++; Bjarne Stroustrup
 */

// 2+2(3) does not work

#include "calc.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <exception>

using namespace std;

// Just a simple exception class for calculation exceptions
class CalcException : public exception 
{
public:
	CalcException() throw(): errorMsg("Something went wrong!") {}
	CalcException(string error) throw(): errorMsg(error) {}
	~CalcException() throw() {}
	
	const char* what() const throw() { return errorMsg.c_str(); }
private:
	string errorMsg;
};

double string_to_double( const string& s ); //Converts a string to double

double expression(stringstream &ss); // Sets up expression (see the rules)
double term(stringstream &ss); // Sets up a term (see the rules)
double primary(stringstream &ss); // Sets ut a primary (see the rules)

/**************************/

double calculate (string input_expression) 
{
	stringstream ss (input_expression);
	return expression(ss);
}

double expression(stringstream &ss) 
{
	double left = term(ss); // Left side of expression
	while (true) 
	{
		char c = ss.get(); // What kind of expression is this?
		switch(c) 
		{
		case '+':
			left += term(ss);
			break;
		case '-':
			left -= term(ss);
			break;
        default: // End of expression, term or some error
			ss.unget();
			return left;
		}
	}
}

double term(stringstream &ss) 
{
	double left = primary(ss); // Left side of term
	while (true) {
		char c = ss.get(); // What kind of term is this?
		switch(c) 
		{
		case '*':
			left *= primary(ss);
			break;
		case '/':
		{
			double right = primary(ss);
            if (right == 0) throw CalcException("Divided by zero!");
			left /= right;
			break;
		}
		default: // Either some error, bust most probably end of term or just a primary
			ss.unget();
			return left;
			break;
		}
	}
}

double primary(stringstream &ss) 
{
	char c = ss.get();

	if (isdigit(c) || c == '.' || c == '-') 
	{
		string doubleString;
		doubleString += c;

		while (true) 
		{ // Read the rest of the number (if any)
			c = ss.get();
			if (isdigit(c) || c == '.') // Still valid
				doubleString += c;
			else 
			{ // Not valid anymore, finish up
				ss.unget();
				return string_to_double(doubleString);
			}
		}
    }
    else if (c == '(')
    { // new expression
        double expressionValue = expression(ss);
        c = ss.get(); // Get the )
        if (c != ')') throw CalcException("Invalid expression, expected ')'");
        return expressionValue;
    }
    else
	{
		throw CalcException("Invalid expression!");
	}
	
}

/* Converts a given string to a double value and returns it */
double string_to_double( const string& s )
{
	istringstream i(s);
	double x;
	if (!(i >> x)) // Just push i into x
		return 0;
	return x;
} 
