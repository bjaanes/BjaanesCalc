/*
 * Heavly influenced by the calculater from the book:
 * Programming: Practice & Principles using c++; Bjarne Stroustrup
 */

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
		default: // Either some error, but most probably end of expression or just a term
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
			if (right == 0) throw CalcException("Divided by zero!"); // plz
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

	// UGLY FUCKING CODE!
	if (isdigit(c) || c == '.' || c == '-') 
	{ // This ought to be a number!
		string doubleString; // To store our number in
		doubleString += c; 
		while (true) 
		{ // Read the rest of the number (if any)
			c = ss.get();
			if (isdigit(c) || c == '.') // Still valid, add it
				doubleString += c;
			else 
			{ // Not? Then were done for now
				ss.unget();
				return string_to_double(doubleString);
			}
		}
	} else if (c == '(')
	{ // uuuh, a new expression we got?
		double d = expression(ss);
		c = ss.get();
	} else 
	{ // Fuuuuuuuuuu
		throw CalcException("Invalid expression!");
	}
	
}

double string_to_double( const string& s )
{
	istringstream i(s);
	double x;
	if (!(i >> x)) // Just push i into x like a baws
		return 0;
	return x;
} 
