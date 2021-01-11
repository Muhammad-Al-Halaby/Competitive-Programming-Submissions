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

const int N = 1e4 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, k, x;    cin >> n >> k >> x;
    ll a[n], b[n], bits[64] = {0}, oremall = 0;
    
    for(int i = 0;i < n;i++){
        cin >> a[i];
        
        b[i] = a[i];
        
        oremall |= a[i];
        
        for(int j = 0;j < 50;j++)   bits[j] += (a[i] >> j) & 1;
        
        for(int j = 0;j < k;j++)    b[i] *= x;
    }

    ll ans = oremall;
    for(int i = 0;i < n;i++){
        ll localAns = oremall;
        
        for(int j = 0;j < 50;j++)
            if((a[i] >> j) & 1){
                if(bits[j] == 1)    localAns ^= (1ll << j);
            }
        
        localAns |= b[i];
        
        ans = max(ans, localAns);
    }

    cout << ans;
}
