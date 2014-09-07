#ifndef EIGENVECTORSMATRIX_HPP
#define EIGENVECTORSMATRIX_HPP

#include "function.hpp"
#include <string>
#include <sstream>

class EigenVectorsMatrix: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};

#endif // EIGENVECTORSMATRIX_HPP
