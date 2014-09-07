#ifndef FILLMATRIX_HPP
#define FILLMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class FillMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // FILLMATRIX_HPP
