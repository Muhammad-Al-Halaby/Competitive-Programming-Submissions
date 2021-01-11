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
int n, m, k;
vector<pair<int, int> > adj[MAX];

struct edge{
    int a;
    ll b;
    bool c;
    edge(int x, ll y, bool z){
        a = x;
        b = y;
        c = z;
    }

    bool operator <(const edge &A)const{
        if(A.b == b)
            return c > A.c;
        return b > A.b;
    }
};

ll costArr[MAX];
bool visited[MAX];
priority_queue<edge> pq;
int ans = 0;

void dijkstra(int s){
    for(int i = 1;i <= n;i++)
        costArr[i] = 1e18;
        
    pq.push(edge(s, 0, 0));
    costArr[s] = 0;
    
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        int v = e.a;
        ll cost = e.b;
        bool train = e.c;

        if(visited[v]){
            ans += train;
            continue;
        }

        visited[v] = 1;

        //update cost to v by train route
        if(train)costArr[v] = cost;

        for(int i = 0;i < adj[v].size();i++){
                int u = adj[v][i].F;
                ll oldCost = costArr[u];
                ll newCost = cost + adj[v][i].S;
                if(newCost < oldCost){
                    costArr[u] = newCost;
                    pq.push(edge(u, newCost, 0));
            }
        }
    }
}


int main(){
    init();

    cin >> n >> m >> k;

    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].PB(MP(b,c));
        swap(a,b);
        adj[a].PB(MP(b,c));
    }
    
    for(int i = 0;i < k;i++){
        int b, c;
        cin >> b >> c;
        pq.push(edge(b,c,1));
    }
    
    dijkstra(1);
    
    cout << ans;
}
