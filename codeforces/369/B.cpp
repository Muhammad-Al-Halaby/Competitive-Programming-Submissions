#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e3 + 9, M = 12, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int n, k, l, r, sa, sk; cin >> n >> k >> l >> r >> sa >> sk;
    int rm = sk % k;
    for(int i = 0;i < k;i++){
        cout << (sk / k) + (rm > 0) << " ";
        rm--;
    }

    sa -= sk;
    if(!sa) return 0;
    int q = sa / (n - k);
    rm = sa % (n - k);
    for(int i = k;i < n;i++){
        cout << q + (rm > 0) << " ";
        rm--;
    }

}