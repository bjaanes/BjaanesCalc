#include "interpreter.hpp"
#include "functions/function.hpp"
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

/* The interpreter uses a set of rules, found in "rules".
   It uses regular expressions to see if the given command
   is valid. If so, it executes the rules function call and
   let that thing finish the job for it. After the input has 
   been interpreted, the interpreter dosent not care how it goes
*/
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
