#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define modulo ll (1e9 + 7)

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;

const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);


    int  t; cin >> t;
    while(t--){
        int n, m, a, b; cin >> n >> m >> a >> b;

        ll s[m];
        for(int i = 0;i < m;i++)
            cin >> s[i];

        sort(s, s + m);

        ll diff = abs(a - b);

        ll firecrackers = diff - 1;


        ll end;
        if(b > a)
            end = a - 1;
        else
            end = n - a;

        ll endTime = (diff - 1) + end + 1;

        auto check = [&](ll cnt){
            ll time = 1;
            for(int i = cnt - 1;time <= diff - 1 && i >= 0;i--){
                if(time + s[i] > endTime)
                    return false;
                time++;
            }
            return cnt <= diff - 1;
        };

        ll l = 0, r = m;
        while(l <= r){
            ll mid = (l + r) >> 1;
            if(check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }

        cout << r << '\n';
    }
}