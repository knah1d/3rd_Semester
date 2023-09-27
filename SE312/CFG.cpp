#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void derivePalindrome(string s) {
    int n = s.length();
    int i = 0;

    while (i < n) {
        if (s[i] == '0') {
            cout << "P -> 0" << endl;
            i++;
        } else if (s[i] == '1') {
            cout << "P -> 1" << endl;
            i++;
        } else {
            cout << "Not in this grammar" << endl;
            return;
        }
    }

    if (isPalindrome(s)) {
        cout << "Derivation:" << endl;
        for (int i = 0; i < n / 2; i++) {
            cout << "P -> " << s[i] << "P" << s[i] << endl;
        }
        cout << "P => " << s << endl;
    } else {
        cout << "Not in this grammar" << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    derivePalindrome(input);

    return 0;
}
