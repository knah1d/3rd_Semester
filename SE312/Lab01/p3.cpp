#include<bits/stdc++.h>

using namespace std;

int main() {
    
    //string x, y, z;
    char x[10];
    char y[10];
    char z[50];
    int i;
    cin>>x>>y;
    for (i = 0; x[i]!='\0'; i++) {
        z[i] = x[i];
    }
    for (int j = 0; y[j]!='\0'; j++, i++) { 
        z[i] = y[j];
    }
        z[i] = '\0';
        
        cout<<z<<endl;    

}