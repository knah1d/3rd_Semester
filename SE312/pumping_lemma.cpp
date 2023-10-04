#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define MAX 1000

using namespace std;

int a, m, b, n;
char expression[MAX];
char prefix[MAX], repeat[MAX], suffix[MAX];

bool isRegularExpression() {
    for (int k = 0; k < 200; k++) {
        int repeatLength = strlen(repeat);
        char newRepeat[MAX] = {0};
        for (int i = 0; i < k * repeatLength; i += repeatLength) {
            for (int j = 0; j < repeatLength; j++) {
                newRepeat[i] = repeat[j];
            }
        }
        newRepeat[k * repeatLength] = '\0';

        char newExpression[MAX] = {0};
        strcat(newExpression, prefix);
        strcat(newExpression, newRepeat);
        strcat(newExpression, suffix);

        int newN = 0, newM = 0;
        for (int i = 0; i < strlen(newExpression); i++) {
            if (newExpression[i] == a) newN++;
            else newM++;
        }

        if ((float)newN / newM != (float)n / m)
            return false;
    }
    return true;
}

void splitExpression() {
    int random = (int)rand() % (m - 1);
    for (int i = m - 1, j = 0; i > m - 1 - random; i--, j++) {
        repeat[j] = expression[i];
    }
    repeat[n] = '\0';

    for (int i = 0, j = 0; i <= m - 1 - random; i++, j++) {
        prefix[j] = expression[i];
    }
    prefix[n] = '\0';

    for (int i = m, j = 0; i < m + n; i++, j++) {
        suffix[j] = expression[i];
    }
    suffix[n] = '\0';

    if (isRegularExpression()) cout << "Yes, Regular expression" << endl;
    else cout << "No, it's not a regular expression" << endl;
}

int main() {
    cout << "Enter symbol 'a', count of 'a's 'm', symbol 'b', count of 'b's 'n': " << endl;
    cin >> a >> m >> b >> n;

    srand(time(NULL));

    for (int i = 0; i < m; i++) {
        expression[i] = (char)(a + 48);
    }
    for (int i = m; i < m + n; i++) {
        expression[i] = (char)(b + 48);
    }
    expression[m + n] = '\0';

    cout << "Expression: " << expression << endl;

    splitExpression();

    return 0;
}
