#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file." << endl;
        return 0;
    }

    string line;
    int line_number = 1;
    bool inMultiLineComment = false;

    while (getline(file, line)) {
        bool inSingleLineComment = false;

        for (size_t i = 0; i < line.length(); ++i) {
            if (line[i] == '/' && i + 1 < line.length()) {
                if (line[i + 1] == '/' && !inSingleLineComment && !inMultiLineComment) {
                    inSingleLineComment = true;
                    cout << "LineNumber: " << line_number << " (single-line): ";

                } else if (line[i + 1] == '*' && !inSingleLineComment && !inMultiLineComment) {
                    inMultiLineComment = true;
                    cout << "LineNumber: " << line_number << " (Multi-line): ";

                }
            }

            if (inSingleLineComment) {
                cout << line[i];
            }

            if (inMultiLineComment) {
                cout << line[i];

                if (line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                    inMultiLineComment = false;
                    i++;
                    cout <<"/"<< endl;
                }
            }
        }

        if (inSingleLineComment) {
            cout << endl;
            inSingleLineComment = false;
        }

        if (inMultiLineComment) {
            cout << endl;
        }

        line_number++;
    }

    file.close();
    return 0;
}
