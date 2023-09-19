#include <iostream>

using namespace std;

// DFA transition table
char transitions[8][2] = {
    {'B', 'A'},
    {'A', 'C'},
    {'D', 'B'},
    {'D', 'A'},
    {'D', 'F'},
    {'F', 'G'},
    {'G', 'F'},
    {'G', 'D'}
};

// Mark final states
bool isFinal[8] = {false, false, false, true, false, false, false, false};

// Function to initialize distinguishabilities table
void initializeDistinguishabilities(bool table[8][8]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // States with different final state status are distinguishable
            if (isFinal[i] != isFinal[j]) {
                table[i][j] = true;
            }
        }
    }
}

// Function to check if two states are distinguishable based on transitions
bool areDistinguishable(char state1, char state2, bool table[8][8]) {
    for (char c = '0'; c <= '1'; ++c) {
        int nextState1 = state1 - 'A';
        int nextState2 = state2 - 'A';
        nextState1 = transitions[nextState1][c - '0'] - 'A';
        nextState2 = transitions[nextState2][c - '0'] - 'A';
        if (table[nextState1][nextState2]) {
            return true;
        }
    }
    return false;
}

// Function to apply the table-filling algorithm
void tableFillingAlgorithm(bool table[8][8]) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 1; i < 8; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!table[i][j]) {
                    bool isDistinguishable = areDistinguishable('A' + i, 'A' + j, table);
                    if (isDistinguishable) {
                        table[i][j] = true;
                        changed = true;
                    }
                }
            }
        }
    }
}

// Function to print the distinguishabilities table
void printDistinguishabilities(const bool table[8][8]) {
    cout << "Distinguishabilities Table:" << endl;
    for (int j = 0; j < 7; ++j) {
        for (int i = 1; i < 8; ++i) {
            if (i == j) {
                cout << 'X' << ' ';
            } else {
                cout << (table[i][j] ? 'X' : ' ') << ' ';
            }
        }
        cout << endl;
    }
}


int main() {
    bool distinguishabilities[8][8] = {0};

    // Step 1: Initialize distinguishabilities table
    initializeDistinguishabilities(distinguishabilities);

    // Step 2: Apply the table-filling algorithm
    tableFillingAlgorithm(distinguishabilities);

    // Step 3: Print the distinguishabilities table
    printDistinguishabilities(distinguishabilities);

    return 0;
}
