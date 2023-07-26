#include<bits/stdc++.h>
using namespace std;

char rndm[5][10];

int main(){
    int size;
    for(int i=0; i<5; i++){
        size = (int)(rand()%10);
        for(int j=0; j<size; j++){
            rndm[i][j] = (char)((int)(rand()%2)+48);
        }
    }
    for(int i=0; i<5; i++){
        cout<<rndm[i]<<endl;
    }
    int length[5];
    for(int i=0; i<5; i++){
        length[i] = 0;
        for(int j=0; rndm[i][j] != '\0'; j++){
            length[i]++;
        }
    }
    for(int i=0; i<5; i++){
        cout<<length[i]<<endl;
    }

}
