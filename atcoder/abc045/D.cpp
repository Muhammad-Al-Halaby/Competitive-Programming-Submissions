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

const int N = 55, M = 3e3, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int h, w, n;

bool valid(int i, int j){
    return i >= 1 && i <= h && j >= 1 && j <= w && i + 2 <= h && j + 2 <= w;
}

int main(){
    init();

    cin >> h >> w >> n;
    map<pii, int> mp;
    for(int i = 0;i < n;i++){
        int a, b;   cin >> a >> b;
        for(int i = -2;i <= 0;i++){
            for(int j = -2;j <= 0;j++){
                if(valid(a + i, b + j))
                    mp[{a + i, b + j}]++;
            }
        }
    }

    ll fr[10] = {0};
    for(auto p : mp){
        fr[p.S]++;
    }

    fr[0] = (ll)(h - 2) * (w - 2) - accumulate(fr, fr + 10, 0);

    for(int i = 0;i < 10;i++)
        cout << fr[i] << '\n';
}