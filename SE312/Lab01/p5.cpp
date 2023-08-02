#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i, j, k, mid;
    char w[50];
    cin >> w;
    for (i = 0; i < w[i] != '\0'; i++)
        ;
    // cout<<i<<endl;
    if (i % 2 == 0)
        mid = i / 2;
    else
        mid = i / 2 + 1;

    for (j = i / 2 - 1, k = mid; w[k] != '\0'; j--, k++)
    {
        if (w[j] != w[k])
        {
            cout << "NOT palindrome...:(" << endl;
            return 0;
        }
    }
    cout << "PALINDROME...:)" << endl;
    return 0;
}