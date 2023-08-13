#include <bits/stdc++.h>
using namespace std;

int mem[100];
int Max[100];
int rodCut(int price[], int length)
{

    if (length < 1)
        return 0;

    if (mem[length] != -1)
    {
        //cout<<"used"<<endl;
        return mem[length];
    }
    int maxPrice = -1;
    int count = 0;
    for (int i = 1; i <= length; i++)
    {
        // cout<<price[i-1]<<" "<< rodCut(price, length-i)<<endl;
        maxPrice = max(maxPrice, price[i - 1] + rodCut(price, length - i));
        Max[i-1] = maxPrice;
    }

    mem[length] = maxPrice;
    return maxPrice;
}

int main()
{

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int length = 9;
    fill(mem, mem + 100, -1);
    cout << "Maximum Revenue for the length " << length << " is: " << rodCut(price, length) << endl;
    int min = 0, i, k;
    for(i = 0; i<length; i++) {
        if(min<Max[i]) {
        min = Max[i];
        k = i;
        }
    }
    cout<<"Price of length "<<k+1<<"="<<price[k]<<" + "<<"Price of length "<<length-k-1<<"="<<price[length-k-2]<<endl;
}