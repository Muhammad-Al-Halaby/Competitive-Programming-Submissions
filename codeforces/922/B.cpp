#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifdef OnlineJudge
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int main(){
    init();

    int n,ans=0;
    cin >> n;

    for(int i = 1;i <= n;i++)
        for(int j = i;j <= n;j++){
            int k = i ^ j;
            if(i + j > k && k >= j && k <= n)
                ans++;
        }

    cout << ans;
}