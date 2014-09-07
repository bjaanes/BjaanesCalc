#include "addmatrix.hpp"
#include "../util.hpp"
#include <boost/lexical_cast.hpp>
#include <armadillo>

using namespace std;
using namespace boost;
using namespace arma;

void AddMatrix::execute(string command, ostringstream &output)
{
    vector<string> tokens = splitString(command);
    /*
     * 0 - "addmatrix"
     * 1 - name
     * 2 - rows
     * 3 - cols
     */

    string name = tokens[1];
    int rows = lexical_cast<int>(tokens[2]); // These might throw
    int cols = lexical_cast<int>(tokens[3]); // Find a way to deal

    Mat<double> matrix(rows, cols); // Create the new matrix
    matrix.fill(0.0); // Fill it up with zeros

    matrices.insert( pair<string, Mat<double> >(name, matrix) ); // Put it in memory

    // Report back!
    output << "Matrix '" << name << "' (" << rows << ", "
        << cols << ") added.";
}
