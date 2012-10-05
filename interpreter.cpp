#include "interpreter.hpp"
#include "function.hpp"
#include "function_objects.hpp"
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

/* Explain how this works */
void Interpreter::interpret(string input, ostringstream &output) 
{
	for (map<regex, Function*>::const_iterator iter = rules.begin();
		 iter != rules.end(); ++iter) 
	{
		if (regex_match(input, iter->first))
			return iter->second->execute(input, output);
	}

	output << "'" << input << "' - not a valid command.";
}
