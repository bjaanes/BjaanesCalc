#ifndef HELP_H
#define HELP_H

#include "function.hpp"

class Help: public Function
{
public:
    void execute(std::string command, std::ostringstream &output);
};


#endif // HELP_H
