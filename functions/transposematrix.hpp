#ifndef TRANSPOSEMATRIX_HPP
#define TRANSPOSEMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class TransposeMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // TRANSPOSEMATRIX_HPP
