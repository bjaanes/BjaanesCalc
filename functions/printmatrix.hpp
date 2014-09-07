#ifndef PRINTMATRIX_HPP
#define PRINTMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class PrintMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // PRINTMATRIX_HPP
