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

const int N = 4e5 + 9, M = 5e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m, floors[N][2];

int solve(int i, int s){
    if(i == n - 1)  return (s == 0) * (floors[i][1]) + (s == 1) *  (m - 1 - floors[i][0]);

    int ret = OO;
    if(s == 0)
        ret = 2 * floors[i][1] + solve(i + 1, 0);
    else
        ret = 2 * (m - 1 - floors[i][0]) + solve(i + 1, 1);

    ret = min(ret, (m - 1) + solve(i + 1, !s));

    return ret + (ret != 0);
}

int main(){
    init();

    cin >> n >> m;
    m += 2;

    for(int i = 0;i < n;i++){
        char c;
        bool b, f = 1;

        int k = n - 1 - i;

        floors[k][0] = m - 1;
        for(int j = 0;j < m;j++){
            cin >> c;   b = c == '1';
            if(b && f)  floors[k][0] = j, f = 0;
            if(b)   floors[k][1] = j;
        }
    }

    int i = n - 1;
    while(i >= 0 && floors[i][0] == m - 1 && floors[i][1] == 0)i--, n--;

    int ans = (n > 0 ? solve(0, 0) : 0);
    cout << ans;
}