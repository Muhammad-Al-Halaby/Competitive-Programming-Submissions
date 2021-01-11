#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int a[N], vis[N];

int main(){
    init();

    ll n, k;    cin >> n >> k;

    for(int i = 1;i <= n;i++)    cin >> a[i];

    memset(vis, -1, sizeof vis);

    int vid = 0, cycle = -1, mod;
    for(int i = 1;;i = a[i]){
        if(vid == k)  return cout << i, 0;

        if(cycle == -1 && vis[i] != -1){
            cycle = vid - vis[i];
            k -= vid;
            vid = 0;
        }

        if(~cycle && vid % cycle == k % cycle)
            return cout << i, 0;

        vis[i] = vid++;
    }

}