#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <map>
#include <armadillo>

typedef std::map<std::string, arma::Mat<double> >::const_iterator const_mat_iter;
typedef std::map<std::string, arma::Mat<double> >::iterator mat_iter;

std::vector<std::string> splitString(std::string input);

#endif // UTIL_H
