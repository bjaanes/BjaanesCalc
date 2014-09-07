#include "eigenvectorsmatrix.hpp"

#include "function.hpp"
#include "../util.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <armadillo>

using namespace std;
using namespace arma;

void EigenVectorsMatrix::execute(string command, ostringstream &output)
{
    // Find the eigenvectors of a matrix
    vector<string> tokens = splitString(command);
    /*
     * 0 - "eigenvecmatrix"
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

        for (unsigned int col = 0; col < eigvec.n_cols; ++col)
        {
            output << "V_" << col << "=\n";
            output << eigvec.col(col) << "\n";
        }
        //output << eigvec;
        /*for (int row = 0; row < eigvec.n_rows; ++row)
        {
            for (int col = 0; col < eigvec.n_cols; ++col)
            {
                if (row == 0) output << "v" << col+1 << "=";
                else output << "  ";
                output << "|" << eigvec(row, col) << "|";
            }
            output << "\n";
        }*/
    }
}
