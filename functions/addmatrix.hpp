#ifndef ADDMATRIX_HPP
#define ADDMATRIX_HPP

#include "function.hpp"

class AddMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // ADDMATRIX_HPP
