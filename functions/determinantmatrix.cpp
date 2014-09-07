#include "determinantmatrix.hpp"

#include <string>
#include <sstream>
#include <vector>
#include "../util.hpp"

using namespace std;

void DeterminantMatrix::execute(string command, ostringstream &output)
{
    // Find the determinant of a matrix
    vector<string> tokens = splitString(command);
    /*
     * 0 - "detmatrix"
     * 1 - name
     */

    string name = tokens[1];

    const_mat_iter map_matrix = matrices.find(name);
    if (map_matrix == matrices.end())
    {
        output << "Matrix '" << name << "' not found!";
    }
    else
    {
        output << "Matrix '" << name << "' determinant: " << det(map_matrix->second);
    }
}
