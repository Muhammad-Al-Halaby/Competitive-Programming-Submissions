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

const int N = 1e5 + 9, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n;  cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    multiset<int> s;
    int l = 0, r = 0, ans = 0;
    while(l <= r && r < n){
        s.insert(a[r]);
        int mn = *s.begin();
        int mx = *s.rbegin();
        while(mx - mn > 1){
            auto it = s.find(a[l]);
            s.erase(it);
            mn = *s.begin();
            mx = *s.rbegin();
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }

    cout << ans;
}