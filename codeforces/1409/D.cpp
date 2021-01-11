#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 509, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void go(int tc = 0){
    ll nn, s;   cin >> nn >> s;
    string n = to_string(nn);
    while(n.size() < 20)    n = '0' + n;

    int prefix[n.size()] = {0};
    for(int i = 1;i < n.size();i++){
        prefix[i] = n[i] - '0' + prefix[i - 1];
    }

    if(prefix[n.size() - 1] <= s)   return cout << 0 << '\n', void();

    for(int i = n.size() - 1, suff = 0;i >= 0;i--, suff++){
        for(int j = (n[i] - '0') + 1;j <= 9;j++){
            int sum = prefix[i - 1] + j;
            if(sum <= s){

                string ans = n.substr(0, i);
                ans += j + '0';
                for(int k = 0;k < suff;k++) ans += '0';

                cout << stoll(ans) - nn << '\n';
                return;
            }
        }
    }
}

int main()
{
    init();

//    freopen("knights.in", "r", stdin);

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
    cin >> t;
    while(t--)
        go(tc++);
}