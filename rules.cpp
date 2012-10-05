#include "rules.hpp"
#include "function.hpp"
#include "function_objects.hpp"
#include <map>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

/* Explain! */
map<regex, Function*> createRules() {
	map<regex, Function*> rules;

	// Displays some help
	rules.insert( pair<regex, Function*>(
		regex("^(([h][e][l][p])|([h]))(\\s\\w+)?$"),
		new Help()
		));

	// Calculate normal math expression
	rules.insert( pair<regex, Function*>(
		regex("^(([c][a][l][c])|([c]))\\s[(\\-?\\d(.\\d)?)\\w\\+\\-\\*\\/]+$"),
		new Calculate()
		));
	
	// Add matrix
	rules.insert( pair<regex, Function*>(
		regex("^(([a][d][d][m][a][t][r][i][x])|([a][m]))\\s\\w+\\s\\d+\\s\\d$"),
		new AddMatrix()
		));

	// Print matrix
	rules.insert( pair<regex, Function*>(
		regex("^(([p][r][i][n][t][m][a][t][r][i][x])|([p][m]))\\s\\w+$"),
		new PrintMatrix()
		));
	// Fill matrix with a value
	rules.insert( pair<regex, Function*>(
		regex("^(([f][i][l][l][m][a][t][r][i][x])|([f][m]))\\s\\w+\\s\\-?\\d+(.\\d+)?$"),
		new FillMatrix()
		));

	// Edit matrix row first
	rules.insert( pair<regex, Function*>(
		regex("^(([e][d][i][t][m][a][t][r][i][x])|([e][m]))\\s\\w+\\s((\\-?\\d+(.\\d+)?)|([x]))((\\s\\-?\\d+(.\\d+)?)|(\\s[x]))*$"),
		new EditMatrix()
		));

	// Get determinant of matrix
	rules.insert( pair<regex, Function*>(
		regex("^(([d][e][t][m][a][t][r][i][x])|([d][m]))\\s\\w+$"),
		new DeterminantMatrix()
		));

	// Get eigenvalues of a matrix
	rules.insert( pair<regex, Function*>(
		regex("(([e][i][g][e][n][v][a][l][m][a][t][r][i][x])|([e][v][l][m]))\\s\\w+$"),
		new EigenValuesMatrix()
		));
	// Get eigenvectors of a matrix
	rules.insert( pair<regex, Function*>(
		regex("(([e][i][g][e][n][v][e][c][m][a][t][r][i][x])|([e][v][c][m]))\\s\\w+$"),
		new EigenVectorsMatrix()
		));

	// Print matrices in memory
	rules.insert( pair<regex, Function*>(
		regex("^([p][r][i][n][t][m][a][t][r][i][c][e][s])|([p][m][s])$"),
		new PrintMatrices()
		));

	rules.insert( pair<regex, Function*>(
		regex("^(([i][n][v][e][r][s][e][m][a][t][r][i][x])|([i][m]))\\s\\w+$"),
		new InverseMatrix()
		));

	rules.insert( pair<regex, Function*>(
		regex("^(([t][r][a][n][s][p][o][s][e][m][a][t][r][i][x])|([t][m]))\\s\\w+$"),
		new TransposeMatrix()
		));
	return rules;
}
