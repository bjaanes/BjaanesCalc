#include "printmatrix.hpp"

#include "function.hpp"
#include "../util.hpp"
#include <string>
#include <sstream>

using namespace std;

void PrintMatrix::execute(string command, ostringstream &output)
{
    vector<string> tokens = splitString(command);
    /*
     * 0 - "printmatrix"
     * 1 - name
     */

    string name = tokens[1];

    const_mat_iter map_matrix = matrices.find(name);
    if (map_matrix == matrices.end())  {
        output << "Matrix '" << name << "' not found!";
    }
    else {
        output << map_matrix->second;
    }

    // Not currently used - alternative for outputting the matrix
    /*{ // Traverse the matrix and put it nicly on the output buffer
        for (int row = 0; row < map_matrix->second.n_rows; ++row)
        {
            output << "| "; // "wall"
            for (int col = 0; col < map_matrix->second.n_cols; ++col)
            {
                output << map_matrix->second(row, col) << " ";
            }
            output << "|\n";
        }
    }*/

}
