#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    regex singleLineRegex("//.*");
    regex multiLineRegex("/\\*.*?\\*/");

    int line_number = 1;

    while (getline(file, line)) {
        smatch match;
        if (regex_search(line, match, singleLineRegex)) {
            cout << "LineNumber: " << line_number << "(single-line): " << match.str() << endl;
        }

        while (regex_search(line, match, multiLineRegex)) {
            cout << "LineNumber: " << line_number << "(Multi-line): " << match.str() << endl;
            line = match.suffix();
        }

        line_number++;
    }

    file.close();
    return 0;
}
