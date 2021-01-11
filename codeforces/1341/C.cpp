#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;

        int a[n], idx[n + 1], vis[n + 2] = {0};
        for(int i = 0;i < n;i++){
            int x;  cin >> x;
            a[i] = x;
            idx[x] = i;
        }

        vis[n] = 1;
        int turn = 1, ok = 1;
        for(int i = idx[turn];;i++){
            if(vis[i] == 1) break;
            vis[i] = 1;
            int cnt = 1;
            for(int j = i + 1;vis[j] == 0;j++, cnt++){
                if(a[j] != turn + cnt) ok = 0;
                vis[j] = 1;
            }
            if(ok == 0) break;
            turn = turn + cnt;
            if(turn == n + 1)   break;
            i = idx[turn] - 1;
        }

        if(turn == n + 1)   cout << "Yes\n";
        else cout << "No\n";

    }
}