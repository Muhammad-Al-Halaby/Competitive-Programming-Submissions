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

const int N = 50, M = 500, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}

int fr[26];

int main(){
    init();
    string s, t;    cin >> s >> t;

    for(int i = 0;i < s.size();i++) fr[s[i] - 'a']++;
    for(int i = 0;i < t.size();i++){
        fr[t[i] - 'a']--;
        if(fr[t[i] - 'a'] == -1)   return cout << "need tree", 0;
    }

    int j = 0;
    for(int i = 0;i < s.size() && j < t.size();i++){
        if(s[i] == t[j])    j++;
    }

    if(j == t.size())   cout << "automaton";
    else if(s.size() != t.size())   cout << "both";
    else cout << "array";
}