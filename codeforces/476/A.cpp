#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, m;   cin >> n >> m;

    int ans = OO;
    for(int i = 0;i <= n;i++){
        if((n - i) % 2 == 0 && (i + (n - i) / 2) % m == 0)
            ans = min(ans, i + (n - i) / 2);
    }

    cout << (ans == OO ? -1 : ans);
}