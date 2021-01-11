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

const int N = 3e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int t[4 * N], a[N], b[N];

void update(int v, int s, int e, int i, int val){
    if(s == e)
        return  t[v] = val, void();

    int mid = (s + e) >> 1;

    if(i <= mid)
        update(v * 2, s, mid, i, val);
    else
        update(v * 2 + 1, mid + 1, e, i, val);

    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int minQuery(int v, int s, int e, int l, int r){
    if(r < s || l > e)  return OO;

    if(s >= l && e <= r)    return t[v];

    int mid = (s + e) >> 1;

    return min({minQuery(v * 2, s, mid, l, r), minQuery(v * 2 + 1, mid + 1, e, l, r)});
}

int n;
vector<int> nxtIdx[N];

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        cin >> n;

        for(int i = 0;i < n;i++)    nxtIdx[i].clear();

        for(int i = 0;i < n;i++)    cin >> a[i], a[i]--, nxtIdx[a[i]].push_back(i);

        for(int i = 0;i < n;i++)    cin >> b[i], b[i]--;

        for(int i = 0;i < n;i++){
            reverse(nxtIdx[i].begin(), nxtIdx[i].end());
            update(1, 0, n - 1, i, nxtIdx[i].empty() ? OO : nxtIdx[i].back());
        }

        int ok = 1;
        for(int i = 0;i < n;i++){
            int nxt = b[i];

            if(nxtIdx[nxt].empty()){
                ok = 0;
                break;
            }

            if(minQuery(1, 0, n - 1, 0, nxt) != nxtIdx[nxt].back()){
                ok = 0;
                break;
            }

            if(!nxtIdx[nxt].empty())  nxtIdx[nxt].pop_back();
            update(1, 0, n - 1, nxt, nxtIdx[nxt].empty() ? OO : nxtIdx[nxt].back());
        }

        if(ok)  cout << "YES\n";
        else cout << "NO\n";
    }
}