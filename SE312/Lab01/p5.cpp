#include<bits/stdc++.h>
using namespace std;

int main() {

    int i, j, k;
    char w[50], x[50], y[50];
    cin>>w;

    for(i = 0; w[i]!='\0'; i++); //length
    if(i%2==0) {
        for(j = 0; j<i/2; j++) {
            x[j] = w[j];
        }
        x[j] = '\0';

        for(j = i/2, k = 0; w[j]!='\0'; j++, k++) {
            y[k] = w[j];
        }
        y[k] = '\0';

        //cout<<x<<endl<<y;
    }
    else {
        for(j = 0; j<i/2; j++) {
            x[j] = w[j];
        }
        x[j] = '\0';

        for(j = (i/2)+1, k = 0; w[j]!='\0'; j++, k++) {
            y[k] = w[j];
        }
        y[k] = '\0';
        //cout<<x<<endl<<y<<endl;
    }
    
    
    for(j = 0, k = (i/2)-1; x[j]!='\0'; j++, k--) {
        if(x[j]!=y[k]) {
            cout<<"NOT palindrome...:("<<endl;
            return 0;
        }
    }
    cout<<"PALINDROME...:)"<<endl;
    return 0;
}