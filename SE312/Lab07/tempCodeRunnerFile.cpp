#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if a line is a single-line comment
bool isSingleLineComment(const string& line) {
    size_t pos = line.find("//");
    return (pos != string::npos);
}

// Function to check if a line is part of a multi-line comment
bool isInMultiLineComment(const string& line, bool& inComment) {
    size_t start = line.find("/*");
    size_t end = line.find("*/");

    if (start != string::npos && end != string::npos && start < end) {
        inComment = false;
        return false;
    }

    if (start != string::npos) {
        inComment = true;
    }

    if (inComment || end != string::npos) {
        return true;
    }

    return false;
}

int main() {
    ifstream inputFile("test_code.c"); // Replace with the path to your C file
    string line;
    int lineNumber = 0;
    bool inMultiLineComment = false;

    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        lineNumber++;

        if (isInMultiLineComment(line, inMultiLineComment)) {
            cout << "LineNumber " << lineNumber << ": " << line << endl;
        } else if (isSingleLineComment(line)) {
            cout << "LineNumber " << lineNumber << ": " << line << endl;
        }
    }

    inputFile.close();
    return 0;
}
