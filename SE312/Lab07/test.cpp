#include <iostream>
#include <vector>
#include <string>
using namespace std;

void applyProduction(string& derivation, const string& left, const string& right) {
    size_t pos = derivation.find(left);
    if (pos != string::npos) {
        derivation.replace(pos, left.length(), right);
    }
}

void leftmostDerivation(const vector<pair<string, string>>& grammar, const string& inputString) {
    string leftmost = "S";
    string rightmost = "S";
    
    vector<string> leftmostDerivations = {leftmost};
    vector<string> rightmostDerivations = {rightmost};
    
    while (leftmost != inputString) {
        for (const auto& production : grammar) {
            const string& left = production.first;
            const string& right = production.second;
            
            if (leftmost.find(left) == 0) {
                applyProduction(leftmost, left, right);
                leftmostDerivations.push_back(leftmost);
                break;
            }
        }
    }
    
    while (rightmost != inputString) {
        for (const auto& production : grammar) {
            const string& left = production.first;
            const string& right = production.second;
            
            size_t pos = rightmost.rfind(right);
            if (pos != string::npos && pos + right.length() == rightmost.length()) {
                rightmost.replace(pos, right.length(), left);
                rightmostDerivations.push_back(rightmost);
                break;
            }
        }
    }

    cout << "Input: " << inputString << endl;
    
    cout << "Leftmost Derivation:" << endl;
    for (size_t i = 0; i < leftmostDerivations.size(); ++i) {
        cout << "Step " << i + 1 << ": " << leftmostDerivations[i] << endl;
    }
    
    cout << "\nRightmost Derivation:" << endl;
    for (size_t i = 0; i < rightmostDerivations.size(); ++i) {
        cout << "Step " << i + 1 << ": " << rightmostDerivations[i] << endl;
    }
}

int main() {
    vector<pair<string, string>> cfg = {
        {"S", "A1B"},
        {"A", "0A"},
        {"A", ""},
        {"B", "0B"},
        {"B", "1B"},
        {"B", ""}
    };

    string inputString = "00101";
    
    leftmostDerivation(cfg, inputString);

    return 0;
}
