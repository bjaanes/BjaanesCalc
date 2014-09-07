#ifndef DETERMINANTMATRIX_HPP
#define DETERMINANTMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class DeterminantMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // DETERMINANTMATRIX_HPP
