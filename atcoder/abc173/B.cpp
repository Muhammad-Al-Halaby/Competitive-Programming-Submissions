#include <bits/stdc++.h>

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

const int N = 1e5, M = 109, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc){

    int t;  cin >> t;

    map<string, int> mp;
    while(t--){
        string s;   cin >> s;
        mp[s]++;
    }

    cout << "AC x " << mp["AC"] << '\n';
    cout << "WA x " << mp["WA"] << '\n';
    cout << "TLE x " << mp["TLE"] << '\n';
    cout << "RE x " << mp["RE"] << '\n';

}

int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    int t = 1, tc = 1;
//    cin >> t;
    while(t--)  go(tc++);
}