#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

void readLogAndAddToHastable(string log, regex pattern);

string findFilenameInLine(string line, regex search_pattern);

int main()
{
    // server_log_name then will be changed as access_log
    string server_log_name = "access_log.txt";
    regex pattern("\\w+\\.[a-z]+");
    readLogAndAddToHastable(server_log_name, pattern);

    return 0;
}

// this function should take one more parameter - last parameter will be a hashtabletype - it will be implemented later.
void readLogAndAddToHastable(string log, regex pattern) {
    fstream server_log;
    server_log.open(log, ios::in);

    if (!server_log.is_open()) {
        cerr << "Unable to open the file." << endl;
    }
    else {

        string line;
        while (getline(server_log, line)) {


            string filename = findFilenameInLine(line, pattern);
            cout << filename << endl; // this line will be deleted later.

            // filename then will be added to the hashtable
        }
        server_log.close();
    }
}

string findFilenameInLine(string line, regex search_pattern) {
    smatch match;
    regex_search(line, match, search_pattern);

    return match[0];
}