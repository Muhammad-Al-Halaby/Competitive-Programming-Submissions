#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;

        auto compare = [](pii a, pii b){
            if(abs(a.F - a.S) != abs(b.F - b.S))
                return abs(a.F - a.S) < abs(b.F - b.S);
            return a.F > b.F;
        };

        priority_queue<pii, vector<pii>, decltype(compare)> q(compare);

        int a[n + 1] = {0};
        q.push({1, n});

        int ac = 1;
        while(q.size()){
            pii p = q.top();    q.pop();
            if((p.S - p.F + 1) & 1){
                int t = (p.S + p.F) / 2;
                if(a[t] == 0)   a[t] = ac++;
                if(p.F != p.S){
                    if(p.F <= t - 1)q.push({p.F, t - 1});
                    if(t + 1 <= n)q.push({t + 1, p.S});
                }
            }
            else{
                int t = (p.S + p.F - 1) / 2;
                if(a[t] == 0)   a[t] = ac++;
                if(p.F != p.S){
                    if(p.F <= t - 1)q.push({p.F, t - 1});
                    if(t + 1 <= n) q.push({t + 1, p.S});
                }
            }
        }

        for(int i = 1;i <= n;i++)   cout << a[i] << " ";
        cout << '\n';

    }
}