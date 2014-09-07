#ifndef PRINTMATRICES_HPP
#define PRINTMATRICES_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class PrintMatrices: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // PRINTMATRICES_HPP
