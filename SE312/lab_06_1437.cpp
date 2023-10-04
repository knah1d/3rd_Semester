#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int numberOfState, numOfAlpha;
char states[3];
char alphabet[2];
string memo[4][4][3];



string regEx(int i, int j, int k){
    if( k==0 ){
        if(i==1 && j==1) return " e + 1 ";
        else if((i == 2 && j == 2) || (i==1 && j==3)) return " e ";
        else if(i==3 && j==3) return " e + 0 ";
        else if((i==1 && j==2) || (i==2 && j==3)) return " 0 ";
        else if((i==2 && j==1) || (i==3 && j ==1)) return " 1 ";
        else return " e ";
    }

    if(memo[i][j][k] != "-1") return memo[i][j][k]; //memoization

    memo[i][j][k] = (regEx(i, j, k-1) + " + (" + regEx(i, k, k-1) + ") (" + regEx(k, k, k-1) + ")*(" + regEx(k, j, k-1) + ")"); //recursion
    return memo[i][j][k];

}

int main()
{

    for(int k=0; k<3; k++) {
        for(int i=1; i<4; i++) {
            for(int j=1; j<4; j++) {
                memo[i][j][k] = "-1"; //memo
            }
        }
    }

    for(int k=0; k<3; k++){
        for(int i=1; i<4; i++){
            for(int j=1; j<4; j++){
                cout<<"R"<<i<<j<<"("<<k<<") = "<<regEx(i, j, k)<<endl;
            }
        }
    }

}
