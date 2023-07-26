#include<bits/stdc++.h>

using namespace std;

int main() {
    char ch[20];
    cin>>ch;
    for(int i = 0; ch[i]!='\0'; i++) {
        if(ch[i]!='0' && ch[i]!='1') {
            cout<<"Not from the Alphabet...:("<<endl;
            return 0;
        }
        
    }
    cout<<"From the Alphabet...:)"<<endl;

    return 0;
}