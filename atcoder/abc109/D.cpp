#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 509, M = 1e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N][N];
vector<pair<pii, pii>> op;

int main(){
//    init();

    scanf("%d%d", &n, &m);

    vector<pii> odd;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            scanf("%d", a[i] + j);


    for(int i = 0;i < n;i++){
        for(int j = 0;j < m - 1;j++){
            if(a[i][j] % 2 == 0)    continue;
            op.push_back({{i, j}, {i, j + 1}});
            a[i][j + 1]++;
        }
    }

    for(int i = 0;i < n - 1;i++){
        if(a[i][m - 1] % 2 == 0)    continue;
        op.push_back({{i, m - 1}, {i + 1, m - 1}});
        a[i + 1][m - 1]++;
    }

    printf("%d\n", op.size());
    for(auto &v : op){
        printf("%d %d %d %d\n", v.F.F + 1, v.F.S + 1, v.S.F + 1, v.S.S + 1);
    }
}