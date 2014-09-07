#include "inversematrix.hpp"

#include "function.hpp"
#include "../util.hpp"
#include <string>
#include <sstream>
#include <armadillo>

using namespace std;
using namespace arma;

void InverseMatrix::execute(string command, ostringstream &output)
{
    vector<string> tokens = splitString(command);

    /*
     * 0 - "inversematrix"
     * 1 - name
     */

    string name = tokens[1];

    const_mat_iter map_matrix = matrices.find(name);
    if (map_matrix == matrices.end())
    {
        output << "Matrix '" << name << "'not found!";
    }
    else
    {
        output << "Inverse matrix of '" << name << "':\n";
        output << inv(map_matrix->second);
    }
}
