#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int c[100][100];

int minEditDistance(const string &X, const string &Y, vector<string> &editSteps) {
    int m = X.size();
    int n = Y.size();
    c[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        c[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1];
            } else {
                c[i][j] = min({c[i - 1][j - 1], c[i][j - 1], c[i - 1][j]}) + 1;
            }
        }
    }

    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && X[i - 1] == Y[j - 1]) {
            editSteps.push_back("No operation: " + string(1, X[i - 1]));
            i--;
            j--;
        } else if (i > 0 && c[i][j] == c[i - 1][j] + 1) {
            editSteps.push_back("Delete: " + string(1, X[i - 1]));
            i--;
        } else if (j > 0 && c[i][j] == c[i][j - 1] + 1) {
            editSteps.push_back("Insert: " + string(1, Y[j - 1]));
            j--;
        } else {
            editSteps.push_back("Replace "+string(1, X[i - 1])+" with: "+ string(1, Y[j - 1]));
            i--;
            j--;
        }
    }

    reverse(editSteps.begin(), editSteps.end());

    return c[m][n];
}

int main() {
    string X, Y;
    X = "computer";
    Y = "complete";

    vector<string> editSteps;
    int editDistance = minEditDistance(X, Y, editSteps);
    cout << "Edit Distance between X and Y: " << editDistance << endl;

    cout << "Edit Steps:\n";
    for (auto step : editSteps) {
        cout << step << endl;
    }

    return 0;
}
