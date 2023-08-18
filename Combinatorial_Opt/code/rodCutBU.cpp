#include<bits/stdc++.h>
using namespace std;

int rod(int price[], int length) {

    int rev[length], j, i;
    rev[0] = 0;
    for(j=1; j<=length; j++) {
        int q = -1;    
        for(i=1; i<=j; i++) {
            q = max(q, price[i-1]+rev[j-i]);
            cout<<q<<endl;          
        }
        rev[j] = q;
    }
    return rev[length];
}


int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout<<rod(price, 4);
}