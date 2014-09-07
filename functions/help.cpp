#include "help.hpp"
#include "../util.hpp"

using namespace std;

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

    //TODO: This next part could be LESS ugly
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
                break;
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
