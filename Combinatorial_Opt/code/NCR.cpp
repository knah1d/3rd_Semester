#include<bits/stdc++.h>
using namespace std;

int memo[100][100];

int ncr(int n, int r) {
    if(r>n) {
        cout<< "Math Error" <<endl;
            exit(0);
    }
    if(memo[n][r]!=-1) return memo[n][r];
    if(r==1) return memo[n][r] = n;
    if(r==n||r==0) return memo[n][r] = 1;
    else return memo[n][r] = ncr(n-1, r-1)+ncr(n-1, r);
}

int main() {
    memset(memo, -1, sizeof(memo));
    cout<<ncr(5, 2);
}