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

#define MAXNODES 200005

struct DSU
{
    int parent[MAXNODES];

    DSU()
    {
        for(int i = 0; i < MAXNODES; i++)
        {
            parent[i] = i;
        }
    }

    int findRoot(int i)
    {
        if(parent[i] == i)  return i;

        return parent[i] = findRoot(parent[i]);
    }

    void mergeGroups(int x, int y)
    {
        int root1 = findRoot(x);
        int root2 = findRoot(y);

        if(root1 == root2)  return;

        parent[root2] =  root1;
    }
};

int main(){
    init();
    int n, k, m;
    cin >> n >> k >> m;
    map<string, int> words;

    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        words[s] = i;
    }

    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    int cost[m];
    DSU dsu;
    for(int i = 0;i < k;i++){
        int x;
        cin >> x;
        int minCost = INT_MAX;
        for(int j = 0;j < x;j++){
            int a;
            cin >> a;
            a--;
            dsu.mergeGroups(i,a + 1e5);
            minCost = min(arr[a],minCost);
        }
        cost[i] = minCost;
    }

    ll ans = 0;
    for(int i = 0;i < m;i++){
        string s;
        cin >> s;
        int idx = words[s];
        ans += cost[dsu.findRoot(idx+1e5)];
    }
    cout << ans;
}