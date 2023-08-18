#include <bits/stdc++.h>
using namespace std;

// BU approach
int i, F[100];

int NSU(int n)
{
    
    for (i = 0; i < n; i++)
    {
        if (i <= 2)
            F[i] = i;
            
        else
            F[i] = F[i - 1] + F[i - 2] + F[i - 3];
        
    }
    return F[i-1];
}

int main()
{
    cout<<NSU(5);
}