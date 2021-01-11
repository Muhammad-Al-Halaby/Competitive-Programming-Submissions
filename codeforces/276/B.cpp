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

const int N = 109, M = 15, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    string s;   cin >> s;
    int n = s.size();
    int fr[26] = {0};
    for(int i = 0;i < n;i++){
        fr[s[i] - 'a']++;
    }

    int o = 0;
    for(int i = 0;i < 26;i++)
        o += fr[i] & 1;

    if(o <= 1)  cout << "First";
    else cout << (n & 1 ? "First" : "Second");
}