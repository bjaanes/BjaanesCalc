#include "printmatrices.hpp"

#include "function.hpp"
#include "../util.hpp"
#include <string>
#include <sstream>

using namespace std;

void PrintMatrices::execute(string command, ostringstream &output)
{
    // Traverse all matrices in memory and print out their name and size
    for (const_mat_iter iter = matrices.begin(); iter != matrices.end(); ++iter)
    {
        output << iter->second.n_rows << "x" << iter->second.n_cols
             << " matrix named " << iter->first << ".\n";
    }
}
