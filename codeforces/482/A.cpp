#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    int n,k,base=0,sm=1,tmp=0,ans=0;
    cin >> n >> k;
    for(int i = 1;i<=(n-k);i++)cout << i << ' ';
    base = n-k;
    tmp = k;
    for(int i = 1;i<=tmp;i++){
        cout << base + k * sm << ' ';
        base = base + k * sm;
        sm*=-1;
        k--;
    }
}