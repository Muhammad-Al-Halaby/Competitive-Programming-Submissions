#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 5e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

struct Adj {
    int n, ne, head[N], nxt[M], to[M], cost[M];

    void initGraph(int n) {
        memset(head, -1, (n + 1) * sizeof head[0]);
        ne = 0;
        this->n = n;
    }

    void addEdge(int f, int t, int c = 0) {
        to[ne] = t;
        cost[ne] = c;
        nxt[ne] = head[f];
        head[f] = ne++;
    }

    void addBiEdge(int u, int v, int c = 0) {
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
} adj;


vector<int> cmps;
int vis[N], vid;
void dfs(int u){
    if(vis[u] == vid)   return;

    vis[u] = vid;

    cmps.push_back(u);

    neig(adj, u,e, v){
        dfs(v);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);


    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        string t;
        cin >> s >> t;

        adj.initGraph(n);
        vid++;

        int freq[26] = {0};
        for(int i = 0;i < n;i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        int ans = 1;
        for(int i = 0;i < 26;i++)
            ans &= (freq[i] == 0);

        int f = -1;
        for(int i = 0;i < n;i++){
            if(i + k < n){
                adj.addBiEdge(i, i + k);
            }
            else{
                f = i;
                break;
            }
            if(i + k + 1 < n){
                adj.addBiEdge(i, i + k + 1);
            }
        }

        for(int i = 0;i < n;i++){
            if(vis[i] == vid)   continue;
            cmps.clear();
            dfs(i);

            string s1 = "";
            string s2 = "";
            for(auto idx : cmps){
                s1 += s[idx];
                s2 += t[idx];
            }

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            if(s1 != s2){
                ans = 0;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';


    }

}