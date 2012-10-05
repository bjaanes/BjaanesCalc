#include "interpreter.hpp"
#include "rules.hpp"
#include <iostream>
#include <string>

using namespace std;

/* This is the part of the program that reads user input,
sends it to an interpreter for interpretetion and execution
and then shows the output of the actions to the user */
int main() {
	const string prompt = "--> ";
	string input;
	Interpreter interpreter(createRules()); //Interpreter with rules

	while (true) 
	{ // Read, interpret, display:
		ostringstream output(ostringstream::out);
		
		cout << prompt;
		getline(cin, input);

		if (!cin || input == "exit" || input == "quit") break; 

		interpreter.interpret(input, output);
		cout << output.str() << endl; 
	}
}
