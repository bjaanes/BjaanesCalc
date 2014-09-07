#ifndef EIGENVALUESMATRIX_HPP
#define EIGENVALUESMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class EigenValuesMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // EIGENVALUESMATRIX_HPP
