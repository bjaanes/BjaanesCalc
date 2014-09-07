#include "transposematrix.hpp"

#include "function.hpp"
#include "../util.hpp"
#include <string>
#include <sstream>
#include <armadillo>

using namespace std;
using namespace arma;

void TransposeMatrix::execute(string command, ostringstream &output)
{
    vector<string> tokens = splitString(command);

    /*
     * 0 - "transposematrix"
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
        output << "Transpose matrix of '" << name << "':\n";
        output << trans(map_matrix->second);
    }
}

