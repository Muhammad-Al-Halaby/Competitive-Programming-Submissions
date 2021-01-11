#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int op[(int)1e5+2];
ll add[(int)1e5+2];

int main(){
    init();
    int n,m,k;
    cin >> n >> m >> k;
    ll arr[n+2];
    arr[0] = 0;
    int l[m], r[m];
    ll d[m];
    for(int i = 1;i<=n;i++)
        cin >> arr[i];
    for(int i = 0;i < m;i++)
        cin >> l[i] >> r[i] >> d[i];
    for(int i = 0;i<k;i++){
        int x,y;
        cin >> x >> y;
        op[x]++;
        op[y+1]--;
    }
    partial_sum(op,op+(m+2), op);
    for(int i = 0;i < m;i++){
        d[i] *= op[i+1];
        add[l[i]] += d[i];
        add[r[i]+1] -= d[i];
    }
    partial_sum(add,add+(n+2), add);

    for(int i = 1; i <= n;i++)arr[i] += add[i];

    for(int i = 1;i <= n;i++)
        cout << arr[i] << " ";
}