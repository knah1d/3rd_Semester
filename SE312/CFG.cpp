#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
int pos = 0;

vector<string> leftmostPath;
vector<string> rightmostPath;

bool S();
bool A();
bool B();

bool match(char c) {
    if (pos < input.length() && input[pos] == c) {
        pos++;
        return true;
    }
    return false;
}

void printPath(const vector<string>& path) {
    for (const string& step : path) {
        cout << step << endl;
    }
}

bool S() {
    int initial_pos = pos;
    string derivationStep = "S -> ";
    if (A() && match('1') && B()) {
        derivationStep += "A1B";
        leftmostPath.push_back(derivationStep);
        rightmostPath.push_back(derivationStep);
        return true;
    }
    pos = initial_pos;
    return false;
}

bool A() {
    int initial_pos = pos;
    string derivationStep = "A -> ";
    if (match('0') && A()) {
        derivationStep += "0A";
        leftmostPath.push_back(derivationStep);
        rightmostPath.push_back(derivationStep);
        return true;
    }
    pos = initial_pos;
    derivationStep += "ε";
    leftmostPath.push_back(derivationStep);
    rightmostPath.push_back(derivationStep);
    return true;
}

bool B() {
    int initial_pos = pos;
    string derivationStep = "B -> ";
    if (match('0') && B()) {
        derivationStep += "0B";
        leftmostPath.push_back(derivationStep);
        rightmostPath.push_back(derivationStep);
        return true;
    }
    pos = initial_pos;
    if (match('1') && B()) {
        derivationStep += "1B";
        leftmostPath.push_back(derivationStep);
        rightmostPath.push_back(derivationStep);
        return true;
    }
    pos = initial_pos;
    derivationStep += "ε";
    leftmostPath.push_back(derivationStep);
    rightmostPath.push_back(derivationStep);
    return true;
}

int main() {
    cout << "Enter a string: ";
    cin >> input;

    if (S() && pos == input.length()) {
        cout << "Parsing successful." << endl;
        cout << "Leftmost Derivation:" << endl;
        printPath(leftmostPath);
        cout << "Rightmost Derivation:" << endl;
        printPath(rightmostPath);
    } else {
        cout << "Parsing failed." << endl;
    }

    return 0;
}
