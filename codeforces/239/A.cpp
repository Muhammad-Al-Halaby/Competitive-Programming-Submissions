#include<bits/stdc++.h>

using namespace std;

int main(){
    int y,k,n,flag=0;
    cin >> y >> k >> n;
    for(int i = k;i <= n;i+=k){
        if(i > y){
            cout << i-y << " ";
            flag = 1;
        }
    }
    if(!flag)
        cout << -1;
}