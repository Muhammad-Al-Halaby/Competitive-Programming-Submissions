#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n,k,s;
    cin >> n >> k;
    for(int i = 1;i<=n-k;i++)cout << i << " ";
    s=k;
    for(int i = 1;i<=k;i++){
        cout << (n-k)+s << " ";
        if(!(i % 2))s=k-(i/2);
        else s=(i/2)+1;
    }
} 