#include "fillmatrix.hpp"

#include "../util.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

void FillMatrix::execute(string command, ostringstream &output)
{
    vector<string> tokens = splitString(command);
    /*
     * 0 - "fillmatrix"
     * 1 - name
     * 2 - fillvalue
     */

    string name = tokens[1];
    double val	= lexical_cast<double>(tokens[2]); //Might just throw!

    mat_iter map_matrix = matrices.find(name);
    if (map_matrix == matrices.end())
    {
        output << "Matrix '" << name << "' not found!";
    }
    else
    { // Fill it up!
        map_matrix->second.fill(val);
        output << "Matrix '" << name << "' filled with " << val << ".";
    }

}
