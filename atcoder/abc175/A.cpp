#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 250, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

void go(int tc = 0){
    string s;   cin >> s;
    int cnt1 = (s[0] == 'R') || (s[1] == 'R') || (s[2] == 'R');
    int cnt2 = 2 * ((s[0] == 'R') && (s[1] == 'R'));
    int cnt3 = 2 * ((s[1] == 'R') && (s[2] == 'R'));
    int cnt4 = 3 * ((s[0] == 'R') && (s[1] == 'R') && (s[2] == 'R'));
    cout << max({cnt1, cnt2, cnt3, cnt4});
}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
//   cin >> t;
    while(t--)
        go(tc++);
}