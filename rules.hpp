#ifndef RULES_HPP
#define RULES_HPP

#include "functions/function.hpp"
#include <map>
#include <boost/regex.hpp>

std::map<boost::regex, Function*> createRules(); // Creat a rule map

#endif
