#include "calculate.hpp"
#include "../util.hpp"
#include "../calc.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;

void Calculate::execute(string command, ostringstream &output)
{
    vector<string> tokens = splitString(command);
    /*
     * 0 - "calc"
     * 1 - expression
     */
    try
    {
        double result = calculate(tokens[1]);
        output << tokens[1] << "=" << result;
    }
    catch (std::exception &ex)
    {
        output << "Error! " << ex.what();
    }

}
