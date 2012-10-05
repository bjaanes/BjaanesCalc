#include "function_objects.hpp"
#include "calc.hpp"
#include "function.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <armadillo>
#include <map>
#include <algorithm>
#include <exception>
#include <complex>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;
using namespace arma;

typedef map<string, Mat<double> >::const_iterator const_mat_iter;
typedef map<string, Mat<double> >::iterator mat_iter;

vector<string> splitString(string input);

void Help::execute(string command, ostringstream &output)
{
	vector<string> tokens = splitString(command);
	/*
	 * 0 - "help"
	 * 1 - optional: command
	 */
	ifstream helpfile ("help.txt");
	string line;

	if (!helpfile.is_open())
	{
		output << "Unable to open help file (help.txt)";
		return;
	}

	// This next part could be LESS ugly
	if (tokens.size() == 2) { // There is specified a topic
		string topic = tokens[1];
		while (helpfile.good()) {
			getline (helpfile, line);

			if (line == ":")
			{
				getline (helpfile, line);
				vector<string> commands = splitString(line);
				for (int i = 0; i < commands.size(); ++i)
				{
					if (commands[i] == topic)
					{
						getline (helpfile, line);
						while (line != "---")
						{
							output << line << "\n";
							getline(helpfile,line);
						}
						break;
					}
				}
			}
		}
	}
	else // General help
	{
		while (helpfile.good())
		{
			getline (helpfile, line);
			if (line[0] == '[')
			{
				output.setf(ios_base::left);
				output.width(25);
				output << line << ":\t"; // Function name
				
				getline (helpfile, line); // OK, we need the next line!
				output << line << "\n"; // Function command
			}
		}
		output << "To see more info about a specific topic, use: \"help topic\"";
	}

	helpfile.close();
}

void Calculate::execute(string command, ostringstream &output) 
{
	vector<string> tokens = splitString(command);
	/*
	 * 0 - "calc"
	 * 1 - expression
	 */
	try 
	{
		double result = calculate(tokens[1]);
		output << tokens[1] << "=" << result;
	} 
	catch (std::exception &ex) 
	{
		output << "Error! " << ex.what();
	}

}

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

void PrintMatrix::execute(string command, ostringstream &output) 
{
	vector<string> tokens = splitString(command);
	/*
	 * 0 - "printmatrix"
	 * 1 - name
	 */

	string name = tokens[1];

	const_mat_iter map_matrix = matrices.find(name);
	if (map_matrix == matrices.end()) 
	{
		output << "Matrix '" << name << "' not found!";
	} 
	else { output << map_matrix->second; }
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

void PrintMatrices::execute(string command, ostringstream &output) 
{
	// Traverse all matrices in memory and print out their name and size
	for (const_mat_iter iter = matrices.begin(); iter != matrices.end(); ++iter) 
	{
		output << iter->second.n_rows << "x" << iter->second.n_cols 
			 << " matrix named " << iter->first << ".\n";
	}
}

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

		for (int col = 0; col < eigvec.n_cols; ++col)
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

vector<string> splitString(string input) 
{
	vector<string> tokens;
	stringstream ss (input);
	string token;

	while (getline(ss, token, ' '))
		tokens.push_back(token);

	return tokens;
}
