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
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int visited[MAX];
bool cat[MAX];
int n, m;

int dfs(int v, int cats_so_far){
    if(cats_so_far > m)return 0;

    if(v != 1 && adj[v].size() == 1)return 1;

    visited[v] = 1;
    int res = 0;
    for(int i = 0;i < adj[v].size();i++){
        if(!visited[adj[v][i]]){
            if(cat[adj[v][i]])
                res += dfs(adj[v][i], cats_so_far + cat[adj[v][i]]);
            else
                res += dfs(adj[v][i], 0);
        }
    }

    return res;
}

int main(){
    init();
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> cat[i];

    for(int i = 1;i < n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1, cat[1]);
}