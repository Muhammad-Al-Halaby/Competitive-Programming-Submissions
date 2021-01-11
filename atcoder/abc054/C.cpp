#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 10, M = 2e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int adjMat[N][N];

int main(){
    init();

    int n, m;   cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u, v;   cin >> u >> v;  --u, --v;
        adjMat[u][v] = adjMat[v][u] = 1;
    }


    int path[n - 1];
    for(int i = 0;i < n - 1;i++)    path[i] = i + 1;

    int ans = 0;
    do{
        int ok = 1;
        if(!adjMat[0][path[0]])  continue;
        for(int i = 0;i < n - 2;i++){
            int u = path[i];
            int v = path[i + 1];
            if(!adjMat[u][v])   ok = 0;
        }
        ans += ok;
    }while(next_permutation(path, path + n - 1));

    cout << ans;
}