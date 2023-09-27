#include <iostream>
#include <string>

using namespace std;

bool parseP(string input, int &index) {
    if (index == input.length()) {
        // Derivation successful
        return true;
    }

    if (input[index] == '0') {
        cout << "P -> 0" << endl;
        index++;
        return true;
    } else if (input[index] == '1') {
        cout << "P -> 1" << endl;
        index++;
        if (parseP(input, index)) {
            cout << "P -> 1P1" << endl;
            if (input[index] == '1') {
                index++;
                return true;
            }
        }
    }

    return false; // If none of the rules can be applied
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int index = 0;
    if (parseP(input, index) && index == input.length()) {
        cout << "Derivation successful" << endl;
    } else {
        cout << "Not in this grammar" << endl;
    }

    return 0;
}
