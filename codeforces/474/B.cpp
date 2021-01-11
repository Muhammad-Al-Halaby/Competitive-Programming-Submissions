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

    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(i)   a[i] += a[i - 1];
    }

    int m;  cin >> m;
    for(int i = 0;i < m;i++){
        int q;  cin >> q;
        int idx = lower_bound(a, a + n, q) - a;
        cout << idx + 1 << '\n';
    }
}