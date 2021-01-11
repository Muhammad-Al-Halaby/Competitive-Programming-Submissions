#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
int n, m, colors[100005];
set<int> cardinality[100005];

int main(){
    init();
    cin >> n >> m;
    set<int> c;
    for(int i = 1;i <= n;i++){
        cin >> colors[i];
        c.insert(colors[i]);
    }
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        if(colors[u] == colors[v])continue;
        cardinality[colors[u]].insert(colors[v]);
        cardinality[colors[v]].insert(colors[u]);
    }

    int mx = 0;
    for(auto color : c)
        mx = max(mx, (int)cardinality[color].size());

    for(auto color : c){
        if(cardinality[color].size() == mx){
            return cout << color, 0;
        }
    }
}