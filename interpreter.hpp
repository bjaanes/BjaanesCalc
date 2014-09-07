#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "functions/function.hpp"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <boost/regex.hpp>

/* The interpreter uses a set of rules to interpret command, 
   call function related to the command and give back some
   output in a stringstream. Often the answer to a problem
*/

class Interpreter 
{
public:
    Interpreter(std::map<boost::regex, Function*> custom_rules) : rules(custom_rules) {}

	void interpret(std::string input, std::ostringstream &output); // Should not throw anything

private:
	std::map<boost::regex, Function*> rules;
};

#endif
