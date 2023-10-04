#include <iostream>
#include <string>
using namespace std;

string input;
int pos = 0;

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

bool S() {
    int initial_pos = pos;
    cout << "S => ";
    if (A() && match('1') && B()) {
        cout << "A1B";
        return true;
    }
    pos = initial_pos;
    return false;
}

bool A() {
    int initial_pos = pos;
    cout << "A => ";
    if (match('0') && A()) {
        cout << "0A";
        return true;
    }
    pos = initial_pos;
    cout << "ε";
    return true;
}

bool B() {
    int initial_pos = pos;
    cout << "B => ";
    if (match('0') && B()) {
        cout << "0B";
        return true;
    }
    pos = initial_pos;
    if (match('1') && B()) {
        cout << "1B";
        return true;
    }
    pos = initial_pos;
    cout << "ε";
    return true;
}

void LeftmostDerivation() {
    cout << "Leftmost: ";
    pos = 0;
    S();
    cout << endl;
}

void RightmostDerivation() {
    cout << "Rightmost: ";
    pos = 0;
    S();
    cout << endl;
}

int main() {
    cout << "Enter a string: ";
    cin >> input;

    LeftmostDerivation();
    RightmostDerivation();

    return 0;
}
