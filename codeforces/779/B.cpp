#include <bits/stdc++.h>
using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    string n;
    int k,cnt=0;
    cin >> n >> k;
    for(int i = n.length()-1;i>=0;i--){
        if(n[i] == '0')k--;
        else cnt++;
        if(!k)break;
    }
    if(k > 0)
        cnt = n.length()-1;
    cout << cnt;
}