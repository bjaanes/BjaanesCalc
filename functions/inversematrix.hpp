#ifndef INVERSEMATRIX_HPP
#define INVERSEMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class InverseMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // INVERSEMATRIX_HPP
