#include "editmatrix.hpp"

#include "../util.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

void EditMatrix::execute(string command, ostringstream &output)
{
    vector<string> tokens = splitString(command);
    /*
     * 0 - "editmatrix"
     * 1 - name
     * [2, ?] - value to be set - can be all or just one of the values
     * If the value is 'x' that means we should not change the value
     */

    string name = tokens[1];

    vector<string> value_tokens(tokens.size()-2); // Just the values
    vector<string>::iterator value_iter = value_tokens.begin();

    copy( (tokens.begin()+2), tokens.end(), value_iter ); // Copy the values

    mat_iter map_matrix = matrices.find(name);
    if (map_matrix == matrices.end())
    {
        output << "Matrix '" << name << "' not found!";
        return;
    }

    // Traverse the matrix row first
    for (int row = 0; row < map_matrix->second.n_rows; ++row)
    {
        for (int col = 0; col < map_matrix->second.n_cols; ++col)
        {
            if (*value_iter != "x")
            { // If this value should be changed, we change it!
                map_matrix->second(row, col)
                  = lexical_cast<double>(*value_iter);
                output << "Row " << row << " Col " <<
                  col << " changed to " << *value_iter << "\n";
            }

            ++value_iter;
            if (value_iter == value_tokens.end()) return; // Done!
        }
    }

}
