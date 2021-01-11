#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

ll pow (ll b, ll e){
    if(e == 0)
        return 1;

    ll p = pow(b,e/2);

    p *= p;

    if(e % 2)
        p *= b;

    return p;
}

int row[50];
int col[50];

int main(){
    init();
    int n,m;
    ll ans = 0;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            bool x;
            cin >> x;
            if(x){
                row[i]++;
                col[j]++;
            }
        }
    }

    for(int i = 0;i<n;i++){
        ans += pow((ll)2,(ll)row[i]) - 1;
        ans += pow((ll)2,(ll)m-row[i]) - 1;
    }

    for(int i = 0;i<m;i++){
        ans += pow((ll)2,(ll)col[i]) - 1;
        ans += pow((ll)2,(ll)n-col[i]) - 1;
    }

    ans -= n * m;

    cout << ans;
}