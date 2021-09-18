#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int idx[26];

bool cmp(string a, string b){
    int mn = min(a.size(), b.size());
    for(int i = 0;i < mn;i++){
        int x = idx[a[i] - 'a'];
        int y = idx[b[i] - 'a'];
        if(x == y)  continue;
        else if(x < y)   return 1;
        else return 0;
    }
    if(a.size() < b.size())
        return 1;
    return 0;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string x; cin >> x;
    for(int i = 0;i < 26;i++)
        idx[x[i] - 'a'] = i;

    int n;  cin >> n;

    string a[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];

    sort(a, a + n, cmp);

    for(int i = 0;i < n;i++)
        cout << a[i] << '\n';
}