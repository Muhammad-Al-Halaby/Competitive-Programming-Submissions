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

    int n,a,b;
    cin >> n >> a >> b;

    int ans = 1, last = max(a,b);

    for(int i = 0;i<n-1;i++){
        cin >> a >> b;

        if(max(a,b) <= last) last = max(a,b);
        else if(min(a,b) <= last ) last = min(a,b);
        else ans = 0;
    }

    if(ans)
        cout << "YES";
    else
        cout << "NO";
}