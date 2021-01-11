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

int n, a[10];

vector<ll> v;

ll solve(int i){
    if(i == n){
        ll sum = 0;
        for(int i = 0;i < v.size();i++) sum += v[i];
        return sum;
    }

    ll ret = 0;

    v.push_back(a[i]);
    ret = solve(i + 1);
    v.pop_back();

    if(!v.empty()){
        ll last = v.back();    v.pop_back();
        v.push_back(last * 10 + a[i]);
        ret += solve(i + 1);
        v.pop_back(); v.push_back(last);
    }

    return ret;
}

int main(){
    init();


    string s;   cin >> s;   n = s.size();
    for(int i = 0;i < n;i++) a[i] = s[i] - '0';
    cout << solve(0);
}