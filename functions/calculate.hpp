#ifndef CALCULATE_HPP
#define CALCULATE_HPP

#include "function.hpp"
#include <sstream>
#include <string>

class Calculate: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // CALCULATE_HPP
