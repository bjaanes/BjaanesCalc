#include "eigenvaluesmatrix.hpp"

#include "function.hpp"
#include "../util.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <armadillo>

using namespace std;
using namespace arma;

void EigenValuesMatrix::execute(string command, ostringstream &output)
{
    // Find the eigenvalues of a matrix
    vector<string> tokens = splitString(command);
    /*
     * 0 - "eigenvalmatrix"
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
        cx_vec eigval;
        cx_mat eigvec;

        eig_gen(eigval, eigvec, map_matrix->second);
        output << eigval;
        /*for (cx_vec::const_iterator iter = eigval.begin();
            iter != eigval.end(); ++iter)
        {
            output << *iter << "\n";
        }*/
    }
}
