#include "util.hpp"
#include <sstream>

using namespace std;

vector<string> splitString(string input)
{
    vector<string> tokens;
    stringstream ss (input);
    string token;

    while (getline(ss, token, ' '))
        tokens.push_back(token);

    return tokens;
}
