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

const int N = 109, M = 2e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, m, x;    cin >> n >> m >> x;

    int cost[n], c[n][m];
    for(int i = 0;i < n;i++){
        cin >> cost[i];
        for(int j = 0;j < m;j++)
            cin >> c[i][j];
    }


    int ans = OO;
    for(int i = 0;i < (1 << n);i++){
        int totalCost = 0, skills[m] = {0};
        for(int j = 0;j < n;j++){
            if(((i >> j) & 1) == 0)   continue;
            for(int k = 0;k < m;k++)    skills[k] += c[j][k];
            totalCost += cost[j];
        }

        int ok = 1;
        for(int k = 0;k < m;k++)    if(skills[k] < x)   ok = 0;

        if(ok)  ans = min(ans, totalCost);
    }

    cout << (ans == OO ? -1 : ans);

}