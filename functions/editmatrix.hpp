#ifndef EDITMATRIX_HPP
#define EDITMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class EditMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // EDITMATRIX_HPP
