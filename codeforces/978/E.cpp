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

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, w;   cin >> n >> w;

    int a[n];
    for(int i = 0;i < n;i++)    cin >> a[i];

    auto check = [&](int x){
        for(int i = 0;i < n;i++){
            x += a[i];
            if(x < 0)   return -1;
            if(x > w)   return 0;
        }
        return 1;
    };

    int l = 0, r = OO;
    while(l <= r){
        int mid = (l + r) >> 1;

        if(check(mid) == -1) l = mid + 1;
        else r = mid - 1;
    }

    int mn = l;

    l = 0, r = OO;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid) == 0)  r = mid - 1;
        else l = mid + 1;
    }

    int mx = min(r, w);

    if(check(mn) != 1 || check(mx) != 1 || mn > mx)   return cout << 0, 0;

    cout << (mx - mn + 1);
}