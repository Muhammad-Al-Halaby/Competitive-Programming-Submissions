#include <bits/stdc++.h>

using namespace std;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main(){
    init();
    int n,ans=0,player=0,next = 1,mx = 0,wins=0;
    long long k;
    cin >> n >> k;
    int powers[n];
    for(int i = 0;i<n;i++) cin >> powers[i], mx = max(powers[i],mx);

    while(powers[player] != mx){
        if(powers[player] > powers[next])next++,wins++;
        else player = next, next++,wins = 1;

        if(wins == k)break;
    }
    cout << powers[player];
}